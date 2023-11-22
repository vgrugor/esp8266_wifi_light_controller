#include "App/config/wifi.h"

const WiFiConfig wifiConfig = {
    WIFI_SSID,
    WIFI_PASSWORD,
    []() {
        unsigned char ipBytes[4];
        sscanf(WIFI_IP, "%hhu.%hhu.%hhu.%hhu", &ipBytes[0], &ipBytes[1], &ipBytes[2], &ipBytes[3]);
        return IPAddress(ipBytes);
    }(),
    []() {
        unsigned char ipBytes[4];
        sscanf(WIFI_GATEWAY, "%hhu.%hhu.%hhu.%hhu", &ipBytes[0], &ipBytes[1], &ipBytes[2], &ipBytes[3]);
        return IPAddress(ipBytes);
    }(),
    []() {
        unsigned char ipBytes[4];
        sscanf(WIFI_SUBNET, "%hhu.%hhu.%hhu.%hhu", &ipBytes[0], &ipBytes[1], &ipBytes[2], &ipBytes[3]);
        return IPAddress(ipBytes);
    }()
};
