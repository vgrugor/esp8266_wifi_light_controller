// TaskSchedulerFacade.h
#ifndef TASKSCHEDULERFACADE_H
    #define TASKSCHEDULERFACADE_H

    #include <TimeLib.h>
    #include <TimeAlarms.h>

    class TaskSchedulerFacade
    {
        public:
            static TaskSchedulerFacade& getInstance();
            void addTaskInSeconds(unsigned char second, void (*funcPtr)());
            void addTaskInMinutes(unsigned char minute, void (*funcPtr)());
            void addTaskInHours(unsigned char hour, void (*funcPtr)());
            void addRepeatTaskInSeconds(unsigned char second, void (*funcPtr)());
            void addRepeatTaskInMinutes(unsigned char minute, void (*funcPtr)());
            void addRepeatTaskInHours(unsigned char hour, void (*funcPtr)());
            void handleTask();

        private:
            AlarmId disableTimerId;
            TaskSchedulerFacade();
            ~TaskSchedulerFacade() = default;
            TaskSchedulerFacade(const TaskSchedulerFacade&) = delete;
            TaskSchedulerFacade& operator=(const TaskSchedulerFacade&) = delete;
    };

#endif
