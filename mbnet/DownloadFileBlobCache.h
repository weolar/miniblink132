
#if 0 // ndef net_DownloadFileBlobCache_h
#define net_DownloadFileBlobCache_h

namespace mbnet {

class DownloadFileBlobCache {
public:
    static DownloadFileBlobCache* inst();

    void shutdown();

    void appendDataToBlobCache(
        blink::WebURLLoaderClient* client,
        blink::WebURLLoader* loader,
        const String& url,
        const char* data,
        int dataLength,
        int encodedDataLength
        );

    BlobTempFileInfo* getBlobTempFileInfoByTempFilePath(const String& path);
    String createBlobTempFileInfoByUrlIfNeeded(const String& url);
    void removeBlobTempFileInfo(const String& path);

private:
    static DownloadFileBlobCache* m_inst;

    typedef WTF::HashMap<String, BlobTempFileInfo*> BlobCache;
    BlobCache m_blobCaches; // real url -> <temp, data>
};
    
}

#endif