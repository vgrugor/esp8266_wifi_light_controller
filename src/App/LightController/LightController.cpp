#include "App/LightController/LightController.h"

LightController::LightController(const int leftLedMatrix, const int centerLedMatrix, const int rightLedMatrix)
    : leftLedMatrix(OutputAnalogPin(leftLedMatrix)),
    centerLedMatrix(OutputAnalogPin(centerLedMatrix)),
    rightLedMatrix(OutputAnalogPin(rightLedMatrix))
{
}

LightController::LightController()
    : leftLedMatrix(OutputAnalogPin(LEFT_LED_MATRIX)),
    centerLedMatrix(OutputAnalogPin(CENTER_LED_MATRIX)),
    rightLedMatrix(OutputAnalogPin(RIGHT_LED_MATRIX))
{
}

void LightController::leftLedMatrixSetLevel(int level) {
    Serial.println("Left led matrix set level");
    Serial.println(" - start level ");
    Serial.print(level);

    level = this->mapLevel(level);

    Serial.println(" - mapped level ");
    Serial.print(level);

    this->leftLedMatrix.setLevel(level);
    Serial.println(" - level setted");
}

void LightController::centerLedMatrixSetLevel(int level) {
    level = this->mapLevel(level);

    this->centerLedMatrix.setLevel(level);
}

void LightController::rightLedMatrixSetLevel(int level) {
    level = this->mapLevel(level);

    this->rightLedMatrix.setLevel(level);
}

void LightController::allLedMatrixSetLevel(int level) {
    level = this->mapLevel(level);

    this->leftLedMatrix.setLevel(level);
    this->centerLedMatrix.setLevel(level);
    this->rightLedMatrix.setLevel(level);
}

void LightController::slowAllLedMatrixSetLevel(int level) {
    //TODO add delay
    level = this->mapLevel(level);

    this->leftLedMatrix.setLevel(level);
    this->centerLedMatrix.setLevel(level);
    this->rightLedMatrix.setLevel(level);
}

void LightController::turnOffAllLedMatrix() {
    this->leftLedMatrix.setLevel(OutputAnalogPin::MIN_PIN_LEVEL);
    this->centerLedMatrix.setLevel(OutputAnalogPin::MIN_PIN_LEVEL);
    this->rightLedMatrix.setLevel(OutputAnalogPin::MIN_PIN_LEVEL);
}

void LightController::slowTurnOffAllLedMatrix() {
    //TODO: need add delay
    this->leftLedMatrix.slowSetLevel(OutputAnalogPin::MIN_PIN_LEVEL);
    this->centerLedMatrix.slowSetLevel(OutputAnalogPin::MIN_PIN_LEVEL);
    this->rightLedMatrix.slowSetLevel(OutputAnalogPin::MIN_PIN_LEVEL);
}

void LightController::turnOnAllLedMatrix() {
    this->leftLedMatrix.setLevel(OutputAnalogPin::MAX_PIN_LEVEL);
    this->centerLedMatrix.setLevel(OutputAnalogPin::MAX_PIN_LEVEL);
    this->rightLedMatrix.setLevel(OutputAnalogPin::MAX_PIN_LEVEL);
}

void LightController::slowTurnOnAllLedMatrix() {
    //TODO: need add delay
    this->leftLedMatrix.slowSetLevel(OutputAnalogPin::MAX_PIN_LEVEL);
    this->centerLedMatrix.slowSetLevel(OutputAnalogPin::MAX_PIN_LEVEL);
    this->rightLedMatrix.slowSetLevel(OutputAnalogPin::MAX_PIN_LEVEL);
}

int LightController::mapLevel(int level) {
    return map(level, 0, 100, OutputAnalogPin::MIN_PIN_LEVEL, OutputAnalogPin::MAX_PIN_LEVEL);
}
