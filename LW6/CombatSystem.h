#pragma once
#include "NPC.h"
#include "Observer.h"
#include "CombatVisitor.h"
#include <vector>

class CombatSystem {
private:
    std::vector<NPC*> npcs;
    std::vector<Observer*> observers;
public:
    void addNPC(NPC* npc);
    void removeNPC(NPC* npc);
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers(const std::string& message);
    void conductCombat(int range);
};
