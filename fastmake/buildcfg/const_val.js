
const cmdstr = qfmGetCmdline();
jsPrint("cmdstr:" + cmdstr);
const cmd = JSON.parse(cmdstr);

var constValue = {
    "sdkLibPath":    "C:/cygwin64/usr/local/x86_64-unknown-linux-gnu/lib",
    "sdkPath":       "C:/cygwin64/usr/local/x86_64-unknown-linux-gnu/x86_64-unknown-linux-gnu",
    "clangPath":     "C:/Microsoft/AndroidNDK64/android-ndk-r25c/toolchains/llvm/prebuilt/windows-x86_64/bin",
    "ndkBinPath":    "C:/Microsoft/AndroidNDK64/android-ndk-r25c/toolchains/llvm/prebuilt/windows-x86_64/bin",
    "ndkIncludePath":"C:/Microsoft/AndroidNDK64/android-ndk-r25c/toolchains/llvm/prebuilt/windows-x86_64/lib64/clang/14.0.7/include",
    "ndkPath":       "C:/Microsoft/AndroidNDK64/android-ndk-r25c/toolchains/llvm/prebuilt/windows-x86_64/lib64/clang/14.0.7",
    "srcPath":       "W:/mycode/mb108",
    "targetDir":     "linux_debug_x64",
    "isDebug":       cmd.isDebug,
    "v8dir":         cmd.v8dir,
    //"sysroot":     "G:/chromium/M84/build/linux/debian_sid_amd64-sysroot",
    "sysroot":       "C:/Microsoft/AndroidNDK64/debian_sid_arm64_sysroot",
};
//constValue.linker = constValue.ndkBinPath + "/llvm-link.exe";
//constValue.linker = constValue.ndkBinPath + "/ld.lld.exe"; //x64
//constValue.linker = constValue.ndkBinPath + "/ld.gold.exe"; 
//constValue.linker = "C:/Microsoft/AndroidNDK64/android-ndk-r25c/toolchains/llvm/prebuilt/windows-x86_64/bin/ld.gold.exe";
constValue.linker = "C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/aarch64-linux-android-4.9/prebuilt/windows-x86_64/aarch64-linux-android/bin/ld.gold.exe";

constValue.isBuildElectronMode = cmd.isBuildElectronMode;
constValue.compileCfg = cmd.compileCfg;
constValue.target = "x86_64-linux-guneabi";

jsPrint("constValue.isBuildElectronMode:" + constValue.isBuildElectronMode);
jsPrint("constValue.compileCfg:" + constValue.compileCfg);

if (cmd.compileCfg == "debug") {
    constValue.targetDir = "linux_debug_x64";
} else if (cmd.compileCfg == "release" || cmd.compileCfg == "linux_release_x64") {
    constValue.targetDir = "linux_release_x64";
} else if (cmd.compileCfg == "linux_release_sym_arm64") {
    constValue.target = "aarch64-linux-guneabi"
    constValue.targetDir = cmd.compileCfg;
} else if (cmd.compileCfg == "linux_release_arm64") {
    constValue.target = "aarch64-linux-guneabi"
    constValue.targetDir = cmd.compileCfg;
} else {
    constValue.targetDir = "linux_release_sym_x64";
}

var includePaths;
if ("aarch64-linux-guneabi" == constValue.target) { // Arm 64
    constValue.sdkPath        = "C:/Microsoft/AndroidNDK64/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu";
    //constValue.clangPath      = "C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/llvm/prebuilt/windows-x86_64/bin";
    //constValue.ndkBinPath     = "C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/aarch64-linux-android-4.9/prebuilt/windows-x86_64/aarch64-linux-android/bin";
    constValue.ndkIncludePath = "C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/llvm/prebuilt/windows-x86_64/lib64/clang/5.0/include";
    
    // C:\Microsoft\AndroidNDK64\android-ndk-r16b\toolchains\arm-linux-androideabi-4.9\prebuilt\windows-x86_64\lib\gcc\arm-linux-androideabi\4.9.x\include\mmintrin.h
    includePaths = [
        "${sysroot}/usr/include/aarch64-linux-gnu/c++/10",
        //"C:/Microsoft/AndroidNDK64/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/lib/gcc/aarch64-linux-gnu/7.5.0/include",
        //"C:/Microsoft/AndroidNDK64/debian_sid_arm64_sysroot/usr/lib/clang/17/include",
        //"${sysroot}/usr/lib/gcc/aarch64-linux-gnu/10/include",
        "${sysroot}/usr/include/aarch64-linux-gnu",
        "${sysroot}/usr/include/c++/10",
        "${sysroot}/usr/include",
        "${sysroot}/usr/include/linux",
        "${sysroot}/usr/include/harfbuzz",
        "${sysroot}/usr/include/libdrm",
        "${sysroot}/usr/lib/aarch64-linux-gnu/glib-2.0/include",
        "${sdkPath}/lib/gcc/aarch64-linux-gnu/7.5.0/include",
    ];
} else {
    includePaths = [
        "${sdkPath}/include/c++/7.2.0",
        "${sdkPath}/include/c++/7.2.0/include",
        "${sdkPath}/include/c++/7.2.0/x86_64-unknown-linux-gnu/",
        "${sysroot}/usr/lib/x86_64-linux-gnu/glib-2.0/include",
        "${sdkPath}/sysroot/usr/include",
        "${sdkPath}/sysroot/usr/",
        "${sdkPath}/sysroot/usr/include/linux",
        "${sysroot}/usr/include/libdrm",
    ];
}

constValue.includePaths = [
    //"C:/Microsoft/AndroidNDK64/android-ndk-r16b/toolchains/arm-linux-androideabi-4.9/prebuilt/windows-x86_64/lib/gcc/arm-linux-androideabi/4.9.x/include", // 给ARM用的
    "${ndkIncludePath}", // 优先使用clang目录里的stddef.h、arm_neon.h，不然sysroot的这几个头文件clang会识别不了一些基本类型如'__Int8x8_t'
    ...includePaths,
    "${srcPath}",
    "${sysroot}/usr/include/cairo",
    "${sysroot}/usr/include/glib-2.0",
    "${sysroot}/usr/include/gtk-3.0",
    "${sysroot}/usr/include/gdk-pixbuf-2.0",
    "${sysroot}/usr/include/atk-1.0",
    "${sysroot}/usr/include/pango-1.0",
    "${srcPath}/linux",
];
    
export const constVal = constValue;

export const buildCommonSetting = function(json) {
    json[0].compile.objdir = json[0].compile.objdir.replace("${srcPath}", constValue.srcPath);
    json[0].compile.objdir = json[0].compile.objdir.replace("${targetDir}", constValue.targetDir);
    
    json[0].compile.cmd.push("-fPIC");
    json[0].compile.cmd.push("-fno-exceptions");
    json[0].compile.cmd.push("-fvisibility=hidden");
    json[0].compile.cmd.push("--target=" + constValue.target);
    //json[0].compile.cmd.push("-march=iwmmxt2");
    
    // gtk:
    //json[0].compile.cmd.push("-DSK_B32_SHIFT=0");
    //json[0].compile.cmd.push("-DSK_G32_SHIFT=8");
    //json[0].compile.cmd.push("-DSK_R32_SHIFT=16");
    //json[0].compile.cmd.push("-DSK_A32_SHIFT=24");
    // opengl
    json[0].compile.cmd.push("-DSK_B32_SHIFT=16");
    json[0].compile.cmd.push("-DSK_G32_SHIFT=8");
    json[0].compile.cmd.push("-DSK_R32_SHIFT=0");
    json[0].compile.cmd.push("-DSK_A32_SHIFT=24");
    
    if ("aarch64-linux-guneabi" == constValue.target) { // ARM64
        //json[0].compile.cmd.push("-mfpu=neon-fp16");
        //json[0].compile.cmd.push("-mneon-for-64bits");
        //json[0].compile.cmd.push("-mfloat-abi=hard");
    }

    if (cmd.symbolLevel == 2) { // 带符号
        json[0].compile.cmd.push("-g"); // debug core dump
        json[0].compile.cmd.push("-D_DEBUG");
        json[0].compile.cmd.push("-DDEBUG");
        json[0].compile.cmd.push("-fno-omit-frame-pointer");
        json[0].compile.cmd.push("-fstack-protector-all");
        
        //json[0].compile.cmd.push("-finline-functions");
        //json[0].compile.cmd.push("-DNDEBUG");
        //json[0].compile.cmd.push("-DENABLE_ASSERT=1");
        //json[0].compile.cmd.push("-fno-rtti");
        //json[0].compile.cmd.push("-Os");
        //json[0].compile.cmd.push("-fsanitize=address");
    } else if (cmd.symbolLevel == 1) { // 带一部分符号
        json[0].compile.cmd.push("-g"); // debug core dump
        json[0].compile.cmd.push("-DNDEBUG");
        json[0].compile.cmd.push("-fno-stack-protector");
        json[0].compile.cmd.push("-fno-omit-frame-pointer");
    } else {
        json[0].compile.cmd.push("-Os");
        //json[0].compile.linkerCmd.push("-strip-all");
        json[0].compile.cmd.push("-fomit-frame-pointer");
        json[0].compile.cmd.push("-DNDEBUG");
        //json[0].compile.cmd.push("-fno-rtti");
    }
    
    qfmRebuild(json[0].compile.objdir, JSON.stringify(json));
};