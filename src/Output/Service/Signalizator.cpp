#include "Output/Service/Signalizator.h"

Signalizator::Signalizator(const int greenLedPin, const int redLedPin)
    : greenLed(OutputDigitalPin(greenLedPin)),
    redLed(OutputDigitalPin(redLedPin))
{
}

void Signalizator::wifiConnection() {
    this->redLed.turnOn();

    Serial.println("Connecting to WiFi...");
}

void Signalizator::wifiConnected() {
    this->redLed.turnOff();
    this->greenLed.blink(5);

    Serial.println("Connected to WiFi");
}
