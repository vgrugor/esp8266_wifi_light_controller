// WebSocketFacade
#ifndef WEBSOCKETFACADE_H
    #define WEBSOCKETFACADE_H

    #include <ESPAsyncWebServer.h>

    class WebSocketFacade
    {
        public:
            WebSocketFacade();
            AsyncWebSocket* getWebSocketObject();
            void cleanupClients();

        private:
            AsyncWebSocket webSocket;
            void notifyClients();
            void handleEvent(
                AsyncWebSocket *server,
                AsyncWebSocketClient *client,
                AwsEventType type,
                void *arg,
                uint8_t *data,
                size_t len
            );
            void handleMessage(void *arg, uint8_t *data, size_t len);
    };

#endif
