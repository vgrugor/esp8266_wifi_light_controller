#include <Arduino.h>
#include "App/config/wifi.h"
#include "App/config/logger.h"
#include "App/Logger/Logger.h"
#include "Facades/WiFi/WiFiConnectionFacade.h"

Logger Ledlogger(GREEN_LED_PIN, RED_LED_PIN);
WiFiConnectionFacade WiFiConnection;

void setup() {
    Serial.begin(115200);

    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);

    Ledlogger.wifiConnection();
    WiFiConnection.connect(wifiConfig);
    Ledlogger.wifiConnected();
}

void loop() {
    if(!WiFiConnection.isConnected()) {
        Ledlogger.wifiConnection();
        WiFiConnection.reconnect();
        Ledlogger.wifiConnected();
    }
}
