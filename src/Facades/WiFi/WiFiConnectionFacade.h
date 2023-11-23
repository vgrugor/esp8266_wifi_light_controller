// WiFiConnectionFacade.h
#ifndef WIFICONNECTIONFACADE_H
    #define WIFICONNECTIONFACADE_H

    #include <Arduino.h>
    #include <ESP8266WiFi.h>
    #include "App/config/wifi.h"

    class WiFiConnectionFacade {
        public:
            WiFiConnectionFacade();
            void initAndConnect(const WiFiConfig& wifiConfig);
            bool isConnected();
            void reconnect();

        private:
            ESP8266WiFiClass wifi;
            void setMode();
            void setStaticIpAddress();
            void begin();
            void connect();
            void setAutoreconnect();
    };

#endif
