#include "OutputAnalogPinController.h"

OutputAnalogPinController::OutputAnalogPinController(int pin) : outputPin(pin) {

}

void OutputAnalogPinController::turnOff() {
	analogWrite(this->outputPin, MIN_PIN_LEVEL);
}

void OutputAnalogPinController::setMaxLevel() {
	analogWrite(this->outputPin, MAX_PIN_LEVEL);
}

void OutputAnalogPinController::setLevel(int level) {
	if (level > MAX_PIN_LEVEL) {
		level = MAX_PIN_LEVEL;
	}

	if (level < MIN_PIN_LEVEL) {
		level = MIN_PIN_LEVEL;
	}

	analogWrite(this->outputPin, level);
}
