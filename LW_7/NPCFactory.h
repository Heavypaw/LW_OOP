#pragma once
#include <memory>
#include <vector>
#include "NPC.h"

class NPCFactory {
public:
    static std::shared_ptr<NPC> createNPC(NPCType type, int x, int y, std::string name);
    static std::vector<std::shared_ptr<NPC>> loadNPCsFromFile(const std::string& filename);
    static void saveNPCsToFile(const std::vector<std::shared_ptr<NPC>>& npcs, const std::string& filename);
};