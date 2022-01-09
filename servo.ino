void servo_setup(){
  servo.attach(SERVO_PIN,500,2600);
  servo.write(90);
}

void servo_lock(){
    for(int angle = SERVO_NEUTRAL_ANGLE; angle >SERVO_LOCK_ANGLE; angle --){
    servo.write(angle);
    delay(SERVO_DELAY);
  }

  for(int angle = SERVO_LOCK_ANGLE; angle <=SERVO_NEUTRAL_ANGLE; angle ++){
    servo.write(angle);
    delay(SERVO_DELAY);
  }

  servo_lock_request = false;
}

void servo_unlock(){
  for(int angle = SERVO_NEUTRAL_ANGLE; angle <SERVO_UNLOCK_ANGLE; angle ++){
    servo.write(angle);
    delay(SERVO_DELAY);
  }

  for(int angle = SERVO_UNLOCK_ANGLE; angle >=SERVO_NEUTRAL_ANGLE; angle --){
    servo.write(angle);
    delay(SERVO_DELAY);
  }

  servo_unlock_request = false;
}

void handle_servo(){
  if(servo_unlock_request){
    Serial.println("Lock request: unlock");
    servo_unlock();
    
    iot_kernel.device_state = "unlocked";
    iot_kernel.mqtt_publish_state();
    digitalWrite(UNLOCK_LED_PIN,HIGH);
    digitalWrite(LOCK_LED_PIN,LOW);
  }
  if(servo_lock_request){
    Serial.println("Lock request: lock");
    servo_lock();
    
    iot_kernel.device_state = "locked";
    iot_kernel.mqtt_publish_state();
    digitalWrite(LOCK_LED_PIN,HIGH);
    digitalWrite(UNLOCK_LED_PIN,LOW);
  }
}
