#pragma once
#include "Observer.h"

class LogFileObserver : public Observer {
public:
    void update(const std::string& message) override;
};
