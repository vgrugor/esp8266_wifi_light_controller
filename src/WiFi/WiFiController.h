// WiFiController.h
#ifndef WIFICONTROLLER_H
    #define WIFICONTROLLER_H

    #include <Arduino.h>
    #include "WiFi/WiFiConfig.h"
    #include "Output/SignalPinsConfig.h"
    #include "WiFi/WiFiConnector.h"
    #include "Output/Service/Signalizator.h"

    class WiFiController {
        public:
            WiFiController(const WiFiConfig& wifiConfig, const SignalPins& signalPins);
            bool isConnected();
            void connect();

        private:
            WiFiConnector wifiConnector;
            Signalizator signalizator;
            void sendConection();
            void sendConected();
    };

#endif
