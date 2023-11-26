#include "App/Facades/TaskScheduler/TaskFactory/TaskFactory.h"
#include "App/Task/DisableAllLedMatrix/DisableAllLedMatrixTask.h"
//#include "GetTemperatureTask.h"

std::map<std::string, std::function<BaseTask*()>> TaskFactory::taskMap = {
    //{"DisableAllLedMatrixTask", []() { return new DisableAllLedMatrixTask(); }},
    //{"GetTemperatureTask", []() { return new GetTemperatureTask(); }},
};

BaseTask* TaskFactory::createInstance(const std::string& taskName) {
    auto it = taskMap.find(taskName);
    if (it != taskMap.end()) {
        return it->second();
    }
    return nullptr;
}
