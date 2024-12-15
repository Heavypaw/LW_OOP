#pragma once
#include "Observer.h"

class LogFileObserver : public Observer {
public:
    void update(NPC* killer, NPC* killed) override;
};