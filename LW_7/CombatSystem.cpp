#include "CombatSystem.h"

void CombatSystem::addNPC(std::shared_ptr<NPC> npc) {
    npcs.push_back(npc);
}

void CombatSystem::simulateCombat() {
    for (size_t i = 0; i < npcs.size(); ++i) {
        for (size_t j = i + 1; j < npcs.size(); ++j) {
            visitor.visit(*npcs[i], *npcs[j]);
        }
    }
}