// WiFiConfig.h
#ifndef WIFICONFIG_H
    #define WIFICONFIG_H

    #include "env.h"

    struct WiFiConfig {
        const char* ssid;
        const char* password;
        const char* ip;
        const char* gateway;
        const char* subnet;
    };

    extern const WiFiConfig wifiConfig;

#endif 
