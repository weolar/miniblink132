import { constVal, buildCommonSetting } from "./const_val.js";

var json = [{
    "var":[
        {"sdkPath":constVal.sdkPath},
        {"clangPath":constVal.clangPath},
        {"srcPath":constVal.srcPath},
        {"ndkIncludePath":constVal.ndkIncludePath},
        {"ndkBinPath":constVal.ndkBinPath},
        {"targetDir": constVal.targetDir},
        {"sysroot": constVal.sysroot},
    ],
    "compile":{
        "ccompiler":"${clangPath}/clang.exe",
        "cppcompiler":"${clangPath}/clang++.exe",
            
        "include":[
//            "${sdkPath}/include/c++/7.2.0",
//            "${sdkPath}/include/c++/7.2.0/include",
//            //"C:/cygwin64/usr/local/x86_64-unknown-linux-gnu/lib/gcc/x86_64-unknown-linux-gnu/7.2.0/include", // sse is compile error
//            "${ndkIncludePath}",
//            "${sdkPath}/include/c++/7.2.0/x86_64-unknown-linux-gnu/",
//            "${srcPath}",
//            "${sdkPath}/sysroot/usr/include",
//            "${sdkPath}/sysroot/usr/",
//            "${sdkPath}/sysroot/usr/include/linux",
            ...constVal.includePaths,
            "${srcPath}/linux",
            "${srcPath}/third_party/freetype/src/include"
        ],
        "prebuildSrc":[
            "${srcPath}/third_party/freetype/src/src/winfonts/winfnt.c"
        ],
        "src":[
            "${srcPath}/third_party/freetype/src/src/winfonts/winfnt.c",
            "${srcPath}/third_party/freetype/src/src/autofit/autofit.c",
            "${srcPath}/third_party/freetype/src/src/bdf/bdf.c",
            "${srcPath}/third_party/freetype/src/src/cache/ftcache.c",
            "${srcPath}/third_party/freetype/src/src/cff/cff.c",
            "${srcPath}/third_party/freetype/src/src/cid/type1cid.c",
            "${srcPath}/third_party/freetype/src/src/gzip/ftgzip.c",
            "${srcPath}/third_party/freetype/src/src/lzw/ftlzw.c",
            "${srcPath}/third_party/freetype/src/src/pfr/pfr.c",
            "${srcPath}/third_party/freetype/src/src/pcf/pcf.c",
            "${srcPath}/third_party/freetype/src/src/psaux/psaux.c",
            "${srcPath}/third_party/freetype/src/src/pshinter/pshinter.c",
            "${srcPath}/third_party/freetype/src/src/psnames/psmodule.c",
            "${srcPath}/third_party/freetype/src/src/raster/raster.c",
            "${srcPath}/third_party/freetype/src/src/sfnt/sfnt.c",
            "${srcPath}/third_party/freetype/src/src/smooth/smooth.c",
            "${srcPath}/third_party/freetype/src/src/truetype/truetype.c",
            "${srcPath}/third_party/freetype/src/src/type1/type1.c",
            "${srcPath}/third_party/freetype/src/src/type42/type42.c",
            "${srcPath}/third_party/freetype/src/src/base/ftbase.c",
            "${srcPath}/third_party/freetype/src/src/base/ftinit.c",
            "${srcPath}/third_party/freetype/src/src/base/ftsystem.c",
            "${srcPath}/third_party/freetype/src/src/base/ftdebug.c",
            "${srcPath}/third_party/freetype/src/src/base/ftbbox.c",
            "${srcPath}/third_party/freetype/src/src/base/ftbdf.c",
            "${srcPath}/third_party/freetype/src/src/base/ftbitmap.c",
            "${srcPath}/third_party/freetype/src/src/base/ftcid.c",
            "${srcPath}/third_party/freetype/src/src/base/ftfstype.c",
            "${srcPath}/third_party/freetype/src/src/base/ftgasp.c",
            "${srcPath}/third_party/freetype/src/src/base/ftglyph.c",
            "${srcPath}/third_party/freetype/src/src/base/ftgxval.c",
            "${srcPath}/third_party/freetype/src/src/base/ftmm.c",
            "${srcPath}/third_party/freetype/src/src/base/ftotval.c",
            "${srcPath}/third_party/freetype/src/src/base/ftpatent.c",
            "${srcPath}/third_party/freetype/src/src/base/ftpfr.c",
            "${srcPath}/third_party/freetype/src/src/base/ftstroke.c",
            "${srcPath}/third_party/freetype/src/src/base/ftsynth.c",
            "${srcPath}/third_party/freetype/src/src/base/fttype1.c",
            "${srcPath}/third_party/freetype/src/src/base/ftobjs.c",
            "${srcPath}/third_party/freetype/src/src/base/ftmm.c",
            "${srcPath}/third_party/freetype/src/src/base/ftwinfnt.c"
        ],
        // 
        "cmd":[
            "-fno-exceptions",
            "-fms-extensions",
            //"-fPIC",
            "-D_GNU_SOURCE",
            "-DUSE_AURA",
            "-DOS_LINUX_FOR_WIN",
            "-DFT_DEBUG_LEVEL_ERROR",
            "-DFT_DEBUG_LEVEL_TRACE",
            "-DFT2_BUILD_LIBRARY",
            "-DCHROMIUM_RESTRICT_VISIBILITY",
        ],
        "objdir":"${srcPath}/out/tmp/freetype/${targetDir}",
        "outdir":"${srcPath}/out/${targetDir}",
        "target":"libfreetype.a",
        "beginLibs":[
        ],
        "linkerCmd":[],
        "endLibs":[
        ],
        "linker":"${ndkBinPath}/llvm-ar.exe"
    }
}];

buildCommonSetting(json);
