// WiFiConfig.h
#ifndef WIFICONFIG_H
    #define WIFICONFIG_H

    #include <IPAddress.h>
    #include "env.h"

    struct WiFiConfig {
        const char* ssid;
        const char* password;
        IPAddress ip;
        IPAddress gateway;
        IPAddress subnet;
    };

    extern const WiFiConfig wifiConfig;

#endif 
