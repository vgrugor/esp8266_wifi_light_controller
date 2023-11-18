#include "Output/Service/LightController.h"

LightController::LightController(const int leftLedMatrix, const int centerLedMatrix, const int rightLedMatrix)
    : leftLedMatrix(OutputAnalogPinController(leftLedMatrix)),
    centerLedMatrix(OutputAnalogPinController(centerLedMatrix)),
    rightLedMatrix(OutputAnalogPinController(rightLedMatrix))
{
}

void LightController::leftLedMatrixSetLevel(int level) {
    this->leftLedMatrix.setLevel(level);
}

void LightController::centerLedMatrixSetLevel(int level) {
    this->centerLedMatrix.setLevel(level);
}

void LightController::rightLedMatrixSetLevel(int level) {
    this->rightLedMatrix.setLevel(level);
}

void LightController::allLedMatrixSetLevel(int level) {
    this->leftLedMatrix.setLevel(level);
    this->centerLedMatrix.setLevel(level);
    this->rightLedMatrix.setLevel(level);
}

void LightController::turnOffAllLedMatrix() {
    this->leftLedMatrix.setLevel(LightController::DISABLED_LEVEL);
    this->centerLedMatrix.setLevel(LightController::DISABLED_LEVEL);
    this->rightLedMatrix.setLevel(LightController::DISABLED_LEVEL);
}

void LightController::slowTurnOffAllLedMatrix() {
    //TODO: need add delay
    this->leftLedMatrix.setLevel(LightController::DISABLED_LEVEL);
    this->centerLedMatrix.setLevel(LightController::DISABLED_LEVEL);
    this->rightLedMatrix.setLevel(LightController::DISABLED_LEVEL);
}

void LightController::turnOnAllLedMatrix() {
    this->leftLedMatrix.setLevel(LightController::MAX_LEVEL);
    this->centerLedMatrix.setLevel(LightController::MAX_LEVEL);
    this->rightLedMatrix.setLevel(LightController::MAX_LEVEL);
}

void LightController::slowTurnOnAllLedMatrix() {
    //TODO: need add delay
    this->leftLedMatrix.setLevel(LightController::MAX_LEVEL);
    this->centerLedMatrix.setLevel(LightController::MAX_LEVEL);
    this->rightLedMatrix.setLevel(LightController::MAX_LEVEL);
}
