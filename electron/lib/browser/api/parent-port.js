const EventEmitter = require('events').EventEmitter;
const MessagePortMain = require('./message-port-main.js');
const binding = process._linkedBinding('electron_browser_parent_port');
const ParentPort = binding.ParentPort;

if (!ParentPort)
    return;

Object.setPrototypeOf(ParentPort.prototype, EventEmitter.prototype); // 把on之类的函数绑定过来

ParentPort.prototype.postMessage = function (message) {
    return this._send(message);
}

// look: \electron\lib\utility\parent-port.ts
var origEmit = ParentPort.prototype.emit;
ParentPort.prototype.emit = function(channel/*: string | symbol*/, event/*: { ports: any[] }*/) {
    if (channel === 'message') {
        event = { ...event, ports: event.ports.map(p => new MessagePortMain(p)) };
    }
    origEmit.call(this, channel, event);
    return false;
}

process.parentPort = new ParentPort(true);