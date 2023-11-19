#include "App/WiFi/WiFiConnectionWrapper.h"
#include "Facades/WiFi/WiFiConnectionFacade.h"

WiFiConnectionWrapper::WiFiConnectionWrapper(const WiFiConfig& wifiConfig, const SignalPins& signalPins) 
    : wifiConnector(WiFiConnectionFacade {wifiConfig.ssid, wifiConfig.password, wifiConfig.ip, wifiConfig.gateway, wifiConfig.subnet}),
    signalizator(Signalizator {signalPins.greenLedPin, signalPins.redLedPin})
{
}

bool WiFiConnectionWrapper::isConnected() {
    return this->wifiConnector.isConnected();
}

void WiFiConnectionWrapper::connect() {
    this->signalizator.wifiConnection();

    this->wifiConnector.connect();

    this->signalizator.wifiConnected();
}
