#include "OutputDigitalPinController.h"

OutputDigitalPinController::OutputDigitalPinController(int pin) : outputPin(pin) {

}

void OutputDigitalPinController::turnOn() {
  digitalWrite(this->outputPin, HIGH);
}

void OutputDigitalPinController::turnOff() {
  digitalWrite(this->outputPin, LOW);
}

void OutputDigitalPinController::toggle() {
  if (digitalRead(this->outputPin) == HIGH) {
    turnOff();
  } else {
    turnOn();
  }
}
