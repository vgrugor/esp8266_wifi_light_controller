// WiFiConnectionFacade.h
#ifndef WIFICONNECTIONFACADE_H
    #define WIFICONNECTIONFACADE_H

    #include <ESP8266WiFi.h>
    #include "Helpers/IPParser.h"

    class WiFiConnectionFacade {
        public:
            WiFiConnectionFacade(const char* ssid, const char* password, const char* ip, const char* gateway, const char* subnet);
            bool isConnected();
            void connect();

        private:
            IPAddress ip;
            IPAddress gateway;
            IPAddress subnet;
            IPParser parserIPAddress;
    };

#endif
