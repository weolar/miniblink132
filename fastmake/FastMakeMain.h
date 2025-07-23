
#ifndef FastMakeMain_h
#define FastMakeMain_h

#include <string>

enum RebuildOpt {
    kRebuildOptAll,
    kRebuildOptPrebuildSrcAndLink, // 预编译
    kRebuildOptOnlyLink, //只链接
    kRebuildOptCompileTimeOutFile, // 编译超时文件
};

void fmFastBuild(const std::wstring& buildJsonPath, RebuildOpt opt); // 这个是测试的
void fmBuild(const std::wstring& buildJsonPath);

#endif