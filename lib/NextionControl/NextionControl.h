#ifndef NEXTION_CONTROL_H
#define NEXTION_CONTROL_H

#include <Arduino.h>

void sendNextionCommand(const char *command);
void clearNextionGraphics();

#endif