#include "WiFi/WiFiController.h"

WiFiController::WiFiController(const WiFiConfig& wifiConfig, const SignalPins& signalPins) 
    : wifiConnector(WiFiConnector {wifiConfig.ssid, wifiConfig.password, wifiConfig.ip, wifiConfig.gateway, wifiConfig.subnet}),
    signalizator(Signalizator {signalPins.greenLedPin, signalPins.redLedPin})
{
}

bool WiFiController::isConnected() {
    return this->wifiConnector.isConnected();
}

void WiFiController::connect() {
    this->sendConection();

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }

    this->sendConected();
}

void WiFiController::sendConection() {
    Serial.println("Connecting to WiFi...");

    this->signalizator.redOn();
}

void WiFiController::sendConected() {
    this->signalizator.redOff();
    this->signalizator.greenBlink(5);

    Serial.println("Connected to WiFi");
}
