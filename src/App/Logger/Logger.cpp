#include "App/Logger/Logger.h"

Logger::Logger(const int greenLedPin, const int redLedPin)
    : greenLed(OutputDigitalPin(greenLedPin)),
    redLed(OutputDigitalPin(redLedPin))
{
}

void Logger::wifiConnection() {
    this->redLed.turnOn();
}

void Logger::wifiConnected() {
    this->redLed.turnOff();
    this->greenLed.blink(2);
}
