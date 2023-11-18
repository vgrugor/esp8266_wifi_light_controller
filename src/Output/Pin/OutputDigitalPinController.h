// OutputDigitalPinController.h
#ifndef OUTPUTDIGITALPINCONTROLLER_H
#define OUTPUTDIGITALPINCONTROLLER_H

#include <Arduino.h>

class OutputDigitalPinController {
public:
  OutputDigitalPinController(int pin);
  void turnOn();
  void turnOff();
  void toggle();

private:
  int outputPin;
};

#endif