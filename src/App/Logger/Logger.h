// Signalizator.h
#ifndef SIGNALIZATOR_H
    #define SIGNALIZATOR_H

    #include <Arduino.h>
    #include "Hardware/Pin/OutputDigitalPin.h"

    class Signalizator {
        public:
            Signalizator(const int greenLedPin, const int redLedPin);
            void wifiConnection();
            void wifiConnected();

        private:
            OutputDigitalPin greenLed;
            OutputDigitalPin redLed;
    };

#endif
