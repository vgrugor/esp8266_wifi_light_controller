#include "App/Facades/WebSocket/WebSocketFacade.h"

WebSocketFacade::WebSocketFacade()
    : webSocket(AsyncWebSocket {"/ws"})
{
    using namespace std::placeholders;

    this->webSocket.onEvent(
        std::bind(&WebSocketFacade::handleEvent, this, _1, _2, _3, _4, _5, _6)
    );
}

AsyncWebSocket* WebSocketFacade::getWebSocketObject() {
    return &this->webSocket;
}

void WebSocketFacade::handleEvent(
    AsyncWebSocket *server,
    AsyncWebSocketClient *client,
    AwsEventType type,
    void *arg,
    uint8_t *data,
    size_t len
) {
    switch (type) {
        case WS_EVT_CONNECT:
            Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
            break;
        case WS_EVT_DISCONNECT:
            Serial.printf("WebSocket client #%u disconnected\n", client->id());
            break;
        case WS_EVT_DATA:
            Serial.println("WebSocket client event before run handler");
            this->handleMessage(arg, data, len);
            break;
        case WS_EVT_PONG:
            case WS_EVT_ERROR:
            break;
    }
}

void WebSocketFacade::handleMessage(
    void *arg,
    uint8_t *data,
    size_t len
) {
    Serial.println("Run ws handler");
    AwsFrameInfo *info = (AwsFrameInfo*)arg;
    if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
        data[len] = 0;

        String message = (char*)data;

        LightController lightController;
        WsData& wsData = WsData::getInstance();

        if (message.indexOf("1s") >= 0) {
            String allSliderValue = message.substring(2);
            wsData.setAllLedMatrixLevel(allSliderValue.toInt());
            lightController.allLedMatrixSetLevel(wsData.getAllLedMatrixLevel());
            this->notifyClients();
        }

        if (message.indexOf("2s") >= 0) {
            String timerMinute = message.substring(2);
            wsData.setTimerMinute(timerMinute.toInt());
            //lightController.rightLedMatrixSetLevel(timerMinute.toInt());
            this->notifyClients();
        }

        if (message.indexOf("3s") >= 0) {
            String leftSliderValue = message.substring(2);
            wsData.setLeftLedMatrixLevel(leftSliderValue.toInt());
            lightController.leftLedMatrixSetLevel(wsData.getLeftLedMatrixLevel());
            this->notifyClients();
        }

        if (message.indexOf("4s") >= 0) {
            String centerSliderValue = message.substring(2);
            wsData.setCenterLedMatrixLevel(centerSliderValue.toInt());
            lightController.centerLedMatrixSetLevel(wsData.getCenterLedMatrixLevel());
            this->notifyClients();
        }

        if (message.indexOf("5s") >= 0) {
            String rightSliderValue = message.substring(2);
            wsData.setRightLedMatrixLevel(rightSliderValue.toInt());
            lightController.rightLedMatrixSetLevel(wsData.getRightLedMatrixLevel());
            this->notifyClients();
        }

        if (strcmp((char*)data, "getValues") == 0) {
            this->notifyClients();
        }
    }
}

void WebSocketFacade::notifyClients() {
    WsData& wsData = WsData::getInstance();

    this->webSocket.textAll(wsData.toJSON());
}

void WebSocketFacade::cleanupClients() {
    this->webSocket.cleanupClients();
}
