// LightController.h
#ifndef LIGHTCONTROLLER_H
#define LIGHTCONTROLLER_H

#include <Arduino.h>
#include "Output/Pin/OutputAnalogPinController.h"

class LightController {
public:
    LightController(const int leftLedMatrix, const int centerLedMatrix, const int rightLedMatrix);
    void leftLedMatrixSetLevel(int level);
    void centerLedMatrixSetLevel(int level);
    void rightLedMatrixSetLevel(int level);
    void allLedMatrixSetLevel(int level);
    void turnOffAllLedMatrix();
    void slowTurnOffAllLedMatrix();
    void turnOnAllLedMatrix();
    void slowTurnOnAllLedMatrix();

private:
    const int DISABLED_LEVEL = 255;
    const int MAX_LEVEL = 255;
    OutputAnalogPinController leftLedMatrix;
    OutputAnalogPinController centerLedMatrix;
    OutputAnalogPinController rightLedMatrix;
};

#endif
