# lock

Wifi enabled door lock that can be controlled via either MQTT or HTTP.

## Video:
[![Alt text](https://img.youtube.com/vi/oReezruJR1E/0.jpg)](https://www.youtube.com/watch?v=oReezruJR1E)

## Parts list
* Wemos D1 Mini
* MG996R servo
* 2x Limit switch
* 2x LED + resistor

## Schematic
![alt text](https://moreillon.duckdns.org/projects/iot/images/lock_schematic.png)

## Requirements
* Arduino IDE with [support for ESP8266](https://github.com/esp8266/Arduino)
* [Async MQTT client](https://github.com/marvinroger/async-mqtt-client)
* [ESPAsyncTCP](https://github.com/me-no-dev/ESPAsyncTCP)
