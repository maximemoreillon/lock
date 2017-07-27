void servo_setup(){
  servo.attach(SERVO_PIN,500,2600);
  servo.write(90);
}

void servo_lock(){
    for(int angle = 90; angle >0; angle --){
    servo.write(angle);
    delay(SERVO_DELAY);
  }

  for(int angle = 0; angle <=90; angle ++){
    servo.write(angle);
    delay(SERVO_DELAY);
  }
}

void servo_unlock(){
  for(int angle = 90; angle <180; angle ++){
    servo.write(angle);
    delay(SERVO_DELAY);
  }

  for(int angle = 180; angle >=90; angle --){
    servo.write(angle);
    delay(SERVO_DELAY);
  }
}

