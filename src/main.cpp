#include <Arduino.h>
#include "App/config/wifi.h"
#include "App/WiFi/WiFiConnectionWrapper.h"
#include "App/config/logger.h"

WiFiConnectionWrapper WiFiConnection {wifiConfig, signalPins};

void setup() {
    WiFiConnection.connect();
}

void loop() {
    if (!WiFiConnection.isConnected()) {
        WiFiConnection.connect();
    }
}
