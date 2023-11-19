// WiFiConnectionWrapper.h
#ifndef WIFICONNECTIONWRAPPER_H
    #define WIFICONNECTIONWRAPPER_H

    #include <Arduino.h>
    #include "App/config/wifi.h"
    #include "App/config/logger.h"
    #include "Facades/WiFi/WiFiConnectionFacade.h"
    #include "App/Logger/Logger.h"

    class WiFiConnectionWrapper {
        public:
            WiFiConnectionWrapper(const WiFiConfig& wifiConfig, const SignalPins& signalPins);
            bool isConnected();
            void connect();

        private:
            WiFiConnectionFacade wifiConnector;
            Signalizator signalizator;
    };

#endif
