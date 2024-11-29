#include "CombatSystem.h"
#include <cmath>

void CombatSystem::addNPC(NPC* npc) { npcs.push_back(npc); }

void CombatSystem::removeNPC(NPC* npc) {
    npcs.erase(std::remove(npcs.begin(), npcs.end(), npc), npcs.end());
}

void CombatSystem::addObserver(Observer* observer) { observers.push_back(observer); }

void CombatSystem::removeObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void CombatSystem::notifyObservers(const std::string& message) {
    for (auto observer : observers)
        observer->update(message);
}

void CombatSystem::conductCombat(int range) {
    for (size_t i = 0; i < npcs.size(); ++i) {
        for (size_t j = i + 1; j < npcs.size(); ++j) {
            NPC* npc1 = npcs[i];
            NPC* npc2 = npcs[j];
            double distance = std::sqrt(std::pow(npc1->getX() - npc2->getX(), 2) +
                                        std::pow(npc1->getY() - npc2->getY(), 2));
            if (distance <= range) {
                CombatVisitor cv(*this);
                npc1->accept(cv);
                npc2->accept(cv);
            }
        }
    }
}
