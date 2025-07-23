const EventEmitter = require('events').EventEmitter;

function MessagePortMain(internalPort) {
    this._internalPort = internalPort;
    this._internalPort.emit = (channel/*: string*/, event/*: {ports: any[]}*/) => {
        if (channel === 'message') { 
            event = { ...event, ports: event.ports.map(p => new MessagePortMain(p)) }; 
        }
        this.emit(channel, event);
    };
}

MessagePortMain.prototype.start = function() {
    return this._internalPort.start();
}

MessagePortMain.prototype.close = function() {
    return this._internalPort.close();
}

MessagePortMain.prototype.postMessage = function(msg, ports) {
    if (Array.isArray(ports)) {
        ports = ports.map((o) => {o instanceof MessagePortMain ? o._internalPort : o});
        return this._internalPort.postMessage(msg, ports);
    }
    return this._internalPort.postMessage(msg);
}

Object.setPrototypeOf(MessagePortMain.prototype, EventEmitter.prototype);

module.exports = MessagePortMain;