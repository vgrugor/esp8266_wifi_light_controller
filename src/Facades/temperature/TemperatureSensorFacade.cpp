#include <Arduino.h>
#include "Facades/temperature/TemperatureSensorFacade.h"

TemperatureSensorFacade::TemperatureSensorFacade(const uint8_t temperaturePin)
{
    OneWire oneWire {temperaturePin};
    this->sensor = DallasTemperature {&oneWire};
}

void TemperatureSensorFacade::init()
{
    this->sensor.begin();
}

float TemperatureSensorFacade::getTemperatureC()
{
    this->sensor.requestTemperatures();
    float temperature = this->sensor.getTempCByIndex(0);
    delay(TemperatureSensorFacade::DELAY_GETTING_TEMPERATURE);

    return temperature;
}
