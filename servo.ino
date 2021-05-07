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
}
