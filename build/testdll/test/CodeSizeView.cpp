
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <windows.h>

void readFileToBuf(const char* path, std::vector<char>* buffer);
void writeFileToBuf(const char* path, const char* buffer, size_t size);

std::string removeAll(const std::string& input, const std::string& substring)
{
    std::string result;
    size_t pos = 0;
    size_t abc_len = substring.size(); // "ABC"的长度

    while (pos < input.length()) {
        // 检查当前位置开始的子串是否是"ABC"
        if (pos + abc_len <= input.length() &&
            input.substr(pos, abc_len) == substring) {
            // 跳过"ABC"
            pos += abc_len;
        } else {
            // 不是"ABC"，将当前字符添加到结果中
            result += input[pos];
            pos++;
        }
    }

    return result;
}

/*
一个文件里有如下形式的数据：
static const uint8_t _http_client_raw[] = {
47,47,32,67,111,112,
};

static StaticExternalOneByteResource _http_client_resource(_http_client_raw, 28689, nullptr);

写一段c++代码， 把上面的数据改成：

static const uint8_t _http_client_raw[] = {
32,
};

static StaticExternalOneByteResource _http_client_resource(_http_client_raw, 1, nullptr);
*/

bool isDigit(char c) 
{
    return c >= '0' && c <= '9';
}

// 这个函数会处理输入字符串并返回修改后的字符串
std::string modifyData(const std::string& input)
{
    std::istringstream iss(input);
    std::string line;
    std::string result;

    std::string newLines;
    while (std::getline(iss, line)) {
        if (isDigit(line[0])) {
            newLines += "32\n";
            continue;
        }

        size_t pos1 = line.find(", nullptr);");
        if (pos1 != std::string::npos) {
            size_t pos2 = line.rfind(',', pos1 - 1);
            std::string temp1 = line.substr(0 , pos2 + 1);
            std::string temp2 = line.substr(pos1);
            std::string temp = temp1 + " 1" + temp2;
            newLines += temp;
            newLines += "\n";
            continue;
        }

        newLines += line;
        newLines += "\n";

    }

    return newLines;
}

// 辅助函数：去除字符串两端的空白字符
std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

// 辅助函数：分割字符串
std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(trim(token));
    }
    return tokens;
}

// 解析函数声明
struct FunctionInfo {
    std::string returnType;
    std::string functionName;
    std::vector<std::pair<std::string, std::string>> parameters; // <type, name>
};

std::unique_ptr<FunctionInfo> parseFunctionDeclaration(const std::string& declaration)
{
    std::unique_ptr<FunctionInfo> info = std::make_unique<FunctionInfo>();

    // 1. 提取返回值类型和函数名部分
    size_t parenStart = declaration.find('(');
    if (parenStart == std::string::npos) {
        //throw std::runtime_error("Invalid function declaration: no '(' found");
        return nullptr;
    }

    std::string beforeParen = declaration.substr(0, parenStart);
    // 去除可能的空格
    beforeParen = trim(beforeParen);

    // 2. 分离返回值类型和函数名
    size_t lastSpace = beforeParen.find_last_of(" \t\n\r");
    if (lastSpace == std::string::npos) {
        //throw std::runtime_error("Invalid function declaration: cannot separate return type and function name");
        DebugBreak();
    }

    info->returnType = trim(beforeParen.substr(0, lastSpace));
    info->functionName = trim(beforeParen.substr(lastSpace + 1));

    // 3. 提取参数部分
    size_t parenEnd = declaration.find(')', parenStart);
    if (parenEnd == std::string::npos) {
        throw std::runtime_error("Invalid function declaration: no ')' found");
    }

    std::string paramsStr = declaration.substr(parenStart + 1, parenEnd - parenStart - 1);
    paramsStr = trim(paramsStr);

    if (!paramsStr.empty()) {
        // 分割各个参数
        std::vector<std::string> paramParts = split(paramsStr, ',');

        for (const auto& paramPart : paramParts) {
            std::string param = trim(paramPart);
            if (param.empty()) {
                continue;
            }

            // 分离参数类型和参数名
            size_t lastParamSpace = param.find_last_of(" \t\n\r");
            if (lastParamSpace == std::string::npos) {
                // 可能是没有参数名的情况（如void函数），但根据题目要求，我们假设都有参数名
                //throw std::runtime_error("Invalid parameter declaration: cannot separate type and name");
                DebugBreak();
            }

            std::string paramType = trim(param.substr(0, lastParamSpace));
            std::string paramName = trim(param.substr(lastParamSpace + 1));

            info->parameters.emplace_back(paramType, paramName);
        }
    }

    return info;
}

void genYYThrunk(const std::string& input, const std::string& dllName)
{
    std::istringstream iss(input);
    std::string line;
    std::string result;

    std::string newLines;
    while (std::getline(iss, line)) {
        line = removeAll(line, "WINBASEAPI");
        line = removeAll(line, "WINAPI");
        line = removeAll(line, "EXTERN_C");
        line = removeAll(line, "WINADVAPI");
        line = removeAll(line, "_Outptr_opt_");
        line = removeAll(line, "_Out_opt_");
        line = removeAll(line, "_In_opt_");
        line = removeAll(line, "_In_");

        std::string returnType;
        std::vector<std::string> params;
        std::unique_ptr<FunctionInfo> info = parseFunctionDeclaration(line);
        if (!info)
            continue;

        std::string output;
        output += "__DEFINE_THUNK(\n";
        output += dllName + ",\n";
        char temp[64];
        sprintf(temp, "%d,\n", info->parameters.size() * 4);
        output += temp;
        output += info->returnType + ",\n";
        output += "WINAPI,\n";
        output += info->functionName + ",\n";

        int i = 0;
        for (const auto& param : info->parameters) {
            output += param.first;
            output += " ";
            output += param.second;
            if (i != info->parameters.size() - 1)
                output += ",\n";
            ++i;
        }
        output += ")\n";
        output += "{\n";
        output += "    const auto _pfn";
        output += info->functionName;
        output += "  = try_get_";
        output += info->functionName;
        output += "();\n";
        output += "    return _pfn";
        output += info->functionName;
        output += "(";

        i = 0;
        for (const auto& param : info->parameters) {
            output += param.second;
            if (i != info->parameters.size() - 1)
                output += ", ";
            ++i;
        }
        output += ");\n}\n\n";
        OutputDebugStringA(output.c_str());
    }
}


int codeSizeViewmmain() {
    // 原始输入数据
//     std::string input = R"(
// static const uint8_t _http_client_raw[] = {
// 47,47,32,67,111,112,
// };
// 
// static StaticExternalOneByteResource _http_client_resource(_http_client_raw, 28689, nullptr);
// )";
    //std::string output = modifyData(input);

//     std::vector<char> buffer;
//     readFileToBuf("W:\\mycode\\mb132\\third_party\\libnode\\gen\\src\\node\\node_javascript.cc", &buffer);
//     input = buffer.data();
//     std::string output = modifyData(input);
//     writeFileToBuf("W:\\mycode\\mb132\\third_party\\libnode\\gen\\src\\node\\node_javascript2.cc", output.data(), output.size());

    std::string line = removeAll("HANDLE WINAPI CreateSemaphoreW(_In_opt_ LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, _In_ LONG lInitialCount, _In_ LONG lMaximumCount, _In_opt_ LPCWSTR lpName);", "_In_opt_");

    std::string input = 
R"(

DWORD GetModuleFileNameExW(HANDLE hProcess, HMODULE hModule, LPWSTR lpFilename, DWORD nSize);


)";
    genYYThrunk(input, "kernel32");

    return 0;
}