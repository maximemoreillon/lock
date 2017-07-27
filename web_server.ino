void web_server_setup(){
  www_server.on("/", handleRoot);
  www_server.on("/lock", handleLock);
  www_server.on("/unlock", handleUnlock);
  www_server.onNotFound(handleNotFound);

  www_server.begin();
  Serial.println("HTTP server started");
}

void handleRoot() {
  
  Serial.println("Webpage / reqested");
  
  if(!www_server.authenticate(WWW_USERNAME, WWW_PASSWORD)){
    return www_server.requestAuthentication();
  }
      
  String pageContent;
  pageContent = pageContent +
    "<html>" +
    "<head>" +
    "<title>LOCK</title>" +
    "<style>" +
    "body {" +
    "background-color: #222;" +
    "font-family: Arial, Helvetica, sans-serif;" +
    "}" +
    ".lock_status {" +
    "margin-top: 150px;" +
    "color: #fff;" +
    "text-align: center;" +
    "font-size: 150px;" +
    "}" +
    ".lockControl {" +
    "margin-top: 50px;" +
    "text-align: center;" +
    "}" +
    "a:link, a:visited {" +
    "margin: 30px;" +
    "font-size: 60px;" +
    "border-style: solid;" +
    "border-color: white;" +
    "border-width: 5px;" +
    "text-decoration: none;" +
    "color: white;display: inline-block;" +
    "width: 350px;" +
    "height: 150px;" +
    "line-height:150px" +
    "}" +
    "a:hover, a:active {" +
    "background-color: #555;" +
    "}" +
    "</style>" +
    "</head>" +
    "<body>" +
    "<div class=\"lock_status\">"+lock_status+"</div>" +
    "<div class=\"lockControl\">" +
    "<a href=\"/lock\">LOCK</a>" +
    "<a href=\"/unlock\">UNLOCK</a>" +
    "</div>" +
    "</body>" +
    "</html>";

  www_server.send(200, "text/html", pageContent);
  
}




void handleLock() {

  Serial.println("Webpage /lock reqested");

  if(!www_server.authenticate(WWW_USERNAME, WWW_PASSWORD)){
    return www_server.requestAuthentication();
  }

  String pageContent;
  pageContent = pageContent +
    "<html>" +
    "<head>" +
    "<meta charset=\"utf-8\" http-equiv=\"refresh\" content=\"2; url=/\">" +
    "<title>LOCK</title>" +
    "<style>" +
    "body {" +
    "background-color: #222;" +
    "font-family: Arial, Helvetica, sans-serif;" +
    "}" +
    ".lock_status {" +
    "margin-top: 150px;" +
    "color: #fff;" +
    "text-align: center;" +
    "font-size: 150px;" +
    "" +
    "animation-name: blink;" +
    "animation-duration: 500ms;" +
    "animation-iteration-count: infinite;" +
    "animation-timing-function: linear;" +
    "animation-direction: alternate;" +
    "}" +
    "@keyframes blink {" +
    "0% { opacity: 1.0; }" +
    "100% { opacity: 0.0; }" +
    "}" +
    ".lockControl {" +
    "margin-top: 50px;" +
    "text-align: center;" +
    "}" +
    ".lockCircle {" +
    "border-style: solid;" +
    "border-color: #fff;" +
    "border-width: 4px;" +
    "border-radius: 50%;" +
    "position: absolute;" +
    "left: 50%;" +
    "margin-left: -152px;" +
    "height:300px;" +
    "width:300px;" +
    "}" +
    ".lockRectangle {" +
    "height:40px;" +
    "width:260px;" +
    "border-style: solid;" +
    "border-color: #fff;" +
    "border-width: 4px;" +
    "position:absolute;" +
    "top: 50%;" +
    "right: 50%;" +
    "margin-right: -132px;" +
    "margin-top: -22px;" +
    "" +
    "animation-name: lockRotation;" +
    "animation-duration: 1s;" +
    "animation-fill-mode: forwards;" +
    "animation-timing-function: linear;" +
    "animation-direction: reverse;" +
    "}" +
    "@keyframes lockRotation {" +
    "100% { transform:rotate(-90deg); }" +
    "}" +
    "</style>" +
    "</head>" +
    "<body>" +
    "<div class=\"lock_status\">LOCKING</div>" +
    "<div class=\"lockControl\">" +
    "<div class=\"lockCircle\">" +
    "<div class=\"lockRectangle\"></div>" +
    "</div>" +
    "</div>" +
    "</body>" +
    "</html>";

  
  www_server.send(200, "text/html", pageContent);
  servo_lock_request = true;
  
}

void handleUnlock() {

  Serial.println("Webpage /unlock reqested");

  if(!www_server.authenticate(WWW_USERNAME, WWW_PASSWORD)){
    return www_server.requestAuthentication();
  }

  String pageContent;
  pageContent = pageContent +
    "<html>" +
    "<head>" +
    "<meta charset=\"utf-8\" http-equiv=\"refresh\" content=\"2; url=/\">" +
    "<title>LOCK</title>" +
    "<style>" +
    "body {" +
    "background-color: #222;" +
    "font-family: Arial, Helvetica, sans-serif;" +
    "}" +
    ".lock_status {" +
    "margin-top: 150px;" +
    "color: #fff;" +
    "text-align: center;" +
    "font-size: 150px;" +
    "" +
    "animation-name: blink;" +
    "animation-duration: 500ms;" +
    "animation-iteration-count: infinite;" +
    "animation-timing-function: linear;" +
    "animation-direction: alternate;" +
    "}" +
    "@keyframes blink {" +
    "0% { opacity: 1.0; }" +
    "100% { opacity: 0.0; }" +
    "}" +
    ".lockControl {" +
    "margin-top: 50px;" +
    "text-align: center;" +
    "}" +
    ".lockCircle {" +
    "border-style: solid;" +
    "border-color: #fff;" +
    "border-width: 4px;" +
    "border-radius: 50%;" +
    "position: absolute;" +
    "left: 50%;" +
    "margin-left: -152px;" +
    "height:300px;" +
    "width:300px;" +
    "}" +
    ".lockRectangle {" +
    "height:40px;" +
    "width:260px;" +
    "border-style: solid;" +
    "border-color: #fff;" +
    "border-width: 4px;" +
    "position:absolute;" +
    "top: 50%;" +
    "right: 50%;" +
    "margin-right: -132px;" +
    "margin-top: -22px;" +
    "" +
    "animation-name: lockRotation;" +
    "animation-duration: 1s;" +
    "animation-fill-mode: forwards;" +
    "animation-timing-function: linear;" +
    "animation-direction: standard;" +
    "}" +
    "@keyframes lockRotation {" +
    "100% { transform:rotate(-90deg); }" +
    "}" +
    "</style>" +
    "</head>" +
    "<body>" +
    "<div class=\"lock_status\">UNLOCKING</div>" +
    "<div class=\"lockControl\">" +
    "<div class=\"lockCircle\">" +
    "<div class=\"lockRectangle\"></div>" +
    "</div>" +
    "</div>" +
    "</body>" +
    "</html>";

  
  www_server.send(200, "text/html", pageContent);
  servo_unlock_request = true;
  
}


void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += www_server.uri();
  message += "\nMethod: ";
  message += (www_server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += www_server.args();
  message += "\n";
  for (uint8_t i=0; i<www_server.args(); i++){
    message += " " + www_server.argName(i) + ": " + www_server.arg(i) + "\n";
  }
  www_server.send(404, "text/plain", message);
}
