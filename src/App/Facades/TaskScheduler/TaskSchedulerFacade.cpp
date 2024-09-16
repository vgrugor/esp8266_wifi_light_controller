#include "App/Facades/TaskScheduler/TaskSchedulerFacade.h"

TaskSchedulerFacade::TaskSchedulerFacade() {
    setTime(0, 0, 0, 25, 11, 23);
}

TaskSchedulerFacade& TaskSchedulerFacade::getInstance() {
    static TaskSchedulerFacade instance;
    return instance;
}

void TaskSchedulerFacade::addTaskInSeconds(unsigned char second, void (*funcPtr)()) {
    if (this->disableTimerId) {
        Alarm.disable(this->disableTimerId);
    }

    this->disableTimerId = Alarm.timerOnce(0, 0, second, funcPtr);
}

void TaskSchedulerFacade::addTaskInMinutes(unsigned char minute, void (*funcPtr)()) {
    if (this->disableTimerId) {
        Alarm.disable(this->disableTimerId);
    }

    this->disableTimerId = Alarm.timerOnce(0, minute, 0, funcPtr);
}

void TaskSchedulerFacade::addTaskInHours(unsigned char hour, void (*funcPtr)()) {
    if (this->disableTimerId) {
        Alarm.disable(this->disableTimerId);
    }

    this->disableTimerId = Alarm.timerOnce(hour, 0, 0, funcPtr);
}

void TaskSchedulerFacade::handleTask() {
    Alarm.delay(0);
}

void TaskSchedulerFacade::addRepeatTaskInSeconds(unsigned char second, void (*funcPtr)()) {
    Alarm.timerRepeat(0, 0, second, funcPtr);
}

void TaskSchedulerFacade::addRepeatTaskInMinutes(unsigned char minute, void (*funcPtr)()) {
    Alarm.timerRepeat(0, minute, 0, funcPtr);
}

void TaskSchedulerFacade::addRepeatTaskInHours(unsigned char hour, void (*funcPtr)()) {
    Alarm.timerRepeat(hour, 0, 0, funcPtr);
}
