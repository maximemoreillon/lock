void button_init(){
  pinMode(BUTTON_PIN,INPUT_PULLUP);
}

int readButtonDebounce(int pin) {
  const int DEBOUNCE_DELAY = 50;
  static int buttonState, lastButtonState;
  static long lastDebounceTime; 
  int out = 0;

  int reading = digitalRead(pin);
  if(reading != lastButtonState) lastDebounceTime = millis();

  if((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      buttonState = reading;
      // ACTIVE LOW
      if(!buttonState) {
        out = 1;
      }
    }
  }
  lastButtonState = reading;
  return out;
}

void button_read(){
  if(readButtonDebounce(BUTTON_PIN)){
    Serial.println("[IO] Button pressed, toggling lock state");
    
    if(iot_kernel.device_state == "locked") {
      servo_unlock_request = true;
    }
    else if(iot_kernel.device_state == "unlocked") {
      servo_lock_request = true;
    }
  }
  
}
