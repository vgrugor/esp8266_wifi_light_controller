#include "Facades/WiFi/WiFiConnectionFacade.h"

WiFiConnectionFacade::WiFiConnectionFacade()
{
}

void WiFiConnectionFacade::initAndConnect()
{
    Serial.println("WiFi setting start");

    this->setMode();
    this->setStaticIpAddress();
    this->begin();
    this->connect();
    this->setAutoreconnect();

    Serial.println("WiFi setting end");
}

bool WiFiConnectionFacade::isConnected() {
    return this->wifi.status() == WL_CONNECTED;
}

void WiFiConnectionFacade::reconnect() {
    Serial.println("Reconnect to WiFi");
    
    this->connect();

    Serial.println("Reconnected to WiFi");
}

void WiFiConnectionFacade::setMode() {
    Serial.println("Set WiFi mode");

    this->wifi.mode(WIFI_STA);

    Serial.println("Mode saved");
}

void WiFiConnectionFacade::setStaticIpAddress() {
    Serial.println("Set WiFi static ip");

    IPAddress ip;
    IPAddress gateway;
    IPAddress subnet;

    ip.fromString(WiFiConnectionFacade::WIFI_IP);
    gateway.fromString(WiFiConnectionFacade::WIFI_GATEWAY);
    subnet.fromString(WiFiConnectionFacade::WIFI_SUBNET);

    if(!this->wifi.config(ip, gateway, subnet)) {
        Serial.println("Error set static IP");
    }

    Serial.println("Static IP saved");
}

void WiFiConnectionFacade::begin() {
    Serial.println("Wifi begin");

    this->wifi.begin(WiFiConnectionFacade::WIFI_SSID, WiFiConnectionFacade::WIFI_PASSWORD);

    Serial.println("Wifi begin end");

}

void WiFiConnectionFacade::connect() {
    Serial.println("Connecting to WiFi");

    while (this->wifi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }

    Serial.println("Connected to WiFi");
}

void WiFiConnectionFacade::setAutoreconnect() {
    Serial.println("Set autoreconnect params for WiFi");

    this->wifi.setAutoReconnect(true);
    this->wifi.persistent(true);

    Serial.println("Autoreconnect params for WiFi saved");
}
