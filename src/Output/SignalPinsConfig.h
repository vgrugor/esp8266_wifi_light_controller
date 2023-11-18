// SignalPinsConfig.h
#ifndef SIGNALPINSCONFIG_H
#define SIGNALPINSCONFIG_H

#include "env.h"

struct SignalPins {
    int greenLedPin;
    int redLedPin;
};

extern const SignalPins signalPins;

#endif 
