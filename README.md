# lock

Wifi enabled door lock that can be controlled via either MQTT or HTTP requests.

## Video:
[![Alt text](https://img.youtube.com/vi/oReezruJR1E/0.jpg)](https://www.youtube.com/watch?v=oReezruJR1E)

## Requirements
* Arduino IDE with [support for ESP8266](https://github.com/esp8266/Arduino)
* [Async MQTT client](https://github.com/marvinroger/async-mqtt-client)
* [ESPAsyncTCP](https://github.com/me-no-dev/ESPAsyncTCP)

## Hardware
### Parts list
* Wemos D1 Mini
* MG996R servo
* 2x Limit switch
* 2x LED + resistor
* Screws and standoffs

### Schematic
![alt text](https://img.maximemoreillon.com/images/609493e243b2829ef4abca38)

### 3D printed parts
STL files available on [Thingiverse](https://www.thingiverse.com/thing:2462482)

## Notes
* For applications without limit switches, please see the no_limit_switches branch of this repository.
