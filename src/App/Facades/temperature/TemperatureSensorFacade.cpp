#include "App/Facades/temperature/TemperatureSensorFacade.h"

TemperatureSensorFacade& TemperatureSensorFacade::getInstance() {
    static TemperatureSensorFacade instance;
    return instance;
}

TemperatureSensorFacade::TemperatureSensorFacade()
{
    OneWire oneWire {TEMPERATURE_SENSOR_PIN};
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
