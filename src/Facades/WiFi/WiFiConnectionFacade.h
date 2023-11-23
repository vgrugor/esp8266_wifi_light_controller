// WiFiConnectionFacade.h
#ifndef WIFICONNECTIONFACADE_H
    #define WIFICONNECTIONFACADE_H

    #include <Arduino.h>
    #include <ESP8266WiFi.h>
    #include "App/config/wifi.h"
    #include "env.h"

    class WiFiConnectionFacade {
        public:
            WiFiConnectionFacade();
            void initAndConnect();
            bool isConnected();
            void reconnect();

        private:
            const char* WIFI_SSID = "ENERGY";
            const char* WIFI_PASSWORD = "v1502j2107";
            const char* WIFI_IP = "192.168.1.201";
            const char* WIFI_GATEWAY = "192.168.1.1";
            const char* WIFI_SUBNET = "255.255.255.0";
            ESP8266WiFiClass wifi;
            void setMode();
            void setStaticIpAddress();
            void begin();
            void connect();
            void setAutoreconnect();
    };

#endif
