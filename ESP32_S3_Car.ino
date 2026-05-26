#include <WiFi.h>
#include <WebServer.h>
#include "driving.h"
#include "WebControl.h"


const char* ssid = "RoboCar";
const char* password = "123456789";

WebServer server(80); 

void setup() {
  Serial.begin(115200);
  Serial.println("Serial ready!");
  
  setUpMotors();

  WiFi.softAP(ssid, password);
  Serial.println("AP Started");
  Serial.print("IP: ");
  Serial.println(WiFi.softAPIP());
  
  server.on("/forward", handleForward);
  server.on("/backward", handleBackward);
  server.on("/left", handleLeft);
  server.on("/right", handleRight);
  server.on("/stop", handleStop);
  
  server.begin();
  Serial.println("Server Started");
}


void loop() {
  server.handleClient();
}
