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

LittleFSFacade littleFS;
WiFiConnectionFacade WiFiConnection {WIFI_SSID, WIFI_PASSWORD, WIFI_IP, WIFI_GATEWAY, WIFI_SUBNET};
WebServerFacade webServer;
WebSocketFacade& webSocket = WebSocketFacade::getInstance();
Logger Ledlogger {GREEN_LED_PIN, RED_LED_PIN};
WsData& wsData = WsData::getInstance();
TaskSchedulerFacade& taskScheduler = TaskSchedulerFacade::getInstance();

void setup() {
    Serial.begin(115200);

    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(LEFT_LED_MATRIX, OUTPUT);
    pinMode(CENTER_LED_MATRIX, OUTPUT);
    pinMode(RIGHT_LED_MATRIX, OUTPUT);

    littleFS.init();

    Ledlogger.wifiConnection();
    WiFiConnection.initAndConnect();
    Ledlogger.wifiConnected();

    webServer.init();
    wsData.initializeData();

    taskScheduler.addRepeatTaskInSeconds(5, DisableAllLedMatrixTask::run);
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
