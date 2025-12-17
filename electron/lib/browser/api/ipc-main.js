const EventEmitter = require('events').EventEmitter;

function createIpcMain() {
    var ipcMain = new EventEmitter();
    ipcMain.m_invokeHandlers = new Map();
    
    ipcMain.__origOn__ = ipcMain.on;
    ipcMain.on = function (channel, callback) {
        let cbStub = function (event, ...args) {
            if (event.innnerChannel == 'ipc-render-invoke')
                return;
            callback(event, ...args);
        }
        return ipcMain.__origOn__(channel, cbStub);
    }
    
    ipcMain.handle = function (channel, listener) { // 这里的channel是用户定义的channel
        if (ipcMain.m_invokeHandlers.has(channel)) {
            throw new Error("Attempted to register a second handler for " + channel);
        }
        if (typeof listener !== 'function') {
            throw new TypeError("Expected handler to be a function, but found type " + (typeof listener));
        }
        ipcMain.m_invokeHandlers.set(channel, listener);
        
        ipcMain.__origOn__(channel, function (event, ...args) {
            // TODO: Need channel ?
            mbConsoleLog("ipcMain.handle.on::" + channel);
            if (event.innnerChannel != 'ipc-render-invoke')
                return;
            
            var promiseOrResult = listener(/*channel,*/ event, ...args);
            var promise = promiseOrResult;
            if (!promiseOrResult || promiseOrResult.toString() != "[object Promise]") {
                promise = new Promise((resolve) => {
                    mbConsoleLog("ipcMain.on getAppVersion!" + promiseOrResult);
                    resolve(promiseOrResult);
                });
            }
            promise.then(function(result) {
                event.sender.send('ipc-main-handle-reply-' + channel, result);
            });
        });
    }
    
    ipcMain.removeHandler = function (channel /*string*/) {
        if (ipcMain.m_invokeHandlers.has(channel)) {
            let listener = ipcMain.m_invokeHandlers.get(channel);
            ipcMain.removeListener(channel, listener);
            ipcMain.m_invokeHandlers.delete(channel);
        }
    }
    
    return ipcMain;
}

var ipcMain = createIpcMain();
ipcMain.createIpcMain = createIpcMain;

module.exports = ipcMain;

// Do not throw exception when channel name is "error".
module.exports.on('error', () => {})
