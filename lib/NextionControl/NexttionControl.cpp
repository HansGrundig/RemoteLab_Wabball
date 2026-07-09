#include "NextionControl.h"

void sendNextionCommand(const char *command) {
    Serial1.print(command);
    Serial1.write(0xFF);
    Serial1.write(0xFF);
    Serial1.write(0xFF);
}

void clearNextionGraphics() {
    sendNextionCommand("ref 0"); 
}