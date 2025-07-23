import { constVal, buildCommonSetting } from "./const_val.js";

var json = [{
    "var":[
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
            "${srcPath}/gen/${v8dir}/include",
            "${srcPath}/${v8dir}",
            "${srcPath}/${v8dir}/include",
            "${srcPath}/third_party/zlib",
            "${srcPath}/third_party/iccjpeg",
            "${srcPath}/third_party/libjpeg_turbo",
            "${srcPath}/third_party/libwebp/src/src",
            "${srcPath}/third_party/libpng",
            "${srcPath}/third_party/harfbuzz-ng/src/src",
            "${srcPath}/third_party/khronos",
            "${srcPath}/",
            "${srcPath}/gen/",
            "${srcPath}/third_party/abseil-cpp",
            "${srcPath}/v8/include",
            "${srcPath}/third_party/skia",
            "${srcPath}/gen/v8/include",
            "${srcPath}/third_party/icu/source/i18n",
            "${srcPath}/third_party/icu/source/common",
            "${srcPath}/third_party/libxml/win32/include",
            "${srcPath}/third_party/libxml/src/include",
            "${srcPath}/third_party/libxslt/src",
            "${srcPath}/third_party/libyuv/include",
            //"${srcPath}/third_party/boringssl/src/include",
            "${srcPath}/third_party/openssl/openssl/include",
            "${srcPath}/third_party/openssl",
            "${srcPath}/gpu",
            "C:/msys64/mingw64/include/glm",
        ],
        "prebuildSrc":[
//            "${srcPath}/linux/linuxwindows.cpp",
//            "${srcPath}/linux/linuxgdi.cpp",
//            "${srcPath}/linux/testmain.cpp",
//            "${srcPath}/skia/ext/convolver_SSE2.cc",
            
            "${srcPath}/build/testdll/wkexe_linux.cpp",
            "${srcPath}/build/testdll/wkexe_linux_exp.cpp",
        ],
        "src":[
            //"${srcPath}/build/testdll/test_gtk.cpp",
            "${srcPath}/build/testdll/wkexe_linux.cpp",
            //"${srcPath}/build/testdll/wkexe_linux_exp.cpp",
            //"${srcPath}/build/testdll/gtk_gl.cpp",
            
        ],
        "cmd":[
            "-fno-exceptions",
            //"--target=x86_64-linux-guneabi", 
            "-std=c++14",
            "-fms-extensions",
            //"-fshort-wchar",
            "-D_GLIBCXX17_INLINE=inline",
            "-D_GNU_SOURCE",
            "-DUSE_AURA",
            "-DOS_LINUX_FOR_WIN",
            "-DINSIDE_BLINK",
            "-DBLINK_IMPLEMENTATION",
            "-DSK_SUPPORT_LEGACY_CREATESHADER_PTR=1",
            "-DSK_SUPPORT_LEGACY_TYPEFACE_PTR=1",
        ],
        "objdir":"${srcPath}/out/tmp/wkexe/${targetDir}",
        "outdir":"${srcPath}/out/${targetDir}",
        "target":"wkexe",
        "beginLibs":[
//            "${sysroot}/usr/lib/x86_64-linux-gnu/crt1.o",
//            "${sysroot}/usr/lib/x86_64-linux-gnu/crti.o",
//            "${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/crtbegin.o",
//            "${sysroot}/usr/lib/x86_64-linux-gnu/libc_nonshared.a",
//            "${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/libgcc_eh.a",
//            "${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/libgcc.a",
//            "${sysroot}/usr/lib/x86_64-linux-gnu/libffi.a"
        ],
        "linkerCmd":[
//            "-strip-all",
//            //"-dynamic-linker /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2",
//            "-dynamic-linker /lib64/ld-linux-x86-64.so.2",
//            "-l${sysroot}/lib/x86_64-linux-gnu/libc-2.27.so",
//            "-l${sysroot}/usr/lib/x86_64-linux-gnu/libglib-2.0.so.0.6200.3",
//            "-l${sysroot}/usr/lib/x86_64-linux-gnu/libgtk-3.so.0.2404.9",
//            "-l${sysroot}/usr/lib/x86_64-linux-gnu/libgdk-3.so.0.2404.9",
//            "-l${sysroot}/usr/lib/x86_64-linux-gnu/libcairo.so.2.11600.0",
//            "-l${sysroot}/usr/lib/x86_64-linux-gnu/libpthread.so",
//            //"-l${sysroot}/usr/lib/x86_64-linux-gnu/libpcreposix.so.3.13.3",
//            "-l${sysroot}/usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.28",
//            "-l${sysroot}/usr/lib/x86_64-linux-gnu/libgobject-2.0.so.0.6200.3",
//            "-l${sdkPath}/sysroot/lib/libdl.so.2",
//            "-l${sdkPath}/sysroot/lib/libgcc_s.so.1",
//            "-l${sysroot}/lib/x86_64-linux-gnu/libm-2.27.so"
            ],
        "endLibs":[
//            "${sysroot}/usr/lib/x86_64-linux-gnu/crtn.o",
//            "${sysroot}/usr/lib/gcc/x86_64-linux-gnu/7/crtend.o"
        ],
        "linker":constVal.linker//"${ndkBinPath}/ld.gold.exe"
    }
}];


var endLibs = [];

if ("aarch64-linux-guneabi" == constVal.target) { // ARM64
    json[0].compile.linkerCmd = [
        //"-z defs",
        //"-fPIC",
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
        "-L C:/Microsoft/AndroidNDK64/debian_sid_arm64_sysroot/lib/x86_64-linux-gnu",
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
        "--library=gio-2.0",
        //"--library=gcc_s.so.1",
        "--library=m-2.27",
        //"--library=C:/Microsoft/AndroidNDK64/android-ndk-r25c/toolchains/llvm/prebuilt/windows-x86_64/sysroot/usr/lib/x86_64-linux-android/33/libGLESv2.so",
        "--library=G:/chromium/M84/build/linux/debian_sid_amd64-sysroot/usr/lib/x86_64-linux-gnu/libGL.so.1.7.0",
        //"--library=atomic.so.1.2.0",
        //"P:/chromium/cef111linux/third_party/llvm-build/Release+Asserts/lib/clang/16/lib/x86_64-unknown-linux-gnu/libclang_rt.asan.a",
    ];
        
    json[0].compile.beginLibs = [
        "P:/chromium/M84-/build/linux/debian_sid_amd64-sysroot/usr/lib/x86_64-linux-gnu/crt1.o",
        "P:/chromium/M84-/build/linux/debian_sid_amd64-sysroot/usr/lib/x86_64-linux-gnu/crti.o",
        "P:/chromium/M84-/build/linux/debian_sid_amd64-sysroot/usr/lib/x86_64-linux-gnu/libc_nonshared.a",
        "C:/cygwin64/usr/local/x86_64-unknown-linux-gnu/lib/gcc/x86_64-unknown-linux-gnu/7.2.0/libgcc_eh.a",
        "C:/cygwin64/usr/local/x86_64-unknown-linux-gnu/lib/gcc/x86_64-unknown-linux-gnu/7.2.0/libgcc.a",
        "G:/chromium/M84/build/linux/debian_sid_amd64-sysroot/usr/lib/x86_64-linux-gnu/libffi.a"
    ];
    json[0].compile.endLibs.push("P:/chromium/M84-/build/linux/debian_sid_amd64-sysroot/usr/lib/x86_64-linux-gnu/crtn.o");
    json[0].compile.endLibs.push("P:/chromium/M84-/build/linux/debian_sid_amd64-sysroot/usr/lib/gcc/x86_64-linux-gnu/7/crtend.o");
}


if ("aarch64-linux-guneabi" == constVal.target) // ARM64
    json[0].compile.beginLibs.push("${sysroot}/usr/lib/gcc/aarch64-linux-gnu/10/crtbeginS.o");
else
    json[0].compile.beginLibs.push("P:/chromium/M84-/build/linux/debian_sid_amd64-sysroot/usr/lib/gcc/x86_64-linux-gnu/7/crtbeginS.o");

json[0].compile.target = "wkexe";
//json[0].compile.linkerCmd.push("-shared");


buildCommonSetting(json);
