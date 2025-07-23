import { constVal, buildCommonSetting } from "./const_val.js";

var json = [{
    "var":[
        {"sdkLibPath":constVal.sdkLibPath},
        {"sdkPath":constVal.sdkPath},
        {"clangPath":constVal.clangPath},
        {"srcPath":constVal.srcPath},
        {"ndkIncludePath":constVal.ndkIncludePath},
        {"ndkBinPath":constVal.ndkBinPath},
        {"v8dir": constVal.v8dir},
        {"targetDir": constVal.targetDir},
        {"sysroot": constVal.sysroot},
        
    ],
    "compile":{
        "ccompiler":"${clangPath}/clang.exe",
        "cppcompiler":"${clangPath}/clang++.exe",
            
        "include":[
            ...constVal.includePaths,
            "${srcPath}/third_party/harfbuzz-ng/src/src", // for C:/Microsoft/AndroidNDK64/debian_sid_arm64_sysroot/usr/include/pango-1.0/pango/pango-coverage.h(28)::: fatal error: 'hb.h'
        ],
        "prebuildSrc":[            
            //"${srcPath}/wkexe/vip/wkexe_linux.cpp",
            //"${srcPath}/wkexe/vip/wkexe_linux_exp.cpp",
            "${srcPath}/webdriver/MBCommandExecutor.cpp",
            "${srcPath}/webdriver/WebDriverMain.cpp",
            "${srcPath}/linux/linuxwindows.cpp",
        ],
        "src":[
            "${srcPath}/linux/linuxwindows.cpp",
            //"${srcPath}/linux/linuxgdi.cpp",
            "${srcPath}/patch_code/atomic_xp.cpp",
            "${srcPath}/webdriver/WebDriverMain.cpp",
            "${srcPath}/webdriver/MBServer.cpp",
            "${srcPath}/webdriver/MBSession.cpp",
            "${srcPath}/webdriver/MBCommandExecutor.cpp",
            "${srcPath}/webdriver/MBCommandHandler.cpp",
            "${srcPath}/webdriver/server/precompile.cpp",
            "${srcPath}/webdriver/server/command.cpp",
            "${srcPath}/webdriver/server/response.cpp",
            "${srcPath}/webdriver/server/ServerCivetweb.cpp",
            "${srcPath}/webdriver/server/uri_info.cpp",
            "${srcPath}/webdriver/jsoncpp/jsoncpp.cpp",
            "${srcPath}/webdriver/civetweb/civetweb.c",
            "${srcPath}/webdriver/StringUtilities.cpp",
            "${srcPath}/webdriver/js.cpp",
            "${srcPath}/webdriver/atoms.cpp",
            "${srcPath}/webdriver/CommandHandlerRepository.cpp",
            "${srcPath}/webdriver/CommandLineArguments.cpp",
            "${srcPath}/webdriver/CommandHandlers/ElementUtil.cpp",
            "${srcPath}/webdriver/CommandHandlers/NewSessionCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GoToUrlCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/SendKeysCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/ClickElementCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GoForwardCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GoBackCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/RefreshCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/ExecuteScriptCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetTitleCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetElementAttributeCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetTimeoutsCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetCurrentWindowHandleCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/CloseWindowCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/SwitchToWindowCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetAllWindowHandlesCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/CreateNewWindowCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/SetWindowRectCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/ExecuteAsyncScriptCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/ReleaseActionsCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/ScreenshotCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/SetTimeoutsCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetAlertTextCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/AcceptAlertCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/DismissAlertCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/QuitCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/ElementEqualsCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/FindChildElementCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/FindChildElementsCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/FindElementCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/FindElementsCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetCurrentUrlCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetElementPropertyCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetElementRectCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetElementTagNameCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetElementTextCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetElementValueOfCssPropertyCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetWindowRectCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/SwitchToParentFrameCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/SwitchToFrameCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/MaximizeWindowCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/MinimizeWindowCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/GetPageSourceCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/IsElementSelectedCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/IsElementEnabledCommandHandler.cpp",
            "${srcPath}/webdriver/CommandHandlers/IsElementDisplayedCommandHandler.cpp",
        ],
        "cmd":[
            //"-march=armv8.1-a",
            "-fno-exceptions",
            //"--target=x86_64-linux-guneabi", 
            "-std=c++17",
            "-fms-extensions",
            "-Dunix=1",
            "-D_GLIBCXX17_INLINE=inline",
            "-D_GNU_SOURCE",
            "-DUSE_AURA",
            "-DOS_LINUX_FOR_WIN",
        ],
        "objdir":"${srcPath}/out/tmp/wkexe/${targetDir}",
        "outdir":"${srcPath}/out/${targetDir}",
        "target":"chromedriver",
        "beginLibs":[
            //"${sysroot}/usr/lib/x86_64-linux-gnu/crt1.o",
            //"${sysroot}/usr/lib/x86_64-linux-gnu/crti.o",
            //"${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/crtbegin.o",
            //"${sysroot}/usr/lib/x86_64-linux-gnu/libc_nonshared.a",
            //"${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/libgcc_eh.a",
            //"${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/libgcc.a",
            //"${sysroot}/usr/lib/x86_64-linux-gnu/libffi.a",
            
            "${sysroot}/usr/lib/aarch64-linux-gnu/crt1.o",
            "${sysroot}/usr/lib/aarch64-linux-gnu/crti.o",
            "${sysroot}/usr/lib/gcc/aarch64-linux-gnu/10/crtbegin.o",
            "${sysroot}/usr/lib/aarch64-linux-gnu/libc_nonshared.a",
            "${sysroot}/usr/lib/gcc/aarch64-linux-gnu/10/libgcc_eh.a",
            "${sysroot}/usr/lib/gcc/aarch64-linux-gnu/10/libgcc.a",
            "${sysroot}/usr/lib/aarch64-linux-gnu/libffi.a"
        ],
        "linkerCmd":[
            "-strip-all",
            //"-dynamic-linker /lib64/ld-linux-x86-64.so.2",
            //"-l${sysroot}/lib/x86_64-linux-gnu/libc-2.27.so",
            //"-l${sysroot}/usr/lib/x86_64-linux-gnu/libglib-2.0.so.0.6200.3",
            //"-l${sysroot}/usr/lib/x86_64-linux-gnu/libgtk-3.so.0.2404.9",
            //"-l${sysroot}/usr/lib/x86_64-linux-gnu/libgdk-3.so.0.2404.9",
            //"-l${sysroot}/usr/lib/x86_64-linux-gnu/libcairo.so.2.11600.0",
            //"-l${sysroot}/usr/lib/x86_64-linux-gnu/libpthread.so",
            //"-l${sysroot}/usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.28",
            //"-l${sysroot}/usr/lib/x86_64-linux-gnu/libgobject-2.0.so.0.6200.3",
            //"-lC:/cygwin64/usr/local/x86_64-unknown-linux-gnu/x86_64-unknown-linux-gnu/sysroot/lib/libdl.so.2",
            //"-lC:/cygwin64/usr/local/x86_64-unknown-linux-gnu/x86_64-unknown-linux-gnu/sysroot/lib/libgcc_s.so.1",
            //"-l${sysroot}/lib/x86_64-linux-gnu/libm-2.27.so"
            
            //"-dynamic-linker /lib64/ld-linux-x86-64.so.2",
            //"-l${sdkPath}/aarch64-linux-gnu/libc/lib/libc-2.25.so",
            //"-l${sysroot}/usr/lib/aarch64-linux-gnu/libglib-2.0.so.0.6600.7",
            //"-l${sysroot}/usr/lib/aarch64-linux-gnu/libgtk-3.so.0.2404.20",
            //"-l${sysroot}/usr/lib/aarch64-linux-gnu/libgdk-3.so.0.2404.20",
            //"-l${sysroot}/usr/lib/aarch64-linux-gnu/libcairo.so.2.11600.0",
            //"-l${sysroot}/usr/lib/aarch64-linux-gnu/libpthread.so",
            //"-l${sysroot}/usr/lib/aarch64-linux-gnu/libstdc++.so.6.0.28",
            //"-l${sysroot}/usr/lib/aarch64-linux-gnu/libgobject-2.0.so.0.6600.7",
            //"-l${sdkPath}/aarch64-linux-gnu/libc/lib/libdl.so.2",
            //"-l${sdkPath}/aarch64-linux-gnu/lib64/libgcc_s.so.1",
            //"-l${sysroot}/lib/aarch64-linux-gnu/libm-2.31.so"
            ],
        "endLibs":[
            //"${sysroot}/usr/lib/x86_64-linux-gnu/crtn.o",
            //"${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/crtend.o"
            
            //"${sdkPath}/aarch64-linux-gnu/libc/usr/lib/crtn.o",
            //"${sdkPath}/lib/gcc/aarch64-linux-gnu/7.5.0/crtend.o"
        ],
        "linker":constVal.linker//"${ndkBinPath}/ld.gold.exe"
    }
}];


var endLibs = [];

if ("aarch64-linux-guneabi" == constVal.target) { // ARM64
    json[0].compile.linkerCmd = [
        "-dynamic-linker /usr/lib/ld-linux-aarch64.so.1",
        "-l${sysroot}/lib/aarch64-linux-gnu/libc-2.31.so",
        "-l${sysroot}/usr/lib/aarch64-linux-gnu/libglib-2.0.so.0.6600.7",
        "-l${sysroot}/usr/lib/aarch64-linux-gnu/libgtk-3.so.0.2404.20",
        "-l${sysroot}/usr/lib/aarch64-linux-gnu/libgdk-3.so.0.2404.20",
        "-l${sysroot}/usr/lib/aarch64-linux-gnu/libcairo.so.2.11600.0",
        "-l${sysroot}/usr/lib/aarch64-linux-gnu/libpthread.so",
        "-l${sysroot}/usr/lib/aarch64-linux-gnu/libstdc++.so.6.0.28",
        "-l${sysroot}/usr/lib/aarch64-linux-gnu/libgobject-2.0.so.0.6600.7",
        "-l${sdkPath}/aarch64-linux-gnu/libc/lib/libdl.so.2",
        "-l${sdkPath}/aarch64-linux-gnu/libc/lib/libgcc_s.so.1",
        "-l${sysroot}/lib/aarch64-linux-gnu/libm-2.31.so"];
        
    json[0].compile.beginLibs = [
        "${sysroot}/usr/lib/aarch64-linux-gnu/crt1.o",
        "${sysroot}/usr/lib/aarch64-linux-gnu/crti.o",
        "${sysroot}/usr/lib/aarch64-linux-gnu/libc_nonshared.a",
        "${sysroot}/usr/lib/gcc/aarch64-linux-gnu/10/libgcc_eh.a",
        "${sysroot}/usr/lib/gcc/aarch64-linux-gnu/10/libgcc.a",
        "${sysroot}/usr/lib/aarch64-linux-gnu/libffi.a"
    ];

    json[0].compile.endLibs.push("${sysroot}/usr/lib/aarch64-linux-gnu/crtn.o");
    json[0].compile.endLibs.push("${sysroot}/usr/lib/gcc/aarch64-linux-gnu/10/crtend.o");
} else {  // X64
    json[0].compile.linkerCmd = [
        //"-LD:/usr/lib/gcc/i586-linux-gnu/4.9",
        //"-LD:/usr/lib/i386-linux-gnu",
        //"-strip-all",
        "-z defs",
        "-dynamic-linker /lib64/ld-linux-x86-64.so.2",
        "-L ${sysroot}/lib/x86_64-linux-gnu",
        //"-error-limit=0",
        //"-pthread",
        "--library=c-2.27",
        "--library=glib-2.0.so.0.6200.3",
        "--library=gtk-3.so.0.2404.9",
        "--library=gdk-3.so.0.2404.9",
        "--library=cairo.so.2.11600.0",
        "--library=pthread-2.29",
        "--library=stdc++.so.6.0.28",
        "--library=gobject-2.0.so.0.6200.3",
        "--library=dl-2.29",
        //"--library=gcc_s.so.1",
        "--library=m-2.27",
        //"--library=C:/Microsoft/AndroidNDK64/android-ndk-r25c/toolchains/llvm/prebuilt/windows-x86_64/sysroot/usr/lib/x86_64-linux-android/33/libGLESv2.so",
        "--library=${sysroot}/usr/lib/x86_64-linux-gnu/libGL.so.1.7.0",
        //"--library=atomic.so.1.2.0",
        //"P:/chromium/cef111linux/third_party/llvm-build/Release+Asserts/lib/clang/16/lib/x86_64-unknown-linux-gnu/libclang_rt.asan.a",
    ];
        
    json[0].compile.beginLibs = [
        "${sysroot}/usr/lib/x86_64-linux-gnu/crt1.o",
        "${sysroot}/usr/lib/x86_64-linux-gnu/crti.o",
        "${sysroot}/usr/lib/x86_64-linux-gnu/libc_nonshared.a",
        "${sdkLibPath}/gcc/x86_64-unknown-linux-gnu/7.2.0/libgcc_eh.a",
        "${sdkLibPath}/gcc/x86_64-unknown-linux-gnu/7.2.0/libgcc.a",
        "${sysroot}/usr/lib/x86_64-linux-gnu/libffi.a"
    ];
    json[0].compile.endLibs.push("${sysroot}/usr/lib/x86_64-linux-gnu/crtn.o");
    json[0].compile.endLibs.push("${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/crtend.o");
}

// 默认编译成electron，带参数则编译成so
//if (!constVal.isBuildElectronMode) {
//    json[0].compile.target = "miniblink.so";
//    json[0].compile.cmd.push("-shared");
//}

buildCommonSetting(json);
