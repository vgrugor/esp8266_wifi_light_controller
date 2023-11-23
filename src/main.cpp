#include <Arduino.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "env.h"
#include "App/Logger/Logger.h"
#include "App/Facades/WiFi/WiFiConnectionFacade.h"
#include "App/Facades/WebServer/WebServerFacade.h"

WiFiConnectionFacade WiFiConnection {
    WIFI_SSID,
    WIFI_PASSWORD,
    WIFI_IP,
    WIFI_GATEWAY,
    WIFI_SUBNET
};
WebServerFacade webServer;
Logger Ledlogger {GREEN_LED_PIN, RED_LED_PIN};

void setup() {
    Serial.begin(115200);

    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);

    Ledlogger.wifiConnection();
    WiFiConnection.initAndConnect();
    Ledlogger.wifiConnected();

    webServer.init();
}

void loop() {
    if(!WiFiConnection.isConnected()) {
        Ledlogger.wifiConnection();
        WiFiConnection.reconnect();
        Ledlogger.wifiConnected();
    }

    webServer.cleanupClients();
}
