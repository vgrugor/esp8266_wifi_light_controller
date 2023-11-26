// TaskSchedulerFacade.h
#ifndef TASKSCHEDULERFACADE_H
    #define TASKSCHEDULERFACADE_H

    #include <TimeLib.h>
    #include <TimeAlarms.h>
    #include <string>
    #include <functional>

    class TaskSchedulerFacade
    {
        public:
            TaskSchedulerFacade();
            void addTaskInSeconds(unsigned char second, void (*funcPtr)());
            void addTaskInMinutes(unsigned char minute, void (*funcPtr)());
            void addTaskInHours(unsigned char hour, void (*funcPtr)());
            void handleTask();

        private:
            TimeAlarmsClass alarm;
    };

#endif
