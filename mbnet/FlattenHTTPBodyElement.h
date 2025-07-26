
#ifndef mbnet_FlattenHTTPBodyElement_h
#define mbnet_FlattenHTTPBodyElement_h

#include "content/common/common.h"
#include "services/network/public/mojom/data_pipe_getter.mojom.h"
#include "services/network/public/cpp/data_element.h"
#include <vector>

namespace mbnet {

struct FlattenHTTPBodyElement {
    enum Type { TypeData, TypeFile, TypeBlob } type;

    std::vector<char> data;
    std::u16string filePath;
    long long fileStart;
    long long fileLength; // -1 means to the end of the file.
};

class FlattenHTTPBodyElementStream {
public:
    FlattenHTTPBodyElementStream(const std::vector<FlattenHTTPBodyElement*>& elements, curl_off_t size)
    {
        m_elements = elements;
        m_estimateSize = size;
        m_allReadLength = 0;
        m_file = nullptr;
        reset();
    }

    ~FlattenHTTPBodyElementStream()
    {
        for (size_t i = 0; i < m_elements.size(); ++i) {
            delete m_elements[i];
        }
        reset();
    }

    void reset()
    {
        if (m_file)
            fclose(m_file);
        m_file = nullptr;
        m_elementIndex = 0;
        m_fileSize = 0;
        m_elementDataOffset = 0;
        m_elementDataLength = 0;
        m_totalFileReadLength = 0;
        m_originalDataOffset = 0;
    }

    size_t read(void* ptr, size_t blockSize, size_t numberOfBlocks, std::vector<char>* outBuf)
    {
        // Check for overflow.
        if (!numberOfBlocks || blockSize > std::numeric_limits<size_t>::max() / numberOfBlocks)
            return 0;
        if (m_elementIndex >= m_elements.size())
            return 0;

        const FlattenHTTPBodyElement& element = *(m_elements[m_elementIndex]);
        size_t readedLength = 0;

        if (FlattenHTTPBodyElement::Type::TypeFile == element.type) {
            readedLength = readFile(ptr, blockSize, numberOfBlocks, element, outBuf);
        } else {
            readedLength = readBuf(ptr, blockSize, numberOfBlocks, element, outBuf);
        }

        //         static int allSize = 0;
        //         allSize += readedLength;
        //
        //         char* output = (char*)malloc(0x100);
        //         sprintf_s(output, 0x99, "readFile: %d, allSize:%d\n", readedLength, allSize);
        //         OutputDebugStringA(output);
        //         free(output);

        return readedLength;
    }

    static size_t readFromDatePipe(FlattenHTTPBodyElement* flattenElement, const network::DataElementDataPipe& dataPipe)
    {
        MojoCreateDataPipeOptions options;
        options.struct_size = sizeof(MojoCreateDataPipeOptions);
        options.flags = MOJO_CREATE_DATA_PIPE_FLAG_NONE;
        options.element_num_bytes = 1;
        options.capacity_num_bytes = -1; // blink::BlobUtils::GetDataPipeCapacity(blob_data_handle_->size());

        mojo::ScopedDataPipeConsumerHandle consumerHandle;
        mojo::ScopedDataPipeProducerHandle producerHandle;
        MojoResult rv = mojo::CreateDataPipe(&options, producerHandle, consumerHandle);

        mojo::Remote<network::mojom::DataPipeGetter> dataPipeGetter;
        dataPipeGetter.Bind(dataPipe.CloneDataPipeGetter());

        dataPipeGetter->Read(std::move(producerHandle),
            base::BindOnce(
                [](FlattenHTTPBodyElement* flattenElement, mojo::ScopedDataPipeConsumerHandle consumerHandle, int32_t, uint64_t) {
                    const char* buffer = nullptr;
                    uint32_t pipeAvailableSize = 0;
                    MojoResult rv = consumerHandle->BeginReadData(reinterpret_cast<const void**>(&buffer), &pipeAvailableSize, MOJO_READ_DATA_FLAG_NONE);
                    CHECK(MOJO_RESULT_OK == rv || (MOJO_RESULT_SHOULD_WAIT == rv && 0 == pipeAvailableSize));

                    if (0 != pipeAvailableSize) {
                        size_t oldSize = flattenElement->data.size();
                        flattenElement->data.resize(oldSize + pipeAvailableSize); // .insert(flattenElement->data.end(), buffer, bytesEle.bytes().end());
                        memcpy(flattenElement->data.data() + oldSize, buffer, pipeAvailableSize);
                        consumerHandle->EndReadData(pipeAvailableSize);
                    }
                },
                base::Unretained(flattenElement), std::move(consumerHandle)));

        return 0;
    }

private:
    size_t readBuf(void* ptr, size_t blockSize, size_t numberOfBlocks, const FlattenHTTPBodyElement& element, std::vector<char>* outBuf)
    {
        if (-1 == numberOfBlocks)
            numberOfBlocks = element.data.size();

        const size_t maxBufferLength = blockSize * numberOfBlocks;
        size_t elementSize = element.data.size() - m_elementDataOffset;
        size_t readedLength = elementSize > maxBufferLength ? maxBufferLength : elementSize;

        if (readedLength > 0) {
            const char* realData = element.data.data() + m_elementDataOffset;
            if (!ptr) {
                outBuf->resize(readedLength);
                ptr = &outBuf->at(0);
            }
            memcpy(ptr, realData, readedLength);
            m_allReadLength += readedLength;
        }

        if (elementSize > readedLength)
            m_elementDataOffset += readedLength;
        else {
            m_elementDataOffset = 0;
            m_elementIndex++;
        }
        return readedLength;
    }

    size_t readBlobDownloadFile(void* ptr, size_t blockSize, size_t numberOfBlocks, const FlattenHTTPBodyElement& element, std::vector<char>* outBuf)
    {
        DebugBreak();
        return 0;
        //         CHECK(!ptr && -1 == numberOfBlocks);
        //
        //         BlobTempFileInfo* info = DownloadFileBlobCache::inst()->getBlobTempFileInfoByTempFilePath(element.filePath.c_str());
        //         CHECK(info);
        //
        //         size_t fileSize = element.fileLength;
        //         if (-1 == fileSize || fileSize > info->data.size())
        //             fileSize = info->data.size();
        //         outBuf->resize(fileSize);
        //
        //         if (0 != fileSize)
        //             memcpy(&outBuf->at(0), info->data.data(), fileSize);
        //
        //         m_allReadLength += fileSize;
        //         readFileFinish(nullptr, nullptr);
        //         return fileSize;
    }

    size_t readFile(void* ptr, size_t blockSize, size_t numberOfBlocks, const FlattenHTTPBodyElement& element, std::vector<char>* outBuf)
    {
#if defined(OS_WIN)
        WCHAR blobDownloadPath[] = L"file:///c:/miniblink_blob_download_";
        std::u16string subPath = element.filePath.substr(0, sizeof(blobDownloadPath) / sizeof(WCHAR) - 1);
        if (subPath == (const char16_t*)blobDownloadPath)
            return readBlobDownloadFile(ptr, blockSize, numberOfBlocks, element, outBuf);

        if (!m_file) {
            m_file = _wfopen((const WCHAR*)element.filePath.c_str(), L"rb");

            if (!m_file) {
                readFileFinish(L"FlattenHTTPBodyElementStream._wfopen Fail:", (const WCHAR*)element.filePath.c_str());
                // FIXME: show a user error?
                return 0;
            } else {
                fseek(m_file, 0L, SEEK_END);
                m_fileSize = ftell(m_file);
                fseek(m_file, 0, SEEK_SET);

                m_elementDataOffset = element.fileStart;
                m_elementDataLength = element.fileLength;

                if (0 == m_fileSize || m_elementDataOffset > m_fileSize) {
                    readFileFinish(nullptr, nullptr);
                    return 0;
                }

                if (-1 == element.fileLength || m_elementDataLength > m_fileSize)
                    m_elementDataLength = m_fileSize;
                m_totalFileReadLength = m_elementDataLength;

                if (m_elementDataOffset + m_elementDataLength > m_fileSize)
                    m_elementDataLength = m_fileSize - m_elementDataOffset;
                m_originalDataOffset = m_elementDataOffset;

                if (-1 == numberOfBlocks)
                    numberOfBlocks = m_elementDataLength;

                //                 char* output = (char*)malloc(0x100);
                //                 sprintf_s(output, 0x99, "m_totalFileReadLength:%d, %d %d\n", m_totalFileReadLength, (size_t)element.fileStart, (size_t)element.fileLength);
                //                 OutputDebugStringA(output);
                //                 free(output);
            }
        }

        const size_t maxBufferLength = blockSize * numberOfBlocks;
        size_t readedLength = 0;

        CHECK(!(0 == m_fileSize || m_elementDataOffset > m_fileSize || m_elementDataOffset + m_elementDataLength > m_fileSize));

        size_t needReadLength = m_elementDataLength;

        if (needReadLength > maxBufferLength)
            needReadLength = maxBufferLength;

        fseek(m_file, m_elementDataOffset, SEEK_SET);

        if (outBuf)
            outBuf->resize(needReadLength);
        if (!ptr && 0 != needReadLength)
            ptr = &outBuf->at(0);

        if (ptr && 0 != needReadLength)
            readedLength = fread(ptr, 1, needReadLength, m_file);
        m_allReadLength += readedLength;
        if (!readedLength || ferror(m_file)) {
            readFileFinish(L"FlattenHTTPBodyElementStream.ferror Fail:", (const WCHAR*)element.filePath.c_str());
            // FIXME: show a user error?
            return 0;
        }

        bool isEnd = feof(m_file);
        if (isEnd || m_elementDataLength == readedLength) {
            char* output = (char*)malloc(0x100);
            sprintf(output, "isEnd: %d, m_elementDataLength: %d, readedLength:%d, element.fileLength:%d\n", isEnd, m_elementDataLength, readedLength,
                (long)element.fileLength);
            OutputDebugStringA(output);
            free(output);

            CHECK(readedLength <= maxBufferLength);
            CHECK(m_elementDataOffset - m_originalDataOffset + readedLength == m_totalFileReadLength);
            CHECK(m_elementDataLength - readedLength == 0);
            readFileFinish(nullptr, nullptr);
        } else {
            CHECK(readedLength == maxBufferLength);
            m_elementDataOffset += readedLength;
            m_elementDataLength -= readedLength;
        }

        static int allSize = 0;
        allSize += readedLength;
        return readedLength;
#else
        content::printFuncName(__FUNCTION__, true, true);
        return 0;
#endif
    }

    void readFileFinish(const WCHAR* errorText1, const WCHAR* errorText2)
    {
        size_t elementIndex = m_elementIndex;
        reset();
        m_elementIndex = elementIndex + 1;

        if (errorText1) {
            std::u16string errorText = (const char16_t*)errorText1;
            errorText += (const char16_t*)errorText2;
            errorText += u"\n";
            OutputDebugStringW((LPCWSTR)errorText.c_str());
        }
    }

public:
    bool hasMoreElements() const
    {
        bool b = m_elementIndex < m_elements.size();
        if (!b) {
            CHECK(m_estimateSize == m_allReadLength);
        }
        return b;
    }

    static String getPathBySystemURL(const blink::WebURL& fileSystemURL)
    {
        blink::KURL url = fileSystemURL;
        String urlString = url.GetString();
        if (urlString.StartsWith("file:///"))
            urlString.Remove(0, 8);
        urlString.Replace("/", "\\");
        return urlString;
    }

    static void clampSliceOffsets(long long size, long long* start, long long* length)
    {
        CHECK(size != -1);

        // Convert the negative value that is used to select from the end.
        if (*start < 0)
            *start = *start + size;
        if (*length < 0)
            *length = size;

        // Clamp the range if it exceeds the size limit.
        if (*start < 0)
            *start = 0;

        if (*start >= size) {
            *start = 0;
            *length = 0;
        }

        if (*start + *length > size)
            *length = size - *start;
    }

    static void flatten(const blink::WebString& blobUUID, curl_off_t* size, WTF::Vector<FlattenHTTPBodyElement*>* flattenElements, long long parentOffset,
        long long parentLength, bool useParentSize, int deep)
    {
        //CHECK(deep <= 2);
        DebugBreak();
        //         FlattenHTTPBodyElement* flattenElement = nullptr;
        //         content::WebBlobRegistryImpl* blobReg = (content::WebBlobRegistryImpl*)blink::Platform::current()->blobRegistry();
        //         net::BlobDataWrap* blobData = blobReg->getBlobDataFromUUID(blobUUID);
        //         if (!blobData)
        //             return;
        //
        //         long long fileSizeResult = 0;
        //         const Vector<blink::WebBlobData::Item*>& items = blobData->items();
        //
        // //         if (2 == deep && items.size() != 1)
        // //             CHECK(false);
        //
        //         for (size_t i = 0; i < items.size(); ++i) {
        //             blink::WebBlobData::Item* item = items[i];
        //             if (blink::WebBlobData::Item::TypeData == item->type) {
        //
        //                 long long offset = parentOffset;
        //                 long long length = parentLength;
        //                 if (!useParentSize || -1 == length) {
        //                     offset = item->offset;
        //                     length = item->length;
        //                 }
        //                 clampSliceOffsets(item->data.size(), &offset, &length);
        //
        //                 if (length <= 0)
        //                     continue;
        //
        //                 flattenElement = new FlattenHTTPBodyElement();
        //                 flattenElement->type = FlattenHTTPBodyElement::Type::TypeData;
        //
        //                 flattenElement->data.append(item->data.data() + offset, length);
        //                 flattenElements->append(flattenElement);
        //
        //                 *size += length;
        //             } else if (blink::WebBlobData::Item::TypeFile == item->type || blink::WebBlobData::Item::TypeFileSystemURL == item->type) {
        //                 String filePath = item->filePath;
        //                 if (blink::WebBlobData::Item::TypeFileSystemURL == item->type) {
        //                     blink::KURL fileSystemURL = item->fileSystemURL;
        //                     filePath = getPathBySystemURL(fileSystemURL);
        //                 }
        //
        //                 long long offset = parentOffset;
        //                 long long length = parentLength;
        //                 if (!useParentSize || -1 == length) {
        //                     offset = item->offset;
        //                     length = item->length;
        //                 }
        //
        //                 if (-1 != filePath.find("miniblink_blob_download_")) {
        //                     BlobTempFileInfo* info = DownloadFileBlobCache::inst()->getBlobTempFileInfoByTempFilePath(filePath);
        //                     CHECK(info);
        //
        //                     fileSizeResult = info->data.size();
        //                     if (offset > fileSizeResult)
        //                         offset = fileSizeResult;
        //
        //                     char* output = (char*)malloc(0x100);
        //                     sprintf(output, "flatten blob: fileSizeResult:%lld, offset:%lld, parentOffset:%lld, parentLength:%lld\n",
        //                             fileSizeResult, offset, parentOffset, parentLength);
        //                     OutputDebugStringA(output);
        //                     free(output);
        //
        //                     flattenElement = new FlattenHTTPBodyElement();
        //                     flattenElement->type = FlattenHTTPBodyElement::Type::TypeData;
        //
        //                     long long appendSize = fileSizeResult - offset;
        //
        //                     flattenElement->data.append(info->data.data() + offset, appendSize);
        //                     flattenElements->append(flattenElement);
        //
        //                     *size += appendSize;
        //                 } else if (getFileSize(filePath, fileSizeResult)) {
        //                     clampSliceOffsets(fileSizeResult, &offset, &length);
        //                     if (length <= 0)
        //                         continue;
        //
        //                     *size += length;
        //
        //                     flattenElement = new FlattenHTTPBodyElement();
        //                     flattenElement->type = FlattenHTTPBodyElement::Type::TypeFile;
        //                     Vector<UChar> filePathBuf = WTF::ensureUTF16UChar(filePath, true);
        //                     flattenElement->filePath = filePathBuf.data();
        //                     flattenElement->fileStart = offset; // item->offset;
        //                     flattenElement->fileLength = length; // item->length;
        //                     flattenElements->append(flattenElement);
        //                 }
        //             } else if (blink::WebBlobData::Item::TypeBlob == item->type) {
        //                 //OutputDebugStringA("FlattenHTTPBodyElementStream::flatten, TypeBlob\n");
        //                 flatten(item->blobUUID, size, flattenElements, item->offset, item->length, true, deep + 1);
        //             }
        //         }
    }

private:
    FILE* m_file;
    size_t m_fileSize;
    size_t m_elementIndex;
    size_t m_elementDataOffset;
    size_t m_elementDataLength;
    size_t m_totalFileReadLength;
    size_t m_allReadLength;
    size_t m_originalDataOffset;
    curl_off_t m_estimateSize;
    std::vector<FlattenHTTPBodyElement*> m_elements;
};

}

#endif // net_FlattenHTTPBodyElement_h