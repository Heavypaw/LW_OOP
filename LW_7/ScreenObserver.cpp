#include "ScreenObserver.h"
#include <iostream>
#include "NPC.h"

void ScreenObserver::update(NPC* killer, NPC* killed) {
    std::cout << killer->getName() << " killed " << killed->getName() << std::endl;
}