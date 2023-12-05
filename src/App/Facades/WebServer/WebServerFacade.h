// WebServerFacade.h
#ifndef WEBSERVERFACADE_H
    #define WEBSERVERFACADE_H

    #include <ESPAsyncWebServer.h>
    #include "App/Facades/WebSocket/WebSocketFacade.h"
    #include "LittleFS.h"
    #include "App/Logger/Logger.h"

    class WebServerFacade {
        public:
            WebServerFacade();
            void init();

        private:
            AsyncWebServer server;
            void addWsHandler();
            void initRoutes();
            void begin();
    };

#endif
