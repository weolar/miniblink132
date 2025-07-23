const EventEmitter = require('events')
const { IpcMainImpl } = require('events');
//import { MessagePortMain } from '@electron/internal/browser/message-port-main';

const binding = process._linkedBinding('electron_browser_web_frame_main');
const WebFrameMain = binding.WebFrameMain;
const fromId = binding.fromId;

Object.setPrototypeOf(WebFrameMain.prototype, EventEmitter.prototype); // 把on之类的函数绑定过来

//Object.defineProperty(WebFrameMain.prototype, 'ipc', {
//    get() {
//        const ipc = new IpcMainImpl();
//        Object.defineProperty(this, 'ipc', {
//            value: ipc
//        });
//        return ipc;
//    }
//});

WebFrameMain.prototype.send = function(channel, ...args) {
    if (typeof channel !== 'string') {
        throw new TypeError('Missing required channel argument');
    }

    try {
        return this._send(false /* internal */ , channel, args);
    } catch (e) {
        console.error('Error sending from webFrameMain: ', e);
    }
};

WebFrameMain.prototype._sendInternal = function(channel, ...args) {
    if (typeof channel !== 'string') {
        throw new TypeError('Missing required channel argument');
    }

    try {
        return this._send(true /* internal */ , channel, args);
    } catch (e) {
        console.error('Error sending from webFrameMain: ', e);
    }
};

WebFrameMain.prototype.postMessage = function(...args) {
    if (Array.isArray(args[2])) {
        args[2] = args[2].map(o => o instanceof MessagePortMain ? o._internalPort : o);
    }
    this._postMessage(...args);
};

//process.WebFrameMain = WebFrameMain;
//module.exports = new WebFrameMain();
module.exports = {
    "webFrameMain": {
        "fromId": fromId
    }
};
