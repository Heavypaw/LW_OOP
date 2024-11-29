#pragma once
#include "Observer.h"

class ScreenObserver : public Observer {
public:
    void update(const std::string& message) override;
};
