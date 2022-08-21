void web_server_config() {  
  iot_kernel.http.on("/lock", HTTP_GET, handle_lock_form);
  iot_kernel.http.on("/lock", HTTP_POST, handle_locking);
  iot_kernel.http.on("/unlock", HTTP_POST, handle_unlocking);
}


void handle_lock_form(AsyncWebServerRequest *request) {

  if(iot_kernel.device_state == "unlocked"){
    request->send(LittleFS, "/www/lock.html", String(), false);
  }
  else {
    request->send(LittleFS, "/www/unlock.html", String(), false);
  }
  
  
}


void handle_locking(AsyncWebServerRequest *request) {

  request->send(LittleFS, "/www/locking.html", String(), false);
  servo_lock_request = true;
  
}

void handle_unlocking(AsyncWebServerRequest *request) {

  request->send(LittleFS, "/www/unlocking.html", String(), false);
  servo_unlock_request = true;
  
}
