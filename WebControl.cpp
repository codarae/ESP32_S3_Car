#include "WebControl.h"
#include "driving.h"

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
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setUpServer() {
  server.on("/", handleRoot);
  server.on("/forward", handleForward);
  server.on("/backward", handleBackward);
  server.on("/left", handleLeft);
  server.on("/right", handleRight);
  server.on("/stop", handleStop);
  server.begin();
}