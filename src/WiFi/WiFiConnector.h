// WiFiConnector.h
#ifndef WIFICONNECTOR_H
#define WIFICONNECTOR_H

#include <ESP8266WiFi.h>
#include "Helpers/IPParser.h"

class WiFiConnector {
    public:
        WiFiConnector(const char* ssid, const char* password, const char* ip, const char* gateway, const char* subnet);
        bool isConnected();
        void connect();

    private:
        IPAddress ip;
        IPAddress gateway;
        IPAddress subnet;
        IPParser parserIPAddress;
};

#endif
