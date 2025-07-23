'use strict'

const contextBridge = process._linkedBinding('electron_renderer_contextbridge');
module.exports = contextBridge;
