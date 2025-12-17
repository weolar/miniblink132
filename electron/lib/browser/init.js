'use strict';

require('./electron.js');
const fs = require('fs');
const path = require('path');
const util = require('util');
const Module = require('module');
const v8 = require('v8');
const app = require('electron').app;

// Import common settings. 
require('./../common/init.js');
require('./rpc-server.js');

if (typeof module!== 'undefined' && module.exports) {
    mbConsoleLog("is_module_js!!");
} else {
    mbConsoleLog("not is_module_js!!");
}

/*
let packageJson = null;
let packagePath = __dirname + '/../../app.asar/'; //__dirname + '/../default_app/';
if (!fs.existsSync(packagePath))
    packagePath = __dirname + '/../default_app/';
packageJson = require(packagePath + 'package.json');
*/
let packageJson = null;
let packagePath = null;
const searchPaths = ['/../default_app/', 'app', 'app.asar', 'default_app.asar']
for (packagePath of searchPaths) {
    try {
        packagePath = path.join(__dirname, packagePath)
        packageJson = require(path.join(packagePath, 'package.json'))
        break
    } catch (error) {
        continue
    }
}

if (packageJson == null) {
    process.nextTick(function () {
        return process.exit(1);
    })
    throw new Error('Unable to find a valid app')
}

// Set application's version.
if (packageJson.version != null) {
    app.setVersion(packageJson.version);
}

// Set application's name.
if (packageJson.productName != null) {
    app.setName(packageJson.productName)
} else if (packageJson.name != null) {
    app.setName(packageJson.name);
}

// Set application's desktop name.
if (packageJson.desktopName != null) {
    app.setDesktopName(packageJson.desktopName);
} else {
    app.setDesktopName((app.getName()) + '.desktop');
}

// Set v8 flags
if (packageJson.v8Flags != null) {
    v8.setFlagsFromString(packageJson.v8Flags);
}

// Set the user path according to application's name.
app.setPath('userData', path.join(app.getPath('appData'), app.getName()));
app.setPath('userCache', path.join(app.getPath('cache'), app.getName()));
app.setAppPath(packagePath);

// Don't quit on fatal error.
process.on('uncaughtException', function (error) {
    // Do nothing if the user has a custom uncaught exception handler.
    if (process.listenerCount('uncaughtException') > 1) {
        return;
    }

    // Show error in GUI.
    // We can't import { dialog } at the top of this file as this file is
    // responsible for setting up the require hook for the "electron" module
    // so we import it inside the handler down here
    
    //import('electron').then(({ dialog }) => {
    //    const stack = error.stack ? error.stack : `${error.name}: ${error.message}`;
    //    const message = 'Uncaught Exception:\n' + stack;
    //    dialog.showErrorBox('A JavaScript error occurred in the main process', message);
    //});
    
    const stack = error.stack ? error.stack : `${error.name}: ${error.message}`;
    const message = "Uncaught Exception:\n" + stack;
    console.log("A JavaScript error occurred in the main process, " + message);
});

// Set main startup script of the app.
const mainStartupScript = packageJson.main || 'index.js';

// Finally load app's main.js and transfer control to C++.
Module._load(path.join(packagePath, mainStartupScript), Module, true);

setImmediate(function() {
    try {
        app._setIsReady();
        app.emit('will-finish-launching', {});
        app.emit('ready', {});
    } catch(e) {
        console.log("browser/init.js, app.ready fail::" + e + ", \n" + e.stack);
    }
});
