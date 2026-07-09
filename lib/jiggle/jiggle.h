#ifndef JIGGLE_H
#define JIGGLE_H

#include <Arduino.h>
#include <Servo.h>

// Initialisiert die 3 Servos an den angegebenen Pins
void initJiggle(uint8_t pin0, uint8_t pin1, uint8_t pin2);

// Berechnet die Winkel (Inverse Kinematik)
double theta(int leg, double hz, double nx, double ny);

// Führt die Wackel-Bewegung der Plattform aus
void jiggle();

#endif