#pragma once
#include <vector>
#include <memory>
#include "NPC.h"
#include "CombatVisitor.h"

class CombatSystem {
public:
    void addNPC(std::shared_ptr<NPC> npc);
    void simulateCombat();

private:
    std::vector<std::shared_ptr<NPC>> npcs;
    CombatVisitor visitor;
};