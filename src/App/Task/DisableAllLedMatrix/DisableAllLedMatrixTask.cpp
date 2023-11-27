#include "App/Task/DisableAllLedMatrix/DisableAllLedMatrixTask.h"

DisableAllLedMatrixTask::DisableAllLedMatrixTask()
{
}

void DisableAllLedMatrixTask::run() {
    Serial.println("DisableAllLedMatrixTask start");

    WsData& wsData = WsData::getInstance();
    LightController lightController {};
    WebSocketFacade& webSocket = WebSocketFacade::getInstance();

    wsData.setTimerMinute(0);
    wsData.setAllLedMatrixLevel(0);
    wsData.setLeftLedMatrixLevel(0);
    wsData.setCenterLedMatrixLevel(0);
    wsData.setRightLedMatrixLevel(0);

    lightController.turnOffAllLedMatrix();

    webSocket.notifyClients();

    Serial.println("DisableAllLedMatrixTask done");
}
