/*
 * LOCK
 * Maxime MOREILLON
 * 
 * Board type: Wemos D1 Mini
 * 
 */

// Libraries
#include "IotKernel.h"
#include <Servo.h>


// IoT Kernel params
#define DEVICE_TYPE "lock"
#define DEVICE_FIRMWARE_VERSION "0.3.0"

// Pin mapping
#define SERVO_PIN D2
#define UNLOCK_LED_PIN D7
#define LOCK_LED_PIN D8
#define BUTTON_PIN D6 // D6

// Servo
#define SERVO_UNLOCK_ANGLE 160
#define SERVO_NEUTRAL_ANGLE 90
#define SERVO_LOCK_ANGLE 10
//#define SERVO_DELAY 1
#define SERVO_INCREMENT 2



IotKernel iot_kernel(DEVICE_TYPE,DEVICE_FIRMWARE_VERSION); 
Servo servo;
boolean servo_unlock_request, servo_lock_request;

void setup() {

  // IO init
  pinMode(UNLOCK_LED_PIN,OUTPUT);
  pinMode(LOCK_LED_PIN,OUTPUT);

  button_init();
  servo_setup();
  
  iot_kernel.init();
  MQTT_config();
  web_server_config();

}


void loop() {
  
  iot_kernel.loop();
  button_read();
  handle_servo();

}
