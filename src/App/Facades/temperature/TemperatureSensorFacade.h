// TemperatureSensorFacade.h
#ifndef TEMPERATURESENSORFACADE_H
    #define TEMPERATURESENSORFACADE_H

    #include <Arduino.h>
    #include <OneWire.h>
    #include <DallasTemperature.h>
    #include "env.h"

    class TemperatureSensorFacade {
        public:
            static TemperatureSensorFacade& getInstance();
            void init();
            float getTemperatureC();

        private:
            const int DELAY_GETTING_TEMPERATURE = 2000; 
            OneWire oneWire;
            DallasTemperature sensor;
            TemperatureSensorFacade();
            ~TemperatureSensorFacade() = default;
            TemperatureSensorFacade(const TemperatureSensorFacade&) = delete;
            TemperatureSensorFacade& operator=(const TemperatureSensorFacade&) = delete;
    };

#endif
