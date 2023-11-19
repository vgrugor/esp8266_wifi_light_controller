#include "App/TemperatureSensor/TemperatureSensorWrapper.h"

TemperatureSensorWrapper::TemperatureSensorWrapper(const TemperaturePin& temperaturePin, const SignalPins& signalPins) 
    : temperatureSensor(TemperatureSensorFacade {temperaturePin.pin}),
    logger(Logger {signalPins.greenLedPin, signalPins.redLedPin})
{
}

void TemperatureSensorWrapper::init() {
    this->temperatureSensor.init();
}

float TemperatureSensorWrapper::getTemperatureC() {
    this->logger.gettingTemperature();

    float temperature = this->temperatureSensor.getTemperatureC();

    this->logger.temperatureReceived(String(temperature));

    return temperature;
}
