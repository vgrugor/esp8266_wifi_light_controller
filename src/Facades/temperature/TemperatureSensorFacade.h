// TemperatureSensorFacade.h
#ifndef TEMPERATURESENSORFACADE_H
    #define TEMPERATURESENSORFACADE_H

    #include <OneWire.h>
    #include <DallasTemperature.h>

    class TemperatureSensorFacade {
        public:
            TemperatureSensorFacade(const uint8_t temperaturePin);
            void init();
            float getTemperatureC();

        private:
            const int DELAY_GETTING_TEMPERATURE = 2000; 
            DallasTemperature sensor;
    };

#endif
