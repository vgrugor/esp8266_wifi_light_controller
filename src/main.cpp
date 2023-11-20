#include <Arduino.h>
#include "App/config/wifi.h"
#include "App/config/temperatureSensor.h"
#include "App/WiFi/WiFiConnectionWrapper.h"
#include "App/TemperatureSensor/TemperatureSensorWrapper.h"
#include "App/config/logger.h"

WiFiConnectionWrapper WiFiConnection {wifiConfig, signalPins};
TemperatureSensorWrapper TemperatureSensor {temperaturePin, signalPins};

void setup() {
    WiFiConnection.connect();
    TemperatureSensor.init();
}

void loop() {
    if (!WiFiConnection.isConnected()) {
        WiFiConnection.connect();
    }

    TemperatureSensor.getTemperatureC();
}
