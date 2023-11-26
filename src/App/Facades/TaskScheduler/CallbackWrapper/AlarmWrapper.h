#ifndef ALARM_WRAPPER_H
#define ALARM_WRAPPER_H

#include "App/Facades/TaskScheduler/BaseTask/BaseTask.h"
#include "App/Facades/TaskScheduler/TaskFactory/TaskFactory.h"

class AlarmWrapper {
public:
  static void callbackWrapper();
};

#endif  // ALARM_WRAPPER_H