#include "OutputDigitalPin.h"

OutputDigitalPin::OutputDigitalPin(int pin) : pin(pin)
{
}

void OutputDigitalPin::turnOn() {
    digitalWrite(this->pin, HIGH);
}

void OutputDigitalPin::turnOff() {
    digitalWrite(this->pin, LOW);
}

void OutputDigitalPin::toggle() {
    if (digitalRead(this->pin) == HIGH) {
        this->turnOff();
    } else {
        this->turnOn();
    }
}

void OutputDigitalPin::blink(int count, int delayMs) {
    if (digitalRead(this->pin) == HIGH) {
        this->turnOff();
        Alarm.delay(delayMs);
    }

    for (int i = 0; i < count; i++) {
        this->toggle();
        Alarm.delay(delayMs);
        this->toggle();
        Alarm.delay(delayMs);
    }
}
