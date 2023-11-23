// WebServerFacade.h
#ifndef WEBSERVERFACADE_H
    #define WEBSERVERFACADE_H

    //#include <Arduino.h>
    //#include <ESP8266WiFi.h>
    #include <ESPAsyncWebServer.h>
    #include <functional>

    class WebServerFacade {
        public:
            WebServerFacade();
            void init();

        private:
            AsyncWebServer server;
            AsyncWebSocket webSocket;
            void notifyClients();
            void addWsHandler();
            void begin();
            void initRoutes();
            void onEvent(
                AsyncWebSocket *server,
                AsyncWebSocketClient *client,
                AwsEventType type,
                void *arg,
                uint8_t *data,
                size_t len
            );
            void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);
            void cleanupClients();
    };

#endif
