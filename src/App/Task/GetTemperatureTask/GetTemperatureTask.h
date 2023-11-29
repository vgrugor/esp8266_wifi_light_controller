// GetTemperatureTask.h
#ifndef GETTEMPERATURETASK_H
    #define GETTEMPERATURETASK_H

    #include "App/data/ws/wsData.h"
    #include "App/Facades/WebSocket/WebSocketFacade.h"
    #include "App/Facades/Temperature/TemperatureSensorFacade.h"

    class GetTemperatureTask {
        public:
            GetTemperatureTask();
            static void run();
    };

#endif
