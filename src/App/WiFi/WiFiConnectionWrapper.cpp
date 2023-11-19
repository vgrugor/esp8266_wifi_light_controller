#include "App/WiFi/WiFiConnectionWrapper.h"
#include "Facades/WiFi/WiFiConnectionFacade.h"

WiFiConnectionWrapper::WiFiConnectionWrapper(const WiFiConfig& wifiConfig, const SignalPins& signalPins) 
    : wifiConnector(WiFiConnectionFacade {wifiConfig.ssid, wifiConfig.password, wifiConfig.ip, wifiConfig.gateway, wifiConfig.subnet}),
    logger(Logger {signalPins.greenLedPin, signalPins.redLedPin})
{
}

bool WiFiConnectionWrapper::isConnected() {
    return this->wifiConnector.isConnected();
}

void WiFiConnectionWrapper::connect() {
    this->logger.wifiConnection();

    this->wifiConnector.connect();

    this->logger.wifiConnected();
}
