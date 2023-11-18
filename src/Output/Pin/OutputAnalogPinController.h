// OutputAnalogPinController.h
#ifndef OUTPUTANALOGPINCONTROLLER_H
#define OUTPUTANALOGPINCONTROLLER_H

#include <Arduino.h>

class OutputAnalogPinController {
    public:
        OutputAnalogPinController(int pin);
        void turnOff();
        void setMaxLevel();
        void setLevel(int level);

    private:
        static const int MIN_PIN_LEVEL = 0;
        static const int MAX_PIN_LEVEL = 255;
        int outputPin;
};

#endif