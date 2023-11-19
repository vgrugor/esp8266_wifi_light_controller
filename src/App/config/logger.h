// logger.h
#ifndef LOGGER_CONFIG_H
    #define LOGGER_CONFIG_H

    #include "env.h"

    struct SignalPins {
        int greenLedPin;
        int redLedPin;
    };

    extern const SignalPins signalPins;

#endif 
