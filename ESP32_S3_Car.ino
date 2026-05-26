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

  WiFi.softAP(ssid, password); // creates a Wifi access point with the given SSID and password
  Serial.println("AP Started");
  Serial.print("IP: ");
  Serial.println(WiFi.softAPIP());
  
  setUpServer(); // call func to set up server routes and turn on server

  Serial.println("Server Started");
}


void loop() {
  server.handleClient(); // checks if a client has made a request and calls the appropriate handler function
}
