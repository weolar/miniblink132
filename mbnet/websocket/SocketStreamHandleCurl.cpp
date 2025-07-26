/*
 * Copyright (C) 2009 Brent Fulgham.  All rights reserved.
 * Copyright (C) 2009 Google Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "mbnet/websocket/SocketStreamHandle.h"

#include "mbnet/websocket/SocketStreamHandleClient.h"
#include "mbnet/websocket/SocketStreamError.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include "third_party/blink/renderer/platform/wtf/wtf.h"
#include "content/common/LiveIdDetect.h"
#include "content/common/ThreadCall.h"
#include <process.h>
#include <netlistmgr.h>

extern "C" long MB_InterlockedDecrement(long volatile* _Target);
extern "C" long MB_InterlockedIncrement(long volatile* _Target);
extern "C" long MB_InterlockedExchange(long volatile* _Target, long _Value);

namespace mbnet {

SocketStreamHandle::SocketStreamHandle(const blink::KURL& url, SocketStreamHandleClient* client)
    : SocketStreamHandleBase(url, client)
    , m_workerThread(0)
    , m_stopThread(0)
    , m_readDataTaskCount(0)
{
    m_id = common::LiveIdDetect::get()->constructed(this);
    //WTF_LOG(Network, "SocketStreamHandle %p new client %p", this, m_client);
    DCHECK(WTF::IsMainThread());
}

SocketStreamHandle::~SocketStreamHandle()
{
    //WTF_LOG(Network, "SocketStreamHandle %p delete", this);
    DCHECK(!m_workerThread);
    common::LiveIdDetect::get()->deconstructed(m_id);
}

int SocketStreamHandle::platformSend(const char* data, int length)
{
    //WTF_LOG(Network, "SocketStreamHandle %p platformSend", this);

    DCHECK(WTF::IsMainThread());

    startThread();

    char* copy = createCopy(data, length);

    WTF::Locker<WTF::RecursiveMutex> lock(m_mutexSend);
    m_sendData.push_back((new SocketData(copy, length)));

    return length;
}

void SocketStreamHandle::platformClose()
{
    //WTF_LOG(Network, "SocketStreamHandle %p platformClose", this);

    DCHECK(WTF::IsMainThread());

    stopThread();

    if (m_client && common::LiveIdDetect::get()->getPtr((intptr_t)m_clientId))
        m_client->didCloseSocketStream(this);
}

// static void mainThreadReadData(void* param)
// {
//     SocketStreamHandle* hanlde = (SocketStreamHandle*)param;
//     hanlde->mainThreadReadData();
// }
//
// static void mainThreadFail(void* param)
// {
//     SocketStreamHandle* hanlde = (SocketStreamHandle*)param;
//     hanlde->mainThreadFail();
// }

void SocketStreamHandle::mainThreadFail()
{
    stopThread();
    SocketStreamError err(-2);
    if (m_client && common::LiveIdDetect::get()->getPtr((intptr_t)m_clientId))
        m_client->didFailSocketStream(this, err);
    Release();
}

void SocketStreamHandle::mainThreadReadData()
{
    MB_InterlockedDecrement((long volatile*)(&m_readDataTaskCount));
    didReceiveData();
    Release();
}

bool SocketStreamHandle::readData(CURL* curlHandle)
{
    DCHECK(!WTF::IsMainThread());

    const int bufferSize = 1024 * 30;
    char* data = new char[bufferSize];
    size_t bytesRead = 0;

    CURLcode ret = curl_easy_recv(curlHandle, data, bufferSize, &bytesRead);
    DCHECK(bytesRead <= bufferSize);

    if (ret == CURLE_OK /*&& bytesRead >= 0*/) {
        m_mutexReceive.lock();
        m_receiveData.push_back((new SocketData(data, static_cast<int>(bytesRead))));
        m_mutexReceive.unlock();

        AddRef();

        if (0 == m_readDataTaskCount) {
            MB_InterlockedIncrement((long volatile*)(&m_readDataTaskCount));
            int64_t id = m_id;
            content::ThreadCall::callBlinkThreadAsync(FROM_HERE, [id] {
                SocketStreamHandle* self = (SocketStreamHandle*)common::LiveIdDetect::get()->getPtr((intptr_t)id);
                if (self)
                    self->mainThreadReadData();
            });
        }
        return true;
    }

    delete[] data;

    if (ret == CURLE_RECV_ERROR)
        return false;

    if (ret == CURLE_AGAIN)
        return true;

    return false;
}

bool SocketStreamHandle::sendData(CURL* curlHandle)
{
    DCHECK(!WTF::IsMainThread());

    while (true) {
        m_mutexSend.lock();
        if (!m_sendData.size()) {
            m_mutexSend.unlock();
            break;
        }
        std::unique_ptr<SocketData> sendData = std::unique_ptr<SocketData>(m_sendData.TakeFirst());
        m_mutexSend.unlock();

        int totalBytesSent = 0;
        while (totalBytesSent < sendData->size) {
            size_t bytesSent = 0;
            CURLcode ret = curl_easy_send(curlHandle, sendData->data + totalBytesSent, sendData->size - totalBytesSent, &bytesSent);

            if (ret == CURLE_OK)
                totalBytesSent += bytesSent;
            else
                break;
        }

        // Insert remaining data into send queue.

        if (totalBytesSent < sendData->size) {
            const int restLength = sendData->size - totalBytesSent;
            char* copy = createCopy(sendData->data + totalBytesSent, restLength);

            WTF::Locker<WTF::RecursiveMutex> lock(m_mutexSend);
            m_sendData.push_front((new SocketData(copy, restLength)));

            return false;
        }
    }

    return true;
}

// in microseconds
int SocketStreamHandle::waitForAvailableData(CURL* curlHandle, long long selectTimeout)
{
    DCHECK(!WTF::IsMainThread());

    long long usec = selectTimeout * 1000;

    struct timeval timeout;
    if (usec <= (0)) {
        timeout.tv_sec = 0;
        timeout.tv_usec = 0;
    } else {
        timeout.tv_sec = usec / 1000000;
        timeout.tv_usec = usec % 1000000;
    }

    long socket;
    CURLcode err = curl_easy_getinfo(curlHandle, CURLINFO_LASTSOCKET, &socket);
    if (err != CURLE_OK) {
        char* output = (char*)malloc(0x100);
        sprintf(output, "SocketStreamHandle::waitForAvailableData fail 1: %d\n", err);
        OutputDebugStringA(output);
        free(output);

        return -1;
    }

    ::Sleep(50);

    fd_set fdread;
    FD_ZERO(&fdread);
    FD_SET(socket, &fdread);
    int rc = ::select(0, &fdread, nullptr, nullptr, &timeout);

    if (rc != 1 && rc != 0) {
        char* output = (char*)malloc(0x100);
        sprintf(output, "SocketStreamHandle::waitForAvailableData fail 2: %d\n", err);
        OutputDebugStringA(output);
        free(output);
        return -1;
    }
    return rc == 1 ? 1 : 0;
}

static unsigned __stdcall webSocketThread(void* param)
{
    //base::SetThreadName("WebSocketThread");
    SocketStreamHandle* invocation = (static_cast<SocketStreamHandle*>(param));
    invocation->threadFunction();
    return 0;
}

static void s_mainThreadRun(void* param)
{
    SocketStreamHandle* hanlde = (SocketStreamHandle*)param;
    hanlde->mainThreadRun();
}

void SocketStreamHandle::mainThreadRun()
{
    // Check reference count to fix a crash.
    // When the call is invoked on the main thread after all other references are released, the SocketStreamClient
    // is already deleted. Accessing the SocketStreamClient in didOpenSocket() will then cause a crash.
    if (/*refCount() > 1*/ HasAtLeastOneRef() && !HasOneRef())
        didOpenSocket();
    Release();
}

#if defined(OS_WIN)
int checkIsNetwork(INetworkListManager* pNetworkListManager)
{
    static DWORD s_lastCheck = 0;
    DWORD lastCheck = ::GetTickCount();
    if (lastCheck - s_lastCheck < 15000)
        return -1;
    s_lastCheck = lastCheck;

    if (!pNetworkListManager)
        return -1;

    HRESULT hresult = E_FAIL;
    int isOnline = 0;
    VARIANT_BOOL isConnect = VARIANT_FALSE;
    if (pNetworkListManager)
        hresult = pNetworkListManager->get_IsConnectedToInternet(&isConnect);
    if (SUCCEEDED(hresult))
        isOnline = (isConnect == VARIANT_TRUE) ? 1 : 0;

    return isOnline;
}

INetworkListManager* getNetworkList(IUnknown** ppUnknown)
{
    const GUID CLSID_NetworkListManagerXp = { 0xdcb00c01, 0x570f, 0x4a9b, { 0x8d, 0x69, 0x19, 0x9f, 0xdb, 0xa5, 0x72, 0x3b } };
    const IID IID_INetworkListManagerXp = { 0xdcb00000, 0x570f, 0x4a9b, { 0x8d, 0x69, 0x19, 0x9f, 0xdb, 0xa5, 0x72, 0x3b } };

    BOOL bOnline = TRUE;
    HRESULT hresult = CoCreateInstance(CLSID_NetworkListManagerXp, NULL, CLSCTX_ALL, IID_IUnknown, (void**)ppUnknown);
    if (!(SUCCEEDED(hresult)))
        return nullptr;

    INetworkListManager* pNetworkListManager = NULL;
    if (*ppUnknown)
        hresult = (*ppUnknown)->QueryInterface(IID_INetworkListManagerXp, (void**)&pNetworkListManager);

    if (SUCCEEDED(hresult))
        return pNetworkListManager;

    return nullptr;
}
#endif

// void PrintfLog(const char* format, int size, ...)
// {
//   va_list args;
//   va_start(args, size);
//
//   char* buf = new char[size];
//   int len = vsnprintf(buf, size - 1, format, args);
//   va_end(args);
//
//   if (len > 0 && len < size - 1) {
//     OutputDebugStringA(buf);
//   }
//   delete[] buf;
// }
//
// static void process_and_print_addr(const curl_sockaddr* addr)
// {
//   if (!addr)
//     return;
//
//   switch (addr->family) {
//   case AF_INET:
//   {
//     sockaddr_in* addr_in = (sockaddr_in*)(&(addr->addr));
//     char ip_str[INET_ADDRSTRLEN];
//     inet_ntop(AF_INET, &(addr_in->sin_addr), ip_str, INET_ADDRSTRLEN);
//     PrintfLog("IPv4 Address: %s\n", 100, ip_str);
//     PrintfLog("Port: %d\n", 100, ntohs(addr_in->sin_port));
//     break;
//   }
//   case AF_INET6:
//   {
//     //     struct sockaddr_in6* addr_in6 = (struct sockaddr_in6*)addr;
//     //     char ip_str[INET6_ADDRSTRLEN];
//     //     inet_ntop(AF_INET6, &(addr_in6->sin6_addr), ip_str, INET6_ADDRSTRLEN);
//     //     printf("IPv6 Address: %s\n", ip_str);
//     //     printf("Port: %d\n", ntohs(addr_in6->sin6_port));
//     break;
//   }
//   default:
//     //printf("Unsupported address family\n");
//     break;
//   }
// }
//
// static curl_socket_t __cdecl OnOpensocket(void* clientp, curlsocktype purpose, struct curl_sockaddr* address) {
//   process_and_print_addr(address);
//   return socket(address->family, address->socktype, address->protocol);
// }

void SocketStreamHandle::threadFunction()
{
    DCHECK(!WTF::IsMainThread());

    CURL* curlHandle = curl_easy_init();

    if (!curlHandle)
        return;

    String url = m_url.Host().ToString();
    unsigned short port = m_url.Port();
    bool isSSL = !m_url.ProtocolIs("ws");
    if (0 == port)
        port = isSSL ? 443 : 80;

    if (isSSL)
        url = "https://" + url;

    //curl_easy_setopt(curlHandle, CURLOPT_URL, m_url.host().utf8().data());
    curl_easy_setopt(curlHandle, CURLOPT_URL, url.Utf8().data());

    curl_easy_setopt(curlHandle, CURLOPT_PORT, port);
    curl_easy_setopt(curlHandle, CURLOPT_CONNECT_ONLY, 1);
    curl_easy_setopt(curlHandle, CURLOPT_TIMEOUT_MS, 500);

    static const int kAllowedProtocols = CURLPROTO_FILE | CURLPROTO_FTP | CURLPROTO_FTPS | CURLPROTO_HTTP | CURLPROTO_HTTPS;
    curl_easy_setopt(curlHandle, CURLOPT_SSL_VERIFYPEER, false); // ignoreSSLErrors
    curl_easy_setopt(curlHandle, CURLOPT_SSL_VERIFYHOST, FALSE);
    curl_easy_setopt(curlHandle, CURLOPT_HTTPAUTH, CURLAUTH_ANY);
    curl_easy_setopt(curlHandle, CURLOPT_DNS_CACHE_TIMEOUT, 60 * 5); // 5 minutes
    curl_easy_setopt(curlHandle, CURLOPT_PROTOCOLS, kAllowedProtocols);
    curl_easy_setopt(curlHandle, CURLOPT_REDIR_PROTOCOLS, kAllowedProtocols);

    //curl_easy_setopt(curlHandle, CURLOPT_OPENSOCKETFUNCTION, OnOpensocket);

    // Connect to host
    const int kRetryCount = 5;
    CURLcode curlCode = CURLE_FAILED_INIT;
    for (int i = 0; i < kRetryCount; ++i) {
        if (0 != m_stopThread)
            break;
        curlCode = curl_easy_perform(curlHandle);
    }

    int64_t id = m_id;
    if (CURLE_OK != curlCode) {
        AddRef();
        //WTF::internal::callOnMainThread(s_mainThreadFail, this);
        content::ThreadCall::callBlinkThreadAsync(FROM_HERE, [id] {
            SocketStreamHandle* self = (SocketStreamHandle*)common::LiveIdDetect::get()->getPtr((intptr_t)id);
            if (self)
                self->mainThreadFail();
        });
        return;
    }

#if 0 // defined(OS_WIN)
    IUnknown* pUnknown = nullptr;
    INetworkListManager* pNetworkListManager = getNetworkList(&pUnknown);
#endif

    AddRef();

    //WTF::internal::callOnMainThread(s_mainThreadRun, this);
    content::ThreadCall::callBlinkThreadAsync(FROM_HERE, [id] {
        SocketStreamHandle* self = (SocketStreamHandle*)common::LiveIdDetect::get()->getPtr((intptr_t)id);
        if (self)
            self->mainThreadRun();
    });

    int retryCount = 0;
    while (0 == m_stopThread) {
        // Send queued data
        sendData(curlHandle);

        // Wait until socket has available data
        int waitResult = waitForAvailableData(curlHandle, 50);

        if (1 == waitResult) {
            if (!readData(curlHandle))
                retryCount++;
            else
                continue;
        } else if (-1 == waitResult) {
            ++retryCount;
        }

        int checkNetwork = 1;
#if 0 // defined(OS_WIN)
        checkIsNetwork(pNetworkListManager);
#endif
        if (retryCount > 10 || 0 == checkNetwork) {
            AddRef();
            //WTF::internal::callOnMainThread(s_mainThreadFail, this);
            content::ThreadCall::callBlinkThreadAsync(FROM_HERE, [id] {
                SocketStreamHandle* self = (SocketStreamHandle*)common::LiveIdDetect::get()->getPtr((intptr_t)id);
                if (self)
                    self->mainThreadFail();
            });
            break;
        }
    }

    curl_easy_cleanup(curlHandle);

#if 0 // defined(OS_WIN)
    if (pNetworkListManager)
        pNetworkListManager->Release();
    if (pUnknown)
        pUnknown->Release();
#endif
}

void SocketStreamHandle::startThread()
{
    DCHECK(WTF::IsMainThread());

    if (m_workerThread)
        return;

    AddRef(); // stopThread() will call Release().

    m_workerThread = static_cast<uintptr_t>(_beginthreadex(0, 0, webSocketThread, this, 0, nullptr));
}

int waitForThreadCompletion(uintptr_t threadID)
{
    DCHECK(threadID);

    HANDLE threadHandle = (HANDLE)(threadID);
    //     if (!threadHandle)
    //         WTF_LOG("ThreadIdentifier %u did not correspond to an active thread when trying to quit", threadID);

    DWORD joinResult = ::WaitForSingleObject(threadHandle, INFINITE);
    //     if (joinResult == WAIT_FAILED)
    //         WTF_LOG("ThreadIdentifier %u was found to be deadlocked trying to quit", threadID);

    CloseHandle(threadHandle);
    //clearThreadHandleForIdentifier(threadID);

    return joinResult;
}

void SocketStreamHandle::stopThread()
{
    DCHECK(WTF::IsMainThread());

    if (!m_workerThread)
        return;

    MB_InterlockedExchange(reinterpret_cast<long volatile*>(&m_stopThread), 1);
    waitForThreadCompletion(m_workerThread);
    m_workerThread = 0;
    Release();
}

void SocketStreamHandle::didReceiveData()
{
    DCHECK(WTF::IsMainThread());

    m_mutexReceive.lock();
    WTF::Deque<SocketData*> receiveData;
    receiveData.Swap(m_receiveData);
    m_mutexReceive.unlock();

    for (Deque<SocketData*>::iterator it = receiveData.begin(); it != receiveData.end(); ++it) {
        SocketData* socketData = *it;
        if (socketData->size > 0) {
            if (m_client && state() == Open && common::LiveIdDetect::get()->getPtr((intptr_t)m_clientId))
                m_client->didReceiveSocketStreamData(this, socketData->data, socketData->size);
        } else
            platformClose();
        delete socketData;
    }
}

void SocketStreamHandle::didOpenSocket()
{
    DCHECK(WTF::IsMainThread());

    m_state = Open;

    if (m_client && common::LiveIdDetect::get()->getPtr((intptr_t)m_clientId))
        m_client->didOpenSocketStream(this);
}

char* SocketStreamHandle::createCopy(const char* data, int length)
{
    char* copy = (new char[length]);
    memcpy(copy, data, length);

    return copy;
}

void SocketStreamHandle::didReceiveAuthenticationChallenge(const blink::AuthenticationChallenge&)
{
    DebugBreak();
}

void SocketStreamHandle::receivedCredential(const blink::AuthenticationChallenge&, const blink::Credential&)
{
    DebugBreak();
}

void SocketStreamHandle::receivedRequestToContinueWithoutCredential(const blink::AuthenticationChallenge&)
{
    DebugBreak();
}

void SocketStreamHandle::receivedCancellation(const blink::AuthenticationChallenge&)
{
    DebugBreak();
}

void SocketStreamHandle::receivedRequestToPerformDefaultHandling(const blink::AuthenticationChallenge&)
{
    DebugBreak();
}

void SocketStreamHandle::receivedChallengeRejection(const blink::AuthenticationChallenge&)
{
    DebugBreak();
}

} // namespace net