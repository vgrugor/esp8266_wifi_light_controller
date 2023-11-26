#include "App/Task/DisableAllLedMatrix/DisableAllLedMatrixTask.h"

DisableAllLedMatrixTask::DisableAllLedMatrixTask()
{
}

void DisableAllLedMatrixTask::run() {
    Serial.println("DisableAllLedMatrixTask start");

    WsData& wsData = WsData::getInstance();
    LightController lightController {};
    wsData.setTimerMinute(0);
    lightController.turnOffAllLedMatrix();

    Serial.println("DisableAllLedMatrixTask done");
}
