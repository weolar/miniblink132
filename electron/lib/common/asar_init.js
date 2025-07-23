;(function () {
    return function (process, require, asarSource) {
        
        // Make asar.js accessible via "require".
        //process.binding('natives').ELECTRON_ASAR = asarSource; // move to -> third_party\libnode\src\node_builtins.cc
        //mbConsoleLog("asar_init.js 00000");
        
        try {
            // Monkey-patch the fs module.
            require('ELECTRON_ASAR').wrapFsWithAsar(require('fs'));
            //mbConsoleLog("asar_init.js 1111");
            
            // Make graceful-fs work with asar.
            var source = process.binding('natives');
            source['original-fs'] = source.fs;
            //mbConsoleLog("asar_init.js ok");
            
            source['fs'] = `
var nativeModule = new process.NativeModule('original-fs')
nativeModule.cache()
nativeModule.compile()
var asar = require('ELECTRON_ASAR')
asar.wrapFsWithAsar(nativeModule.exports)
module.exports = nativeModule.exports`;
            
        } catch(e) {
            mbConsoleLog("asar_init.js fail: " + e);
        }
    }
})()

