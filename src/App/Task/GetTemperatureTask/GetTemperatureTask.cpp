#include "App/Task/GetTemperatureTask/GetTemperatureTask.h"

GetTemperatureTask::GetTemperatureTask()
{
}

void GetTemperatureTask::run() {
    Serial.println("GetTemperatureTask start");

    WsData& wsData = WsData::getInstance();
    WebSocketFacade& webSocket = WebSocketFacade::getInstance();
    TemperatureSensorFacade& temperatureSensor = TemperatureSensorFacade::getInstance();

    Serial.println(temperatureSensor.getTemperatureC());

    wsData.setTemperature(temperatureSensor.getTemperatureC());

    webSocket.notifyClients();

    Serial.println("GetTemperatureTask done");
}
