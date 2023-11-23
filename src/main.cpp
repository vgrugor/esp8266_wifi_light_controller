#include <Arduino.h>
#include "App/config/logger.h"
#include "App/Logger/Logger.h"
#include "Facades/WiFi/WiFiConnectionFacade.h"
#include "env.h"

Logger Ledlogger {GREEN_LED_PIN, RED_LED_PIN};
WiFiConnectionFacade WiFiConnection {
    WIFI_SSID,
    WIFI_PASSWORD,
    WIFI_IP,
    WIFI_GATEWAY,
    WIFI_SUBNET
};

void setup() {
    Serial.begin(115200);

    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);

    Ledlogger.wifiConnection();
    WiFiConnection.initAndConnect();
    Ledlogger.wifiConnected();
}

void loop() {
    if(!WiFiConnection.isConnected()) {
        Ledlogger.wifiConnection();
        WiFiConnection.reconnect();
        Ledlogger.wifiConnected();
    }
}
