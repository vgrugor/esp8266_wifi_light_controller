#include <Arduino.h>
#include "Facades/WiFi/WiFiConnectionFacade.h"

WiFiConnectionFacade::WiFiConnectionFacade(const char* ssid, const char* password, const char* ip, const char* gateway, const char* subnet) 
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

bool WiFiConnectionFacade::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

void WiFiConnectionFacade::connect() {
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
}
