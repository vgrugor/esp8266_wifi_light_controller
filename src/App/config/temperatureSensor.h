// temperatureSensor.h
#ifndef TEMPERATURE_SENSOR_CONFIG_H
    #define TEMPERATURE_SENSOR_CONFIG_H

    #include "env.h"

    struct TemperaturePin {
        const uint8_t pin;
    };

    extern const TemperaturePin temperaturePin;

#endif
