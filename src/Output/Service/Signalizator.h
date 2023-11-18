// Signalizator.h
#ifndef SIGNALIZATOR_H
#define SIGNALIZATOR_H

#include <Arduino.h>
#include "Output/Pin/OutputDigitalPinController.h"

class Signalizator {
public:
    Signalizator(const int greenLedPin, const int redLedPin);
    void greenBlink(int count, int delayMs = 1000);
    void redBlink(int count, int delayMs = 1000);
    void greenOn();
    void redOn();
    void greenOff();
    void redOff();
    void allOff();

private:
    OutputDigitalPinController greenLed;
    OutputDigitalPinController redLed;
};

#endif
