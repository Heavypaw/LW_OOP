#include "NPCFactory.h"

NPC* NPCFactory::createNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "Squirrel") return new Squirrel(name, x, y);
    if (type == "Elf") return new Elf(name, x, y);
    if (type == "Bandit") return new Bandit(name, x, y);
    return nullptr;
}

void NPCFactory::loadNPCsFromFile(const std::string& filename, CombatSystem& cs) {
    std::ifstream infile(filename);
    std::string line;
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, ',')) tokens.push_back(token);
        if (tokens.size() != 4) continue;
        std::string type = tokens[0];
        std::string name = tokens[1];
        int x = std::stoi(tokens[2]);
        int y = std::stoi(tokens[3]);
        NPC* npc = createNPC(type, name, x, y);
        if (npc) cs.addNPC(npc);
    }
}
