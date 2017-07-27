void wifi_setup() {

  // Callbacks
  wifi_connect_handler = WiFi.onStationModeGotIP(wifi_connect_callback);
  wifi_disconnect_handler = WiFi.onStationModeDisconnected(wifi_disconnect_callback);

  // Settings
  WiFi.hostname(HOSTNAME);
  WiFi.mode(WIFI_STA);
}

void wifi_connect() {
  Serial.print("Wifi connecting to ");
  Serial.print(WIFI_SSID);
  Serial.println("...");
  
  wifi_reconnect_timer.detach();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void wifi_connect_callback(const WiFiEventStationModeGotIP& event){
  Serial.print("Wifi connected, IP address: ");
  Serial.println(WiFi.localIP());
  
  MQTT_connect();
}

void wifi_disconnect_callback(const WiFiEventStationModeDisconnected& event){
  Serial.println("Wifi disconnected");
  
  MQTT_reconnect_timer.detach(); // ensure we don't reconnect to MQTT while reconnecting to Wi-Fi
  wifi_reconnect_timer.attach(2, wifi_connect);
}

