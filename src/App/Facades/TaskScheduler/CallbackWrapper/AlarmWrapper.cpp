#include "App/Facades/TaskScheduler/CallbackWrapper/AlarmWrapper.h"

void AlarmWrapper::callbackWrapper() {
  BaseTask* task = TaskFactory::createInstance("TaskName");
  if (task) {
    task->someMethod();
    delete task; // Убедитесь, что правильно управляете памятью
  }
}