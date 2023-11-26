// TaskSchedulerFacade.h
#ifndef TASKSCHEDULERFACADE_H
    #define TASKSCHEDULERFACADE_H

    #include <TimeLib.h>
    #include <TimeAlarms.h>
    #include <string>
    #include <functional>
    #include "App/Facades/TaskScheduler/BaseTask/BaseTask.h"
    #include "App/Facades/TaskScheduler/TaskFactory/TaskFactory.h"

    #include <functional>
    
    #include "App/Facades/TaskScheduler/CallbackWrapper/AlarmWrapper.h"

    class TaskSchedulerFacade
    {
        public:
            TaskSchedulerFacade();
            void addTaskInSeconds(unsigned char second, void (*funcPtr)());
            void addTaskInMinutes(unsigned char minute, void (*funcPtr)());
            void addTaskInHours(unsigned char hour, void (*funcPtr)());

        private:
            TimeAlarmsClass alarm;
    };

#endif
