#include "Facades/WiFi/WiFiConnectionFacade.h"

WiFiConnectionFacade::WiFiConnectionFacade()
{
}

void WiFiConnectionFacade::connect(const WiFiConfig& wifiConfig)
{
    Serial.println("Set WiFi mode");
    this->wifi.mode(WIFI_STA);

    Serial.println("Set WiFi static ip");
    if(!this->wifi.config(wifiConfig.ip, wifiConfig.gateway, wifiConfig.subnet)) {
        Serial.println("Error set static IP");
    }

    Serial.println("Wifi begin");
    this->wifi.begin(wifiConfig.ssid, wifiConfig.password);

    Serial.println("Connecting to WiFi...");
    while (this->wifi.status() != WL_CONNECTED) {
        delay(1000);
    }
    Serial.println("Connected to WiFi");

    Serial.println("Set autoreconnect params for WiFi");
    this->wifi.setAutoReconnect(true);
    this->wifi.persistent(true);

    Serial.println("WiFi setting end");
}

bool WiFiConnectionFacade::isConnected() {
    return this->wifi.status() == WL_CONNECTED;
}

void WiFiConnectionFacade::reconnect() {
    Serial.println("Reconnect to WiFi");
    while (this->wifi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("Reconnected to WiFi");
}
