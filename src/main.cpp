#include <Arduino.h>
#include "WiFi/WiFiConfig.h"
#include "WiFi/WiFiController.h"
#include "Output/SignalPinsConfig.h"

WiFiController WiFiManager {wifiConfig, signalPins};

void setup() {
  WiFiManager.connect();
}

void loop() {
  if (!WiFiManager.isConnected()) {
    WiFiManager.connect();
  }
}
