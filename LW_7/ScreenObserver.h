#pragma once
#include "Observer.h"

class ScreenObserver : public Observer {
public:
    void update(NPC* killer, NPC* killed) override;
};