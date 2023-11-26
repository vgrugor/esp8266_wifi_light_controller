// TaskFactory.h
#pragma once
#include <string>
#include <functional>
#include <map>
#include "App/Facades/TaskScheduler/BaseTask/BaseTask.h"

class TaskFactory {
    public:
        static BaseTask* createInstance(const std::string& taskName);

    private:
        static std::map<std::string, std::function<BaseTask*()>> taskMap;
};
