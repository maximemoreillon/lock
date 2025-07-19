void MQTT_config(){
  iot_kernel.mqtt.setCallback(mqtt_message_callback);
}


void mqtt_message_callback(char* topic, byte* payload, unsigned int payload_length) {

  Serial.print("[MQTT] message received on ");
  Serial.print(topic);
  Serial.print(", payload: ");
  for (int i = 0; i < payload_length; i++) Serial.print((char)payload[i]);
  Serial.println("");

  // Create a JSON object to hold the message
  // Note: size is limited by MQTT library
  StaticJsonDocument<MQTT_MAX_PACKET_SIZE> inbound_JSON_message;

  // Copy the message into the JSON object
  deserializeJson(inbound_JSON_message, payload);

  if(inbound_JSON_message.containsKey("state")){

    Serial.println("[MQTTT] Payload is JSON with state");

    // Check what the command is and act accordingly
    // Use strdup so as to use strlwr later on
    char* command = strdup(inbound_JSON_message["state"]);

    if( strcmp(strlwr(command), "locked") == 0 ) {
      if(iot_kernel.device_state != "locked") {
        servo_lock_request = true;
        Serial.println("Locking");
      }
      else {
        Serial.println("Already locked");
      }
    }
    else if( strcmp(strlwr(command), "unlocked") == 0 ) {
      if(iot_kernel.device_state != "unlocked") {
        servo_unlock_request = true;
        Serial.println("Unlocking");
      }
      else {
        Serial.println("Already unlocked");
      }
    }
    else if( strcmp(strlwr(command), "toggle") == 0 ) {
      if(iot_kernel.device_state == "locked") {
        servo_unlock_request = true;
      }
      else if(iot_kernel.device_state == "unlocked") {
        servo_lock_request = true;
      }
    }

    free(command);


  }



}
