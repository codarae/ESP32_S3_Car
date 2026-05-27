#include "WebControl.h"
#include "driving.h"
#include <DNSServer.h>
#include <WiFi.h>

DNSServer dnsServer; // create a DNS server object to handle DNS requests for the captive portal

void handleForward() {
  driveForward();
  server.send(200, "text/plain", "OK");
}

void handleBackward() {
  driveBackward();
  server.send(200, "text/plain", "OK");
}

void handleLeft() {
  driveLeft();
  server.send(200, "text/plain", "OK");
}

void handleRight() {
  driveRight();
  server.send(200, "text/plain", "OK");
}

void handleStop() {
  stopMotors();
  server.send(200, "text/plain", "OK");
}

void handleRoot(){
  String html = "<html><head><title>RoboCar Control</title></head><body>";
  html += "<h1>RoboCar Control</h1>";
  html += "<button onclick=\"fetch('/forward')\">Forward</button><br><br>";
  html += "<button onclick=\"fetch('/backward')\">Backward</button><br><br>";
  html += "<button onclick=\"fetch('/left')\">Left</button><br><br>";
  html += "<button onclick=\"fetch('/right')\">Right</button><br><br>";
  html += "<button onclick=\"fetch('/stop')\">Stop</button><br><br>";  
  html += "</body></html>"; // simple HTML page with buttons to control the car, each button sends a fetch request to the corresponding route when clicked

  server.send(200, "text/html", html);
}

void setUpServer() {
  server.on("/", handleRoot);  // set up route for root URL to serve the control webpage
  server.on("/forward", handleForward); // set up route for forward command
  server.on("/backward", handleBackward); // set up route for backward command
  server.on("/left", handleLeft); // set up route for left command
  server.on("/right", handleRight); // set up route for right command
  server.on("/stop", handleStop); // set up route for stop command

  server.on("/generate_204", handleRoot); // set up routes for captive portal detection, all redirect to the root handler to serve the control webpage
  server.on("/hotspot-detect.html", handleRoot);
  server.on("/connecttest.txt", handleRoot);
  server.on("/ncsi.txt", handleRoot);

  server.begin(); // turn on the server to start listening for requests

  dnsServer.start(53, "*", WiFi.softAPIP()); // start the DNS server to redirect all requests to the IP address of the ESP32's access point
  
}

void processDNS() {
  dnsServer.processNextRequest(); // call this function in the main loop to handle incoming DNS requests for the captive portal
}

