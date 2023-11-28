#include "App/data/ws/wsData.h"

WsData& WsData::getInstance() {
    static WsData instance;
    return instance;
}

void WsData::initializeData() {
    this->leftLedMatrixLevel = 0;
    this->centerLedMatrixLevel = 0;
    this->rightLedMatrixLevel = 0;
    this->allLedMatrixLevel = 0;
    this->timerMinute = 0;
    this->temperature = -100.0;
    this->outdoorTemperature = -100.0;
}

int WsData::getLeftLedMatrixLevel()
{
    return this->leftLedMatrixLevel;
}

int WsData::getCenterLedMatrixLevel()
{
    return this->centerLedMatrixLevel;
}

int WsData::getRightLedMatrixLevel()
{
    return this->rightLedMatrixLevel;
}

int WsData::getAllLedMatrixLevel()
{
    return this->allLedMatrixLevel;
}

int WsData::getTimerMinute()
{
    return this->timerMinute;
}

float WsData::getTemperature()
{
    return this->temperature;
}

int WsData::getOutdoorTemperature()
{
    return this->outdoorTemperature;
}

void WsData::setLeftLedMatrixLevel(int level)
{
    this->leftLedMatrixLevel = level;
    this->allLedMatrixLevel = 0;
}

void WsData::setCenterLedMatrixLevel(int level)
{
    this->centerLedMatrixLevel = level;
    this->allLedMatrixLevel = 0;
}

void WsData::setRightLedMatrixLevel(int level)
{
    this->rightLedMatrixLevel = level;
    this->allLedMatrixLevel = 0;
}

void WsData::setAllLedMatrixLevel(int level)
{
    this->leftLedMatrixLevel = level;
    this->centerLedMatrixLevel = level;
    this->rightLedMatrixLevel = level;
    this->allLedMatrixLevel = level;
}

void WsData::setTimerMinute(int minute)
{
    this->timerMinute = minute;
}

void WsData::setTemperature(float temperature)
{
    this->temperature = temperature;
}

void WsData::setOutdoorTemperature(float temperature)
{
    this->outdoorTemperature = temperature;
}

String WsData::toJSON()
{
    JSONVar sliderValues;

    sliderValues["sliderValue1"] = String(this->getAllLedMatrixLevel());
    sliderValues["sliderValue2"] = String(this->getTimerMinute());
    sliderValues["sliderValue3"] = String(this->getLeftLedMatrixLevel());
    sliderValues["sliderValue4"] = String(this->getCenterLedMatrixLevel());
    sliderValues["sliderValue5"] = String(this->getRightLedMatrixLevel());
    sliderValues["sliderValue6"] = String(this->getTemperature());
    sliderValues["sliderValue7"] = String(this->getOutdoorTemperature());

    return JSON.stringify(sliderValues);
}
