// LightController.h
#ifndef LIGHTCONTROLLER_H
    #define LIGHTCONTROLLER_H

    #include <Arduino.h>
    #include "Hardware/Pin/OutputAnalogPin.h"
    #include "env.h"

    class LightController {
        public:
            LightController(const int leftLedMatrix, const int centerLedMatrix, const int rightLedMatrix);
            LightController();
            void leftLedMatrixSetLevel(int level);
            void centerLedMatrixSetLevel(int level);
            void rightLedMatrixSetLevel(int level);
            void allLedMatrixSetLevel(int level);
            void slowAllLedMatrixSetLevel(int level);
            void turnOffAllLedMatrix();
            void slowTurnOffAllLedMatrix();
            void turnOnAllLedMatrix();
            void slowTurnOnAllLedMatrix();

        private:
            OutputAnalogPin leftLedMatrix;
            OutputAnalogPin centerLedMatrix;
            OutputAnalogPin rightLedMatrix;
            int mapLevel(int level);
    };

#endif
