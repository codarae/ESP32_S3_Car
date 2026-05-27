#ifndef WEBCONTROL_H
#define WEBCONTROL_H

#include <WebServer.h>

extern WebServer server;  // declare the web server object so it can be used in WebControl.cpp

void handleForward();
void handleBackward();
void handleRight();
void handleLeft();
void handleStop();
void handleRoot();
void setUpServer();
void processDNS();

#endif
