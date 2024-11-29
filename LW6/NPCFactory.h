#pragma once
#include "NPC.h"
#include "Squirrel.h"
#include "Elf.h"
#include "Bandit.h"
#include "CombatSystem.h"

class NPCFactory {
public:
    static NPC* createNPC(const std::string& type, const std::string& name, int x, int y);
    static void loadNPCsFromFile(const std::string& filename, CombatSystem& cs);
};
