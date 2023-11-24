// env.h
#ifndef ENV_H
    #define ENV_H

    #include "Arduino.h"

    extern const char* WIFI_SSID;
    extern const char* WIFI_PASSWORD;
    extern const char* WIFI_IP;
    extern const char* WIFI_GATEWAY;
    extern const char* WIFI_SUBNET;

    extern const int GREEN_LED_PIN;
    extern const int RED_LED_PIN;

    extern const int LEFT_LED_MATRIX;
    extern const int CENTER_LED_MATRIX;
    extern const int RIGHT_LED_MATRIX;

    extern const unsigned char TEMPERATURE_SENSOR_PIN;

#endif // ENV_H
