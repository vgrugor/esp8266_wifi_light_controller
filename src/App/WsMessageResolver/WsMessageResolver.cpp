#include "App/WsMessageResolver/WsMessageResolver.h"

WsMessageResolver::WsMessageResolver()
    : lightController(LightController {}),
    wsData(WsData::getInstance()),
    taskScheduler(TaskSchedulerFacade {})
{
}

bool WsMessageResolver::resolve(String message) {
    bool result = false;

    if (message.indexOf("1s") >= 0) {
        this->changeAllLedMatrixLevel(message);
        result = true;
    }

    if (message.indexOf("2s") >= 0) {
        this->changeTimerMinute(message);
        result = true;
    }

    if (message.indexOf("3s") >= 0) {
        this->changeLeftLedMatrixLevel(message);
        result = true;
    }

    if (message.indexOf("4s") >= 0) {
        this->changeCenterLedMatrixLevel(message);
        result = true;
    }

    if (message.indexOf("5s") >= 0) {
        this->changeRightLedMatrixLevel(message);
        result = true;
    }

    if (message.indexOf("getValues") >= 0) {
        result = true;
    }

    return result;
}

void WsMessageResolver::changeAllLedMatrixLevel(String message) {
    String allSliderValue = message.substring(2);
    wsData.setAllLedMatrixLevel(allSliderValue.toInt());
    lightController.allLedMatrixSetLevel(wsData.getAllLedMatrixLevel());
}

void WsMessageResolver::changeTimerMinute(String message) {
    String timerMinute = message.substring(2);
    wsData.setTimerMinute(timerMinute.toInt());
    this->taskScheduler.addTaskInMinutes(wsData.getTimerMinute(), DisableAllLedMatrixTask::run);
}

void WsMessageResolver::changeLeftLedMatrixLevel(String message) {
    String leftSliderValue = message.substring(2);
    wsData.setLeftLedMatrixLevel(leftSliderValue.toInt());
    lightController.leftLedMatrixSetLevel(wsData.getLeftLedMatrixLevel());
}

void WsMessageResolver::changeCenterLedMatrixLevel(String message) {
    String centerSliderValue = message.substring(2);
    wsData.setCenterLedMatrixLevel(centerSliderValue.toInt());
    lightController.centerLedMatrixSetLevel(wsData.getCenterLedMatrixLevel());
}

void WsMessageResolver::changeRightLedMatrixLevel(String message) {
    String rightSliderValue = message.substring(2);
    wsData.setRightLedMatrixLevel(rightSliderValue.toInt());
    lightController.rightLedMatrixSetLevel(wsData.getRightLedMatrixLevel());
}
