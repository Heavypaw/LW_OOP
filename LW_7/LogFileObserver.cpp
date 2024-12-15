#include "LogFileObserver.h"
#include <fstream>
#include <iostream>
#include "NPC.h"

void LogFileObserver::update(NPC* killer, NPC* killed) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << killer->getName() << " killed " << killed->getName() << std::endl;
        logFile.close();
    }
}