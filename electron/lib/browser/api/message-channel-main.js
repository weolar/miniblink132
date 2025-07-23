const MessagePortMain = require('./message-port-main.js');
const EventEmitter = require('events').EventEmitter;
const binding = process._linkedBinding('electron_browser_message_port');
const createPair = binding.createPair;

function MessageChannelMain() {
    const { port1, port2 } = createPair();
    this.port1 = new MessagePortMain(port1);
    this.port2 = new MessagePortMain(port2);
}

Object.setPrototypeOf(MessageChannelMain.prototype, EventEmitter.prototype);


module.exports.MessageChannelMain = MessageChannelMain;