#include "Output/Service/Signalizator.h"

Signalizator::Signalizator(const int greenLedPin, const int redLedPin)
    : greenLed(OutputDigitalPinController(greenLedPin)),
    redLed(OutputDigitalPinController(redLedPin))
{
}

void Signalizator::greenBlink(int count, int delayMs) {
    for (int i = 0; i < count; i++) {
        this->greenLed.toggle();
        delay(delayMs);
    }
    this->greenOff();
}

void Signalizator::redBlink(int count, int delayMs) {
    for (int i = 0; i < count; i++) {
        this->redLed.toggle();
        delay(delayMs);
    }
    this->redOff();
}

void Signalizator::greenOn() {
    this->greenLed.turnOn();
}

void Signalizator::redOn() {
    this->redLed.turnOn();
}

void Signalizator::greenOff() {
    this->greenLed.turnOff();
}

void Signalizator::redOff() {
    this->redLed.turnOff();
}

void Signalizator::allOff() {
    this->greenLed.turnOff();
    this->redLed.turnOff();
}
