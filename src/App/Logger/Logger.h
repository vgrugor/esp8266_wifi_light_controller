// Logger.h
#ifndef LOGGER_H
    #define LOGGER_H

    #include <Arduino.h>
    #include "Hardware/Pin/OutputDigitalPin.h"

    class Logger {
        public:
            Logger(const int greenLedPin, const int redLedPin);
            void wifiErrorSetStaticIp();
            void wifiConnection();
            void wifiConnected();
            void gettingTemperature();
            void temperatureReceived(String temperature);

        private:
            OutputDigitalPin greenLed;
            OutputDigitalPin redLed;
    };

#endif
