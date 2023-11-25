// WsMessageResolver.h
#ifndef WSMESSAGERESOLVER_H
    #define WSMESSAGERESOLVER_H

    #include "Arduino.h"
    #include "App/LightController/LightController.h"
    #include "App/data/ws/wsData.h"

    class WsMessageResolver
    {
        public:
            WsMessageResolver();
            bool resolve(String message);

        private:
            LightController lightController;
            WsData& wsData;
            void changeAllLedMatrixLevel(String message);
            void changeTimerMinute(String message);
            void changeLeftLedMatrixLevel(String message);
            void changeCenterLedMatrixLevel(String message);
            void changeRightLedMatrixLevel(String message);
    };

#endif
