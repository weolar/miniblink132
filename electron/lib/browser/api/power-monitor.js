const EventEmitter = require('events').EventEmitter;
const binding = process._linkedBinding('electron_browser_powermonitor');
const ApiPowerMonitor = binding.ApiPowerMonitor;

//function PowerMonitor () {
//    
//}


Object.setPrototypeOf(ApiPowerMonitor.prototype, EventEmitter.prototype);

ApiPowerMonitor.prototype.getSwitchValue22 = function (message) {
    //return this._send(message);
    mbConsoleLog("PowerMonitor.prototype.getSwitchValue");
}

module.exports = new ApiPowerMonitor();