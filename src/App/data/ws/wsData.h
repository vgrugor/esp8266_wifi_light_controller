// wsData.h
#ifndef WSDATA_H
    #define WSDATA_H

    #include <Arduino.h>
    #include <map>
    #include <Arduino_JSON.h>

    class WsData {
        public:
            static WsData& getInstance();
            void initializeData();
            int getLeftLedMatrixLevel();
            int getCenterLedMatrixLevel();
            int getRightLedMatrixLevel();
            int getAllLedMatrixLevel();
            int getTimerMinute();
            float getTemperature();
            float getOutdoorTemperature();
            void setLeftLedMatrixLevel(int level);
            void setCenterLedMatrixLevel(int level);
            void setRightLedMatrixLevel(int level);
            void setAllLedMatrixLevel(int level);
            void setTimerMinute(int minute);
            void setTemperature(float temperature);
            void setOutdoorTemperature(float temperature);
            String toJSON();

        private:
            int leftLedMatrixLevel;
            int centerLedMatrixLevel;
            int rightLedMatrixLevel;
            int allLedMatrixLevel;
            int timerMinute;
            float temperature;
            float outdoorTemperature;
            WsData() = default;
            ~WsData() = default;
            WsData(const WsData&) = delete;
            WsData& operator=(const WsData&) = delete;
    };

#endif
