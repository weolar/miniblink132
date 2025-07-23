
#include "CmdHandler.h"
#include <tchar.h>
#include <vector>

#define EXCEPTIION_STATE_CHECK                                                                                                                                 \
    if (!m_bInit)                                                                                                                                              \
    return E_NOTIMPL

CmdHandler::CmdHandler()
    : m_bInit(FALSE)
    , m_dwErrorCode(0)
    , m_hPipeRead(NULL)
    , m_hPipeWrite(NULL)
{
    ZeroMemory(m_szReadBuffer, sizeof(m_szReadBuffer));
    ZeroMemory(m_szWriteBuffer, sizeof(m_szWriteBuffer));
    //ZeroMemory(&m_CommandParam, sizeof(m_CommandParam));
}

CmdHandler::~CmdHandler()
{
}

HRESULT CmdHandler::Initalize()
{
    // 初始化，创建匿名管道
    if (m_bInit)
        return S_OK;
    m_bInit = TRUE;
    ZeroMemory(m_szReadBuffer, sizeof(m_szReadBuffer));
    ZeroMemory(&m_saOutPipe, sizeof(m_saOutPipe));
    m_saOutPipe.nLength = sizeof(SECURITY_ATTRIBUTES);
    m_saOutPipe.lpSecurityDescriptor = NULL;
    m_saOutPipe.bInheritHandle = TRUE;
    ZeroMemory(&m_startupInfo, sizeof(STARTUPINFO));
    ZeroMemory(&m_processInfo, sizeof(PROCESS_INFORMATION));

    if (!CreatePipe(&m_hPipeRead, &m_hPipeWrite, &m_saOutPipe, PIPE_BUFFER_SIZE)) {
        m_dwErrorCode = GetLastError();
        return E_FAIL;
    }
    return S_OK;
}

HRESULT CmdHandler::Finish()
{
    EXCEPTIION_STATE_CHECK;
    if (m_hPipeRead) {
        CloseHandle(m_hPipeRead);
        m_hPipeRead = NULL;
    }
    if (m_hPipeWrite) {
        CloseHandle(m_hPipeWrite);
        m_hPipeWrite = NULL;
    }
    return S_OK;
}

HRESULT CmdHandler::HandleCommand(CHCmdParam* pCommmandParam)
{
    EXCEPTIION_STATE_CHECK;
    if (!pCommmandParam || pCommmandParam->iSize != sizeof(CHCmdParam))
        return E_INVALIDARG;
    if (wcslen(pCommmandParam->szCommand) <= 0)
        return E_UNEXPECTED;
    //memset(&m_CommandParam, 0, sizeof(m_CommandParam));
    m_CommandParam = *pCommmandParam;
    return ExecuteCmdWait();
}

HRESULT CmdHandler::ExecuteCmdWait()
{
    EXCEPTIION_STATE_CHECK;
    HRESULT hResult = E_FAIL;
    DWORD dwReadLen = 0;
    DWORD dwStdLen = 0;
    m_startupInfo.cb = sizeof(STARTUPINFO);
    m_startupInfo.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
    m_startupInfo.hStdOutput = m_hPipeWrite;
    m_startupInfo.hStdError = m_hPipeWrite;
    m_startupInfo.wShowWindow = SW_HIDE;
    DWORD dTimeOut = (DWORD)-1; // m_CommandParam.iTimeOut >= 3000 ? m_CommandParam.iTimeOut : 5000;
    do {
        if (!CreateProcessW(NULL, m_CommandParam.szCommand, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &m_startupInfo, &m_processInfo)) {
            m_dwErrorCode = GetLastError();
            hResult = E_FAIL;
            break;
        }
        if (WAIT_TIMEOUT == WaitForSingleObject(m_processInfo.hProcess, dTimeOut)) {
            m_dwErrorCode = GetLastError();
            hResult = CO_E_SERVER_START_TIMEOUT;
            if (m_CommandParam.OnCmdEvent)
                m_CommandParam.OnCmdEvent(&m_CommandParam, CO_E_SERVER_START_TIMEOUT, "");
            break;
        }
        // 预览管道中数据的内容
        BOOL b = PeekNamedPipe(m_hPipeRead, m_szPipeOut, PIPE_BUFFER_SIZE, NULL, &dwReadLen, NULL);
        m_dwErrorCode = GetLastError();
        if (b && m_dwErrorCode == 5) {
        }

        if (!b || dwReadLen >= PIPE_BUFFER_SIZE) {
            m_dwErrorCode = GetLastError();
            DebugBreak();
            hResult = E_FAIL;
            break;
        } else if (dwReadLen <= 0) {
            hResult = S_OK;
            if (m_CommandParam.OnCmdEvent)
                m_CommandParam.OnCmdEvent(&m_CommandParam, S_OK, "no data");
            break;
        }

        ZeroMemory(m_szPipeOut, sizeof(m_szPipeOut));
        // 读取管道中的数据
        if (ReadFile(m_hPipeRead, m_szPipeOut, dwReadLen, &dwStdLen, NULL)) {
            hResult = S_OK;
            if (m_CommandParam.OnCmdEvent)
                m_CommandParam.OnCmdEvent(&m_CommandParam, S_OK, m_szPipeOut);
            break;
        } else {
            m_dwErrorCode = GetLastError();
            break;
        }

    } while (0);

    if (m_processInfo.hThread) {
        CloseHandle(m_processInfo.hThread);
        m_processInfo.hThread = NULL;
    }
    if (m_processInfo.hProcess) {
        CloseHandle(m_processInfo.hProcess);
        m_processInfo.hProcess = NULL;
    }
    return hResult;
}

// void appendBuffer(std::vector<char>* buffer, const char* temp, size_t tempSize)
// {
//     if (0 == tempSize)
//         return;
//     size_t oldSize = buffer->size();
//     buffer->resize(oldSize + tempSize);
//     memcpy(buffer->data() + oldSize, temp, tempSize);
// }
//
// HRESULT CmdHandler::ExecuteCmdWait()
// {
//     EXCEPTIION_STATE_CHECK;
//     HRESULT hResult = E_FAIL;
//     DWORD dwReadLen = 0;
//     DWORD dwStdLen = 0;
//     m_startupInfo.cb = sizeof(STARTUPINFO);
//     m_startupInfo.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
//     m_startupInfo.hStdOutput = m_hPipeWrite;
//     m_startupInfo.hStdError = m_hPipeWrite;
//     m_startupInfo.wShowWindow = SW_HIDE;
//     DWORD dTimeOut = (DWORD)-1; // m_CommandParam.iTimeOut >= 3000 ? m_CommandParam.iTimeOut : 5000;
//     do {
//         if (!CreateProcessW(NULL, m_CommandParam.szCommand,
//             NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL,
//             &m_startupInfo, &m_processInfo)) {
//             m_dwErrorCode = GetLastError();
//             hResult = E_FAIL;
//             break;
//         }
//         if (WAIT_TIMEOUT == WaitForSingleObject(m_processInfo.hProcess, dTimeOut)) {
//             m_dwErrorCode = GetLastError();
//             hResult = CO_E_SERVER_START_TIMEOUT;
//             if (m_CommandParam.OnCmdEvent)
//                 m_CommandParam.OnCmdEvent(&m_CommandParam, CO_E_SERVER_START_TIMEOUT, "");
//             break;
//         }
//
//         std::vector<char> buffer;
//         bool needLoop = false;
//         hResult = S_OK;
//         dwReadLen = sizeof(m_szPipeOut);
//
//         do {
//             dwStdLen = 0;
//             needLoop = false;
//             ZeroMemory(m_szPipeOut, sizeof(m_szPipeOut));
//
//             BOOL b = PeekNamedPipe(m_hPipeRead, m_szPipeOut, sizeof(m_szPipeOut), NULL, &dwReadLen, NULL);
//             if (!b || dwReadLen >= PIPE_BUFFER_SIZE) {
//                 m_dwErrorCode = GetLastError();
//                 DebugBreak();
//                 hResult = E_FAIL;
//                 break;
//             } else if (dwReadLen <= 0) {
//                 hResult = S_OK;
//                 break;
//             }
//
//             if (!ReadFile(m_hPipeRead, m_szPipeOut, dwReadLen, &dwStdLen, NULL)) {
//                 m_dwErrorCode = GetLastError();
//                 DebugBreak();
//                 hResult = E_FAIL;
//                 break;
//             }
//
//             appendBuffer(&buffer, m_szPipeOut, dwStdLen);
//
//             m_dwErrorCode = GetLastError();
//             if (5 == m_dwErrorCode) {
//                 needLoop = true;
//                 continue;
//             } else {
//                 OutputDebugStringA("");
//             }
//
//             if (dwReadLen == 0)
//                 break;
//         } while (needLoop);
//
//         if (buffer.size() == 0) {
//             m_CommandParam.OnCmdEvent(&m_CommandParam, S_OK, "no data");
//             break;
//         }
//         buffer.push_back('\0');
//         m_CommandParam.OnCmdEvent(&m_CommandParam, S_OK, buffer.data());
//
//     } while (0);
//
//     if (m_processInfo.hThread) {
//         CloseHandle(m_processInfo.hThread);
//         m_processInfo.hThread = NULL;
//     }
//     if (m_processInfo.hProcess) {
//         CloseHandle(m_processInfo.hProcess);
//         m_processInfo.hProcess = NULL;
//     }
//     return hResult;
// }