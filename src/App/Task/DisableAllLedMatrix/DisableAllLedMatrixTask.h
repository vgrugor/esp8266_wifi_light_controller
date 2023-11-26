// DisableAllLedMatrixTask.h
#ifndef DISABLEALLLEDMATRIXTASK_H
    #define DISABLEALLLEDMATRIXTASK_H

    #include <Arduino.h>
    #include "App/data/ws/wsData.h"
    #include "App/LightController/LightController.h"

    class DisableAllLedMatrixTask {
        public:
            DisableAllLedMatrixTask();
            static void run();
    };

#endif
