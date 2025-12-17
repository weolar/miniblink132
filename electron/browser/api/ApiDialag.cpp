
#include "electron/nodeblink.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/StringUtil.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/browser/api/WindowInterface.h"
#include "electron/browser/api/WindowList.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libuv/include/uv.h"
#include "electron/common/gin_helper/promise.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "content/common/mbchar.h"
#include "content/common/ThreadCall.h"
#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"
#include <Shobjidl.h>
#include <Shlobj.h>
#include <shlwapi.h>
#include <CommDlg.h>
#include <cderr.h>
#include <vector>

//struct __declspec(uuid("00000000-0000-0000-c000-000000000046")) IFileOpenDialog;
namespace content {
void printCallstack();
}

namespace atom {

class Dialog : public mate::EventEmitter<Dialog> {
public:
    explicit Dialog(v8::Isolate* isolate, v8::Local<v8::Object> wrapper)
    {
        gin_helper::Wrappable<Dialog>::InitWith(isolate, wrapper);
    }

    static void init(v8::Isolate* isolate, v8::Local<v8::Object> target)
    {
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, newFunction);

        prototype->SetClassName(v8::String::NewFromUtf8(isolate, "Dialog").ToLocalChecked());
        gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
        builder.SetMethod("_showOpenDialog", &Dialog::_showOpenDialogApi);
        builder.SetMethod("_showSaveDialog", &Dialog::_showSaveDialogApi);
        builder.SetMethod("_showOpenDialogSync", &Dialog::_showOpenDialogSyncApi);
        builder.SetMethod("_showSaveDialogSync", &Dialog::_showSaveDialogSyncApi);
        builder.SetMethod("_showMessageBox", &Dialog::_showMessageBoxApi);
        builder.SetMethod("_showMessageBoxSync", &Dialog::_showMessageBoxSyncApi);
        builder.SetMethod("_showErrorBox", &Dialog::_showErrorBoxApi);

        constructor.Reset(isolate, prototype->GetFunction(context).ToLocalChecked());
        target->Set(context, v8::String::NewFromUtf8(isolate, "Dialog").ToLocalChecked(), prototype->GetFunction(context).ToLocalChecked());
    }

    void nullFunction()
    {
    }

    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        v8::Isolate* isolate = args.GetIsolate();
        if (args.IsConstructCall()) {
            new Dialog(isolate, args.This());
            args.GetReturnValue().Set(args.This());
            return;
        }
    }

    // showSaveDialog([browserWindow, ]options[, callback])
    void _showSaveDialogApi(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        _showOpenOrSaveDialogApi(false, false, args);
    }

    void _showOpenDialogApi(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        _showOpenOrSaveDialogApi(true, false, args);
    }

    void _showSaveDialogSyncApi(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        _showOpenOrSaveDialogApi(false, true, args);
    }

    void _showOpenDialogSyncApi(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        _showOpenOrSaveDialogApi(true, true, args);
    }

    // <description, extensions>
    typedef std::pair<std::string, std::vector<std::string>> Filter;
    typedef std::vector<Filter> Filters;

    struct ShowOpenOrSaveDialogThreadInfo {
        bool isOpenOrSave;
        std::string* title;
        std::string* defaultPath;
        std::string* buttonLabel;
        Filters* filters;
        //base::Value::List* properties;
        int fileDialogProperty;
        v8::Isolate* isolate;
        v8::Persistent<v8::Object> recv;
        v8::Persistent<v8::Function> callback;
        base::Value::List* paths;
        bool canceled;
        HWND hwnd;
        int* sync;

        ~ShowOpenOrSaveDialogThreadInfo()
        {
            delete title;
            delete defaultPath;
            delete buttonLabel;
            delete filters;
            //delete properties;
            delete paths;
        }
    };

    static void showOpenOrSaveDialogEnd(ShowOpenOrSaveDialogThreadInfo* info)
    {
        v8::Local<v8::Value> result = v8::Undefined(info->isolate);
        if (0 != info->paths->size())
            result = gin_helper::Converter<base::Value::List>::ToV8(info->isolate, *info->paths);

        v8::Local<v8::Object> recv = info->recv.Get(info->isolate);
        v8::Local<v8::Value> argv[2];
        argv[0] = info->canceled ? v8::True(info->isolate) : v8::False(info->isolate); // canceled: boolean
        argv[1] = result; // filePaths: string[]

        info->callback.Get(info->isolate)->Call(recv->GetCreationContextChecked(), recv, 2, argv);

        delete info;
    }

    static DWORD __stdcall showOpenOrSaveDialogThreadEntryPoint(void* param)
    {
        ShowOpenOrSaveDialogThreadInfo* info = (ShowOpenOrSaveDialogThreadInfo*)param;
        info->canceled = !showOpenOrSaveDialog(
            info->isOpenOrSave, info->hwnd, *info->title, *info->buttonLabel, *info->defaultPath, *info->filters, info->fileDialogProperty, info->paths);
        if (info->sync) {
            *info->sync = 1;
            return 0;
        }
        content::ThreadCall::callUiThreadAsync(FROM_HERE, [info] { showOpenOrSaveDialogEnd(info); });
        return 0;
    }

    // showOpenDialog([browserWindow, ]options[, callback])
    void _showOpenOrSaveDialogApi(bool isOpenOrSave, bool isSync, const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        if (3 != args.Length())
            return;
        v8::Isolate* isolate = args.GetIsolate();
        v8::Local<v8::Context> context = isolate->GetCurrentContext();

        int browserWindowId = -1;
        if (args[0]->IsInt32())
            browserWindowId = args[0]->ToInt32(context).ToLocalChecked()->Value();

        v8::Local<v8::Object> options;
        if (args[1]->IsObject())
            options = args[1]->ToObject(context).ToLocalChecked();

        int sync = 0;

        ShowOpenOrSaveDialogThreadInfo* info = new ShowOpenOrSaveDialogThreadInfo();
        info->title = new std::string();
        info->defaultPath = new std::string();
        info->buttonLabel = new std::string();
        info->filters = new Filters();
        //info->properties = nullptr;
        info->isolate = isolate;
        info->isOpenOrSave = isOpenOrSave;
        info->paths = new base::Value::List();
        info->sync = isSync ? &sync : nullptr;
        info->canceled = true;
        info->hwnd = NULL;

        WindowInterface* face = WindowList::getInstance()->find(browserWindowId);
        if (face)
            info->hwnd = face->getHWND();

        getOptions(isolate, options, info->title, info->defaultPath, info->filters, info->buttonLabel, /*&info->properties,*/ &info->fileDialogProperty);

        v8::Function* callback = nullptr;
        if (args[2]->IsFunction()) {
            //callback = v8::Function::Cast(*(args[2]));
            info->callback.Reset(isolate, args[2].As<v8::Function>());
        } else if (!isSync)
            DebugBreak();

        info->recv.Reset(isolate, isolate->GetCurrentContext()->Global());

        DWORD threadIdentifier = 0;
        HANDLE threadHandle = ::CreateThread(0, 0, showOpenOrSaveDialogThreadEntryPoint, info, 0, &threadIdentifier);
        ::CloseHandle(threadHandle);

        if (!isSync)
            return;

        while (*info->sync == 0) {
            ::Sleep(1);
        }

        v8::Local<v8::Value> result = v8::Undefined(isolate);
        if (0 != info->paths->size())
            result = gin_helper::Converter<base::Value::List>::ToV8(isolate, *info->paths);

        //         if (callback) {
        //             v8::Local<v8::Object> recv = args.GetIsolate()->GetCurrentContext()->Global();
        //             v8::Local<v8::Value> argv[1];
        //             argv[0] = result;
        //             callback->Call(recv, 1, argv);
        //         } else
        args.GetReturnValue().Set(result);
    }

    void _showErrorBoxApi(const std::string& title, const std::string& content)
    {
        content::printCallstack();
        std::u16string titleW = base::UTF8ToUTF16(title);
        std::u16string contentW = base::UTF8ToUTF16(content);
        ::MessageBoxW(nullptr, (LPCWSTR)contentW.c_str(), (LPCWSTR)titleW.c_str(), MB_OK);
    }

    void _showMessageBoxApi(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        showMessageBoxSyncImpl(args, false);
    }

    void _showMessageBoxSyncApi(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        showMessageBoxSyncImpl(args, true);
    }

    struct ShowMessageBoxThreadInfo {
        Dialog* self;
        std::u16string title;
        std::u16string message;
        int uType;
        int buttonsSize;
        v8::Isolate* isolate;
        gin_helper::Promise<gin_helper::Dictionary>* promise;
        HWND hwnd;
        int result;
    };

    static DWORD __stdcall showMessageBoxThreadEntryPoint(void* param)
    {
        ShowMessageBoxThreadInfo* info = (ShowMessageBoxThreadInfo*)param;

        int result = ::MessageBoxW(nullptr, (LPCWSTR)info->message.c_str(), (LPCWSTR)info->title.c_str(), info->uType);
        if (1 == info->buttonsSize) {
            result = 0;
        } else if (2 == info->buttonsSize) {
            if (IDYES == result)
                result = 0;
            else
                result = 1;
        } else if (3 == info->buttonsSize) {
            if (IDYES == result)
                result = 0;
            else if (IDNO == result)
                result = 1;
            else
                result = 2;
        }
        info->result = result;
        if (info->promise) {
            content::ThreadCall::callUiThreadAsync(FROM_HERE, [info] {
                v8::HandleScope handleScope(info->isolate);
                v8::TryCatch block(info->isolate);
                gin_helper::Dictionary dict = gin_helper::Dictionary::CreateEmpty(info->isolate);

                dict.Set("response", info->result);
                dict.Set("checkboxChecked", false);

                info->promise->Resolve(dict);
                delete info->promise;
                delete info;
            });
        }
        return 0;
    }

    void showMessageBoxSyncImpl(const v8::FunctionCallbackInfo<v8::Value>& args, bool isSync)
    {
        if (3 != args.Length())
            return;

        v8::Isolate* isolate = args.GetIsolate();
        v8::Local<v8::Context> context = isolate->GetCurrentContext();

        int browserWindowId = -1;
        v8::Local<v8::Object> options;
        if (args[0]->IsInt32())
            browserWindowId = args[0]->ToInt32(context).ToLocalChecked()->Value();

        if (args[1]->IsObject())
            options = args[1]->ToObject(context).ToLocalChecked();

        v8::Function* callback = nullptr;
        if (args[2]->IsFunction())
            callback = v8::Function::Cast(*(args[2]));

        std::string title;
        std::string message;
        std::string detail;
        std::string type;
        std::vector<std::string> buttons;
        getMessageOptions(isolate, options, &title, &message, &detail, &type, &buttons);

        UINT uType = MB_ICONINFORMATION;
        if ("error" == type)
            uType = MB_ICONERROR;
        else if ("question" == type)
            uType = MB_ICONQUESTION;
        else if ("warning" == type)
            uType = MB_ICONWARNING;

        if (1 == buttons.size())
            uType |= MB_OK;
        else if (2 == buttons.size())
            uType |= MB_YESNO;
        else if (3 == buttons.size())
            uType |= MB_YESNOCANCEL;

        ShowMessageBoxThreadInfo* info = new ShowMessageBoxThreadInfo();
        info->message = base::UTF8ToUTF16(message);
        info->message += (const char16_t*)L" ";
        info->message += base::UTF8ToUTF16(detail);
        info->result = -1;
        info->self = this;
        info->uType = uType;
        info->title = base::UTF8ToUTF16(title);
        info->buttonsSize = buttons.size();
        info->promise = nullptr;
        info->isolate = isolate;
        info->hwnd = nullptr;

        v8::Local<v8::Promise> handle;
        if (!isSync) {
            info->promise = new gin_helper::Promise<gin_helper::Dictionary>(isolate);
            handle = info->promise->GetHandle();
        }
        DWORD threadIdentifier = 0;
        HANDLE threadHandle = ::CreateThread(0, 0, showMessageBoxThreadEntryPoint, info, 0, &threadIdentifier);
        ::CloseHandle(threadHandle);

        if (isSync) {
            while (info->result < 0) {
                ::Sleep(1);
            }

            v8::Local<v8::Value> v8Result = v8::Integer::New(isolate, info->result).As<v8::Value>();
            if (callback) {
                v8::Local<v8::Object> recv = isolate->GetCurrentContext()->Global();
                v8::Local<v8::Value> argv[1];
                argv[0] = v8Result;
                callback->Call(isolate->GetCurrentContext(), recv, 1, argv);
            } else
                args.GetReturnValue().Set(v8Result);

            delete info;
        } else {
            args.GetReturnValue().Set(handle);
        }
    }

private:
    enum FileDialogProperty {
        FILE_DIALOG_OPEN_FILE = 1 << 0,
        FILE_DIALOG_OPEN_DIRECTORY = 1 << 1,
        FILE_DIALOG_MULTI_SELECTIONS = 1 << 2,
        FILE_DIALOG_CREATE_DIRECTORY = 1 << 3,
        FILE_DIALOG_SHOW_HIDDEN_FILES = 1 << 4,
        FILE_DIALOG_PROMPT_TO_CREATE = 1 << 5,
    };

    void getMessageOptions(
        v8::Isolate* isolate, 
        v8::Local<v8::Object> options, 
        std::string* title, 
        std::string* message, 
        std::string* detail,
        std::string* type, 
        std::vector<std::string>* buttons)
    {
        base::Value::Dict optionsDict;
        if (options.IsEmpty() || !gin_helper::Converter<base::Value::Dict>::FromV8(isolate, options, &optionsDict))
            return;

        std::string* tempStr = optionsDict.FindString("title");
        if (tempStr)
            *title = *tempStr;
        tempStr = optionsDict.FindString("message");
        if (tempStr)
            *message = *tempStr;

        tempStr = optionsDict.FindString("detail");
        if (tempStr)
            *detail = *tempStr;

        tempStr = optionsDict.FindString("type");
        if (tempStr)
            *type = *tempStr;

        base::Value::List* buttonsList = nullptr;
        buttonsList = optionsDict.FindList("buttons");
        if (!buttonsList)
            return;

        for (size_t i = 0; i < buttonsList->size(); ++i) {
            std::string button;
            const base::Value& val = (*buttonsList)[i];
            if (val.is_string())
                button = *val.GetIfString();
            if (!button.empty())
                buttons->push_back(button);
        }
    }

    void getOptions(v8::Isolate* isolate, v8::Local<v8::Object> options, std::string* title, std::string* defaultPath, Filters* filters,
        std::string* buttonLabel, int* fileDialogProperty)
    {
        base::Value::Dict optionsDict;
        if (options.IsEmpty() || !gin_helper::Converter<base::Value::Dict>::FromV8(isolate, options, &optionsDict))
            return;

        base::Value::List* properties = nullptr;

        std::string* temp = optionsDict.FindString("title");
        if (temp)
            *title = *temp;
        temp = optionsDict.FindString("defaultPath");
        if (temp)
            *defaultPath = *temp;
        temp = optionsDict.FindString("buttonLabel");
        if (temp)
            *buttonLabel = *temp;
        properties = optionsDict.FindList("properties");

        *fileDialogProperty = propertiesToEnum(properties);

        base::Value::List* filtersList = nullptr;
        filtersList = optionsDict.FindList("filters");
        if (!filtersList)
            return;

        for (size_t i = 0; i < filtersList->size(); ++i) {
            const base::Value::Dict* filtersItem;
            const base::Value& filtersListVal = (*filtersList)[i];
            if (!filtersListVal.is_dict())
                continue;
            filtersItem = filtersListVal.GetIfDict();

            const std::string* name = filtersItem->FindString("name");
            if (!name)
                continue;
            const base::Value::List* extensionsList = filtersItem->FindList("extensions");
            if (!extensionsList)
                continue;

            Filter filter;
            std::vector<std::string> extensions;
            for (size_t j = 0; j < extensionsList->size(); ++j) {
                const base::Value& extensionsListVal = (*extensionsList)[i];
                if (!extensionsListVal.is_string())
                    continue;
                const std::string* extension = extensionsListVal.GetIfString();
                if (!extension)
                    continue;
                if (extension->empty() || ((size_t)-1) != extension->find(L'.'))
                    continue;
                extensions.push_back(*extension);
            }
            if (0 == extensions.size())
                extensions.push_back("*");
            filter.first = *name;
            filter.second = extensions;
            filters->push_back(filter);
        }
    }

    int propertiesToEnum(base::Value::List* properties)
    {
        int out = 0;
        if (!properties)
            return out;

        for (size_t i = 0; i < properties->size(); ++i) {
            const base::Value& propertieVal = (*properties)[i];
            if (!propertieVal.is_string())
                continue;
            const std::string* propertie = propertieVal.GetIfString();
            if (!propertie)
                continue;
            if ("openFile" == *propertie)
                out |= FILE_DIALOG_OPEN_FILE;
            else if ("openDirectory" == *propertie)
                out |= FILE_DIALOG_OPEN_DIRECTORY;
            else if ("multiSelections" == *propertie)
                out |= FILE_DIALOG_MULTI_SELECTIONS;
            else if ("showHiddenFiles" == *propertie)
                out |= FILE_DIALOG_SHOW_HIDDEN_FILES;
            else if ("createDirectory" == *propertie)
                out |= FILE_DIALOG_CREATE_DIRECTORY;
            else if ("promptToCreate" == *propertie)
                out |= FILE_DIALOG_PROMPT_TO_CREATE;
        }
        return out;
    }

    //     std::vector<std::u16string> showOpenFile() {
    //         HRESULT hr = S_OK;
    //         std::vector<std::u16string> filePaths;
    //
    //         IFileOpenDialog *fileDlg = NULL;
    //         hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&fileDlg));
    //         if (FAILED(hr)) return filePaths;
    //         //ON_SCOPE_EXIT([&] { fileDlg->Release(); });
    //
    //         IKnownFolderManager *pkfm = NULL;
    //         hr = CoCreateInstance(CLSID_KnownFolderManager,
    //             NULL,
    //             CLSCTX_INPROC_SERVER,
    //             IID_PPV_ARGS(&pkfm));
    //         if (FAILED(hr)) return filePaths;
    //         //ON_SCOPE_EXIT([&] { pkfm->Release(); });
    //
    //         IKnownFolder *pKnownFolder = NULL;
    //         hr = pkfm->GetFolder(FOLDERID_PublicMusic, &pKnownFolder);
    //         if (FAILED(hr)) return filePaths;
    //         //ON_SCOPE_EXIT([&] { pKnownFolder->Release(); });
    //
    //         IShellItem *psi = NULL;
    //         hr = pKnownFolder->GetShellItem(0, IID_PPV_ARGS(&psi));
    //         if (FAILED(hr)) return filePaths;
    //         //ON_SCOPE_EXIT([&] { psi->Release(); });
    //
    //         hr = fileDlg->AddPlace(psi, FDAP_BOTTOM);
    //         COMDLG_FILTERSPEC rgSpec[] = {
    //             { L"音乐文件", L"*.mp3;*.wav;" }
    //         };
    //         fileDlg->SetFileTypes(1, rgSpec);
    //
    //         DWORD dwOptions;
    //         fileDlg->GetOptions(&dwOptions);
    //         fileDlg->SetOptions(dwOptions | FOS_ALLOWMULTISELECT);
    //         hr = fileDlg->Show(NULL);
    //         if (SUCCEEDED(hr)) {
    //             IShellItemArray *pRets;
    //             hr = fileDlg->GetResults(&pRets);
    //             if (SUCCEEDED(hr)) {
    //                 DWORD count;
    //                 pRets->GetCount(&count);
    //                 for (DWORD i = 0; i < count; i++) {
    //                     IShellItem *pRet;
    //                     LPWSTR nameBuffer;
    //                     pRets->GetItemAt(i, &pRet);
    //                     pRet->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &nameBuffer);
    //                     filePaths.push_back(std::u16string(nameBuffer));
    //                     pRet->Release();
    //                     CoTaskMemFree(nameBuffer);
    //                 }
    //                 pRets->Release();
    //             }
    //         }
    //         return filePaths;
    //     }

    static void pushStringToVector(std::vector<wchar_t>* buffer, const std::u16string& str)
    {
        for (size_t i = 0; i < str.length(); ++i) {
            buffer->push_back(str[i]);
        }
    }

    static void convertFilters(const Filters& filters, std::vector<wchar_t>* buffer)
    {
        for (size_t i = 0; i < filters.size(); ++i) {
            Filter filter = filters[i];
            std::u16string name = base::UTF8ToUTF16(filter.first);
            pushStringToVector(buffer, name);
            buffer->push_back(L'\0');

            for (size_t j = 0; j < filter.second.size(); ++j) {
                std::string extension = filter.second[j];
                std::u16string extensionW = base::UTF8ToUTF16(extension);
                extensionW.insert(0, (const char16_t*)(mbu16("*.")));
                extensionW.append((const char16_t*)(mbu16(";")));
                pushStringToVector(buffer, extensionW);
            }
            buffer->push_back(L'\0');
        }
        buffer->push_back(L'\0');
    }

    static bool showOpenOrSaveDialog(bool isOpenOrSave, HWND parentWindow, const std::string& title, const std::string& buttonLabel,
        const std::string& defaultPath, const Filters& filters, int properties, base::Value::List* paths)
    {
        std::u16string titleW = base::UTF8ToUTF16(title);
        std::u16string defaultPathW = base::UTF8ToUTF16(defaultPath);
        std::vector<wchar_t> filtersStr;

        if (properties & FILE_DIALOG_OPEN_DIRECTORY) {
            std::u16string resuleDir;
            selectDir(parentWindow, titleW, defaultPathW, &resuleDir);
            paths->Append(base::UTF16ToUTF8(resuleDir));
            return true;
        }

        convertFilters(filters, &filtersStr);

        OPENFILENAMEW ofn = { 0 };
        std::vector<char16_t> fileResult;
        fileResult.resize(4 * MAX_PATH + 1);

        ofn.lStructSize = sizeof(ofn);
        ofn.hwndOwner = parentWindow;
        ofn.lpstrFilter = &filtersStr[0]; // L"Picture File(*.bmp,*.jpg)\0*.bmp;*.jpg;\0\0";
        ofn.nFilterIndex = 1;
        ofn.lpstrFile = (WCHAR*)(fileResult.data());
        ofn.nMaxFile = 1 * MAX_PATH;
        ofn.lpstrFileTitle = nullptr; // titleW.c_str();
        ofn.nMaxFileTitle = 0; // titleW.size();
        ofn.lpstrInitialDir = (const WCHAR*)(defaultPathW.c_str());
        ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;

        if (properties & FILE_DIALOG_MULTI_SELECTIONS)
            ofn.Flags |= OFN_ALLOWMULTISELECT;

        BOOL b = isOpenOrSave ? GetOpenFileNameW(&ofn) : GetSaveFileNameW(&ofn);
        if (b) {
            splitPathFromGetOpenFileNameResult(fileResult, paths);
            return true;
        }

        if (FNERR_BUFFERTOOSMALL != CommDlgExtendedError())
            return false;

        unsigned short size = *((unsigned short*)&fileResult[0]);
        fileResult.resize(2 * size + 2);
        ofn.lpstrFile = LPWSTR(fileResult.data());
        ofn.nMaxFile = size;
        b = isOpenOrSave ? GetOpenFileNameW(&ofn) : GetSaveFileNameW(&ofn);
        if (b) {
            splitPathFromGetOpenFileNameResult(fileResult, paths);
            return true;
        }

        return false;
    }

    static void splitPathFromGetOpenFileNameResult(const std::vector<char16_t>& fileResult, base::Value::List* paths)
    {
        std::vector<std::u16string> pathsTemp;
        const char16_t* begin = &fileResult[0];
        const char16_t* end = nullptr;
        for (size_t i = 0; i < fileResult.size() - 1 && L'\0' != *begin; ++i) {
            if (L'\0' == fileResult[i]) {
                end = &fileResult[0] + i;
                if (end == begin)
                    return;

                std::u16string path(begin, end - begin);
                pathsTemp.push_back((path));

                begin = &fileResult[0] + i + 1;
            }
        }

        if (0 == pathsTemp.size())
            return;

        if (1 == pathsTemp.size())
            paths->Append(base::UTF16ToUTF8(pathsTemp[0]));

        if (2 <= pathsTemp.size()) {
            std::u16string rootPath = pathsTemp[0];
            if (1 >= rootPath.size())
                return;

            if (L'\\' != rootPath[rootPath.size() - 1])
                rootPath += L'\\';
            for (size_t i = 1; i < pathsTemp.size(); ++i) {
                std::u16string path = rootPath;
                path += pathsTemp[i];
                paths->Append(base::UTF16ToUTF8(path));
            }
        }

        return;
    }
    
    // 辅助函数：将 HRESULT 错误转换为可读信息（调试用）
    static void CheckHR(HRESULT hr, const std::string& context)
    {
        if (FAILED(hr)) {
            //_com_error err(hr);
            //std::cerr << "[" << context << "] 错误: " << err.ErrorMessage() << " (HRESULT: 0x"
            //    << std::hex << hr << ")" << std::endl;
            //throw std::runtime_error("COM 操作失败");
        }
    }

    static bool selectFolderDialog(IFileOpenDialog* pFileOpen, HWND hwndParent, std::u16string* folderPath)
    {
        // 1. 创建 IFileOpenDialog 实例

        // 2. 设置选项：只选择文件夹！
        DWORD dwOptions;
        HRESULT hr = pFileOpen->GetOptions(&dwOptions);
        CheckHR(hr, "GetOptions");
        if (FAILED(hr))
            return false;

        hr = pFileOpen->SetOptions(dwOptions | FOS_PICKFOLDERS);
        CheckHR(hr, "SetOptions(FOS_PICKFOLDERS)");
        if (FAILED(hr))
            return false;

        // 3. 可选：设置对话框标题
        hr = pFileOpen->SetTitle(L"请选择一个文件夹");
        CheckHR(hr, "SetTitle");
        if (FAILED(hr))
            return false;

        // 4. 显示对话框
        hr = pFileOpen->Show(hwndParent);
        if (hr == HRESULT_FROM_WIN32(ERROR_CANCELLED)) {
            // 用户按了“取消”
            pFileOpen->Release();
            return false;
        }
        CheckHR(hr, "Show");
        if (FAILED(hr))
            return false;

        // 5. 获取用户选择的项
        IShellItem* pItem = nullptr;
        hr = pFileOpen->GetResult(&pItem);
        CheckHR(hr, "GetResult");
        if (FAILED(hr))
            return false;

        // 6. 获取文件夹的路径
        PWSTR pszFolderPath = nullptr;
        hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFolderPath);
        CheckHR(hr, "GetDisplayName");
        if (FAILED(hr))
            return false;

        *folderPath = (const char16_t*)pszFolderPath;

        // 7. 释放资源
        CoTaskMemFree(pszFolderPath);
        pItem->Release();
        pFileOpen->Release();

        return true;
    }

    static int CALLBACK browseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
    {
        switch (uMsg) {
        case BFFM_INITIALIZED:
            ::SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);
            break;
        }

        return 0;
    }

    static unsigned selectDir(HWND parentWindow, const std::u16string& title, const std::u16string& defaultPath, std::u16string* strDir)
    {
        IFileOpenDialog* pFileOpen = nullptr;
        HRESULT hr = CoCreateInstance(
            CLSID_FileOpenDialog,
            nullptr,
            CLSCTX_INPROC_SERVER,
            IID_PPV_ARGS(&pFileOpen)
        );
        CheckHR(hr, "CoCreateInstance(IFileOpenDialog)");
        if (!(FAILED(hr))) { // win vista以上走这
            selectFolderDialog(pFileOpen, nullptr, strDir);
            return IDOK;
        }

        // 兼容xp
        std::vector<char16_t> szDir;
        szDir.resize(MAX_PATH);
        BROWSEINFO bi;
        bi.hwndOwner = parentWindow;
        bi.pidlRoot = NULL;
        bi.pszDisplayName = (LPWSTR)(szDir.data());
        bi.lpszTitle = (LPWSTR)(title.c_str());
        bi.iImage = 0;

        bi.ulFlags = BIF_USENEWUI | BIF_RETURNONLYFSDIRS;
        bi.lpfn = browseCallbackProc;
        bi.lParam = (LPARAM)(LPCWSTR)defaultPath.c_str();

        LPITEMIDLIST lp = SHBrowseForFolder(&bi);
        if (lp && SHGetPathFromIDList(lp, (LPWSTR)(szDir.data()))) {
            *strDir = &szDir[0];
            if (0 != strDir->size() && L'\\' != strDir->at(strDir->size() - 1))
                strDir->append((const char16_t*)mbu16("\\"));
            return IDOK;
        }

        return IDCANCEL;
    }

    static const int ID_COMBO_ADDR = 0x47c;
    static const int ID_LEFT_TOOBAR = 0x4A0;
    static LONG g_lOriWndProc;

    LRESULT static __stdcall _WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg) {
        case WM_COMMAND: {
            if (wParam == IDOK) {
                std::vector<wchar_t> wcDirPath;
                wcDirPath.resize(MAX_PATH);
                HWND hComboAddr = GetDlgItem(hwnd, ID_COMBO_ADDR);
                if (hComboAddr != NULL)
                    GetWindowText(hComboAddr, &wcDirPath[0], MAX_PATH);

                if (!wcslen(&wcDirPath[0]))
                    break;

                DWORD dwAttr = GetFileAttributes(&wcDirPath[0]);
                if (dwAttr != -1 && (FILE_ATTRIBUTE_DIRECTORY & dwAttr)) {
                    LPOPENFILENAMEW oFn = (LPOPENFILENAME)GetProp(hwnd, L"OPENFILENAME");
                    if (oFn) {
                        int size = oFn->nMaxFile > MAX_PATH ? MAX_PATH : oFn->nMaxFile;
                        memcpy(oFn->lpstrFile, &wcDirPath[0], size * sizeof(wchar_t));
                        ::RemoveProp(hwnd, L"OPENFILENAME");
                        ::EndDialog(hwnd, 1);
                    } else {
                        ::EndDialog(hwnd, 0);
                    }
                }
                break;
            }
            //////////////////////////////////////////////////////////////////////////
            //如果是左边toolbar发出的WM_COMMOND消息（即点击左边的toolbar）, 则清空OK按钮旁的组合框。
            HWND hCtrl = (HWND)lParam;
            if (hCtrl == NULL) {
                break;
            }
            int ctrlId = ::GetDlgCtrlID(hCtrl);
            if (ctrlId == ID_LEFT_TOOBAR) {
                HWND hComboAddr = ::GetDlgItem(hwnd, ID_COMBO_ADDR);
                if (hComboAddr != NULL) {
                    ::SetWindowTextW(hComboAddr, L"");
                }
            }
        } break;
        }
        int i = CallWindowProc((WNDPROC)g_lOriWndProc, hwnd, uMsg, wParam, lParam);
        return i;
    }

    UINT_PTR static __stdcall folderProc(HWND hdlg, UINT uiMsg, WPARAM wParam, LPARAM lParam)
    {
        //参考reactos可知，hdlg 是一个隐藏的对话框，其父窗口为打开文件对话框， OK，CANCEL按钮等控件的消息在父窗口处理。
        if (uiMsg != WM_NOTIFY)
            return 1;

        LPOFNOTIFY lpOfNotify = (LPOFNOTIFY)lParam;
        if (lpOfNotify->hdr.code == CDN_INITDONE) {
            SetPropW(GetParent(hdlg), L"OPENFILENAME", (HANDLE)(lpOfNotify->lpOFN));
            g_lOriWndProc = ::SetWindowLongW(::GetParent(hdlg), /*GWL_WNDPROC*/ (-4), (LONG)_WndProc);
        }

        if (lpOfNotify->hdr.code != CDN_SELCHANGE)
            return 1;

        std::vector<wchar_t> wcDirPath;
        wcDirPath.resize(MAX_PATH);
        CommDlg_OpenSave_GetFilePathW(::GetParent(hdlg), &wcDirPath[0], sizeof(wchar_t) * MAX_PATH);
        HWND hComboAddr = ::GetDlgItem(::GetParent(hdlg), ID_COMBO_ADDR);
        if (NULL == hComboAddr)
            return 1;

        size_t pathSize = wcslen(&wcDirPath[0]);
        if (0 != pathSize) { //去掉文件夹快捷方式的后缀名。
            if (pathSize >= 4) {
                wchar_t* wcExtension = ::PathFindExtensionW(&wcDirPath[0]);
                if (wcslen(wcExtension)) {
                    wcExtension = ::CharLowerW(wcExtension);
                    if (!wcscmp(wcExtension, L".lnk")) {
                        wcDirPath[pathSize - 4] = L'\0';
                    }
                }
            }

            ::SetWindowTextW(hComboAddr, &wcDirPath[0]);
        } else {
            ::SetWindowTextW(hComboAddr, L"");
        }

        return 1;
    }

public:
    static gin_helper::WrapperInfo kWrapperInfo;
    static v8::Persistent<v8::Function> constructor;
};

LONG Dialog::g_lOriWndProc = 0;

v8::Persistent<v8::Function> Dialog::constructor;
gin_helper::WrapperInfo Dialog::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };

static void initializeDialogApi(v8::Local<v8::Object> target, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, const NodeNative* native)
{
    Dialog::init(context->GetIsolate(), target);
}

static const char BrowserDialogNative[] = "console.log('BrowserDialogNative');"
                                          "exports = function {};";

static NodeNative nativeBrowserDialogNative { "Dialog", BrowserDialogNative, sizeof(BrowserDialogNative) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_browser_dialog, initializeDialogApi, &nativeBrowserDialogNative)

}