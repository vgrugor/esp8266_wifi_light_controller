#include "App/Facades/temperature/TemperatureSensorFacade.h"

TemperatureSensorFacade::TemperatureSensorFacade()
    : oneWire(OneWire (TEMPERATURE_SENSOR_PIN)),
    sensor(DallasTemperature(&this->oneWire))
{
}

TemperatureSensorFacade& TemperatureSensorFacade::getInstance() {
    static TemperatureSensorFacade instance;
    return instance;
}

void TemperatureSensorFacade::init()
{
    this->sensor.begin();
}

float TemperatureSensorFacade::getTemperatureC()
{
    this->sensor.requestTemperatures();
    float temperatureC = this->sensor.getTempCByIndex(0);
    delay(TemperatureSensorFacade::DELAY_GETTING_TEMPERATURE);

    return temperatureC;
}
