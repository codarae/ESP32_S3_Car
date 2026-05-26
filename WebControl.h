#ifndef WEBCONTROL_H
#define WEBCONTROL_H

#include <WebServer.h>

extern WebServer server;

void handleForward();
void handleBackward();
void handleRight();
void handleLeft();
void handleStop();
void handleRoot();
void setUpServer();

#endif
