#include "LogFileObserver.h"

void LogFileObserver::update(const std::string& message) {
    std::ofstream logFile("log.txt", std::ios_base::app);
    if (logFile.is_open()) {
        logFile << message << std::endl;
        logFile.close();
    }
}
