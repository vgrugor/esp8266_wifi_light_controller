#include <Arduino.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Time.h>
#include <TimeAlarms.h>
#include <LittleFS.h>
#include "env.h"
#include "App/Facades/LittleFS/LittleFSFacade.h"
#include "App/Facades/WiFi/WiFiConnectionFacade.h"
#include "App/Facades/WebSocket/WebSocketFacade.h"
#include "App/Facades/WebServer/WebServerFacade.h"
#include "App/Logger/Logger.h"
#include "App/Facades/Temperature/TemperatureSensorFacade.h"
#include "App/Task/GetTemperatureTask/GetTemperatureTask.h"

LittleFSFacade littleFS;
WiFiConnectionFacade WiFiConnection {WIFI_SSID, WIFI_PASSWORD, WIFI_IP, WIFI_GATEWAY, WIFI_SUBNET};
WebServerFacade webServer;
WebSocketFacade& webSocket = WebSocketFacade::getInstance();
Logger Ledlogger {GREEN_LED_PIN, RED_LED_PIN};
WsData& wsData = WsData::getInstance();
TaskSchedulerFacade& taskScheduler = TaskSchedulerFacade::getInstance();
TemperatureSensorFacade& temperatureSensor = TemperatureSensorFacade::getInstance();

void setup() {
    Serial.begin(115200);

    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(LEFT_LED_MATRIX, OUTPUT);
    pinMode(CENTER_LED_MATRIX, OUTPUT);
    pinMode(RIGHT_LED_MATRIX, OUTPUT);

    pinMode(BOARD_LED, OUTPUT);
    digitalWrite(BOARD_LED, HIGH);

    littleFS.init();

    Ledlogger.wifiConnection();
    WiFiConnection.initAndConnect();
    Ledlogger.wifiConnected();

    webServer.init();
    wsData.initializeData();
    temperatureSensor.init();

    taskScheduler.addRepeatTaskInMinutes(10, GetTemperatureTask::run);
    taskScheduler.addTaskInSeconds(5, GetTemperatureTask::run);
}

void loop() {
    if(!WiFiConnection.isConnected()) {
        Ledlogger.wifiConnection();
        WiFiConnection.reconnect();
        Ledlogger.wifiConnected();
    }

    webSocket.cleanupClients();
    taskScheduler.handleTask();
}
