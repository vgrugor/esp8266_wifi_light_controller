// WiFiConnectionFacade.h
#ifndef WIFICONNECTIONFACADE_H
    #define WIFICONNECTIONFACADE_H

    #include <Arduino.h>
    #include <ESP8266WiFi.h>
    #include "App/config/wifi.h"

    class WiFiConnectionFacade {
        public:
            WiFiConnectionFacade();
            void connect(const WiFiConfig& wifiConfig);
            bool isConnected();
            void reconnect();

        private:
            ESP8266WiFiClass wifi;
    };

#endif
