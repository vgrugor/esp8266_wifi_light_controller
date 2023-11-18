#include "WiFiConnector.h"
#include <Arduino.h>

WiFiConnector::WiFiConnector(const char* ssid, const char* password, const char* ip, const char* gateway, const char* subnet) 
    : parserIPAddress(IPParser())
{
    WiFi.mode(WIFI_STA);
    WiFi.config(
        this->parserIPAddress.parse(ip), 
        this->parserIPAddress.parse(gateway), 
        this->parserIPAddress.parse(subnet)
    );
    WiFi.begin(ssid, password);
}

bool WiFiConnector::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

void WiFiConnector::connect() {
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
}
