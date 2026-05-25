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