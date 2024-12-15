#include "NPCFactory.h"
#include "Squirrel.h"
#include "Elf.h"
#include "Bandit.h"
#include <fstream>
#include <sstream>

std::shared_ptr<NPC> NPCFactory::createNPC(NPCType type, int x, int y, std::string name) {
    switch (type) {
        case NPCType::Squirrel: return std::make_shared<Squirrel>(x, y, name);
        case NPCType::Elf: return std::make_shared<Elf>(x, y, name);
        case NPCType::Bandit: return std::make_shared<Bandit>(x, y, name);
        default: throw std::invalid_argument("Invalid NPC type");
    }
}

std::vector<std::shared_ptr<NPC>> NPCFactory::loadNPCsFromFile(const std::string& filename) {
    std::vector<std::shared_ptr<NPC>> npcs;
    std::ifstream file(filename);
    if (!file.is_open()) return npcs;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string typeStr, name;
        int x, y;
        iss >> typeStr >> x >> y >> name;
        NPCType type = typeStr == "Squirrel" ? NPCType::Squirrel :
                       typeStr == "Elf" ? NPCType::Elf : NPCType::Bandit;
        npcs.push_back(createNPC(type, x, y, name));
    }
    return npcs;
}

void NPCFactory::saveNPCsToFile(const std::vector<std::shared_ptr<NPC>>& npcs, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) return;

    for (const auto& npc : npcs) {
        file << (npc->getType() == NPCType::Squirrel ? "Squirrel" :
                 npc->getType() == NPCType::Elf ? "Elf" : "Bandit")
             << " " << npc->getX() << " " << npc->getY() << " " << npc->getName() << std::endl;
    }
}