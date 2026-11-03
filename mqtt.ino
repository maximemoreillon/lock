void MQTT_config(){
  iot_kernel.mqtt.setCallback(mqtt_message_callback);

  // Subscriptions are lost on disconnect: renew them on every connect,
  // and republish the state so the retained message is up to date
  iot_kernel.onMqttConnect([]() {
    iot_kernel.mqtt.subscribe(iot_kernel.mqttCommandTopic.c_str());
    publish_lock_state();
  });
}

void publish_lock_state(){
  JsonDocument message;
  message["state"] = lock_state;
  char payload[MQTT_MAX_PACKET_SIZE];
  serializeJson(message, payload, sizeof(payload));
  iot_kernel.mqtt.publish(iot_kernel.mqttStateTopic.c_str(), payload, MQTT_RETAIN);
}

void mqtt_message_callback(char* topic, byte* payload, unsigned int payload_length) {

  Serial.printf("[MQTT] Message received on %s: %.*s\n", topic, (int) payload_length, (char*) payload);

  JsonDocument message;
  // NOTE: payload is not null-terminated, so the length must be passed
  if(deserializeJson(message, payload, payload_length)) return;

  const char* command = message["state"];
  if(!command) return;

  if(strcasecmp(command, "locked") == 0) {
    if(lock_state != "locked") servo_lock_request = true;
  }
  else if(strcasecmp(command, "unlocked") == 0) {
    if(lock_state != "unlocked") servo_unlock_request = true;
  }
  else if(strcasecmp(command, "toggle") == 0) {
    if(lock_state == "locked") servo_unlock_request = true;
    else if(lock_state == "unlocked") servo_lock_request = true;
  }
}
