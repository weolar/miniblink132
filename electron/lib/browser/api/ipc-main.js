const EventEmitter = require('events').EventEmitter;

function createIpcMain() {
    var ipcMain = new EventEmitter();
    ipcMain.m_invokeHandlers = new Map();
     
    ipcMain.handle = function (channel, listener) {
        if (ipcMain.m_invokeHandlers.has(channel)) {
            throw new Error("Attempted to register a second handler for " + method);
        }
        if (typeof listener !== 'function') {
            throw new TypeError("Expected handler to be a function, but found type " + (typeof listener));
        }
        ipcMain.m_invokeHandlers.set(channel, listener);
        
        ipcMain.on(channel, function (event, ...args) {
            // TODO: Need channel ?
            var promise = listener(/*channel,*/ event, ...args);
            if (!promise || promise.toString() != "[object Promise]")
                return;
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
