#include <Arduino.h>
#include "App/config/wifi.h"
#include "App/WiFi/WiFiConnectionWrapper.h"
#include "Output/SignalPinsConfig.h"

WiFiConnectionWrapper WiFiConnection {wifiConfig, signalPins};

void setup() {
    WiFiConnection.connect();
}

void loop() {
    if (!WiFiConnection.isConnected()) {
        WiFiConnection.connect();
    }
}
