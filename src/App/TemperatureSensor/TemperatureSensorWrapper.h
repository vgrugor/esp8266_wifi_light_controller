// TemperatureSensorWrapper.h
#ifndef TEMPERATURESENSORWRAPPER_H
    #define TEMPERATURESENSORWRAPPER_H

    #include "Facades/temperature/TemperatureSensorFacade.h"
    #include "App/Logger/Logger.h"
    #include "App/config/temperatureSensor.h"
    #include "App/config/logger.h"

    class TemperatureSensorWrapper {
        public:
            TemperatureSensorWrapper(const TemperaturePin& temperaturePin, const SignalPins& signalPins);
            void init();
            float getTemperatureC();

        private:
            TemperatureSensorFacade temperatureSensor;
            Logger logger;
    };

#endif
