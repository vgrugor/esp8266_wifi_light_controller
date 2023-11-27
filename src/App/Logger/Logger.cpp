#include "App/Logger/Logger.h"

Logger::Logger(const int greenLedPin, const int redLedPin)
    : greenLed(OutputDigitalPin(greenLedPin)),
    redLed(OutputDigitalPin(redLedPin))
{
}

void Logger::wifiErrorSetStaticIp() {
    this->redLed.turnOn();

    Serial.println("Error set static Ip");
}

void Logger::wifiConnection() {
    this->redLed.turnOn();
}

void Logger::wifiConnected() {
    this->redLed.turnOff();
    this->greenLed.blink(2);
}

void Logger::gettingTemperature() {
    this->redLed.blink(1);

    Serial.println("Getting Temperature...");
}

void Logger::temperatureReceived(String temperature) {
    this->redLed.turnOff();
    this->greenLed.blink(5);

    Serial.println("temperature Received");
}
