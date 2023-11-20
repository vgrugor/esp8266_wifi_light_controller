// temperatureSensor.h
#ifndef TEMPERATURE_SENSOR_CONFIG_H
    #define TEMPERATURE_SENSOR_CONFIG_H

    #include "env.h"

    struct TemperaturePin {
        const unsigned char pin;
    };

    extern const TemperaturePin temperaturePin;

#endif
