// WebServerFacade.h
#ifndef WEBSERVERFACADE_H
    #define WEBSERVERFACADE_H

    #include <ESPAsyncWebServer.h>
    #include <functional>
    #include "App/Facades/WebSocket/WebSocketFacade.h"

    class WebServerFacade {
        public:
            WebServerFacade();
            void init();
            void cleanupClients();

        private:
            AsyncWebServer server;
            WebSocketFacade webSocketFacade;
            void addWsHandler();
            void initRoutes();
            void begin();
    };

#endif
