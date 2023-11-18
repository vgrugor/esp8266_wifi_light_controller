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
    this->signalizator.wifiConnection();

    this->wifiConnector.connect();

    this->signalizator.wifiConnected();
}
