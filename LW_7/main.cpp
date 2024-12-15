#include <iostream>
#include <vector>
#include <memory>
#include "NPCFactory.h"
#include "CombatSystem.h"
#include "LogFileObserver.h"
#include "ScreenObserver.h"

int main() {
    std::cout << "Program started" << std::endl;

    // Загружаем NPC из файла
    std::cout << "Loading NPCs from file..." << std::endl;
    auto npcs = NPCFactory::loadNPCsFromFile("npcs.txt");
    std::cout << "Loaded " << npcs.size() << " NPCs." << std::endl;

    // Создаем систему боя
    CombatSystem combatSystem;
    for (const auto& npc : npcs) {
        combatSystem.addNPC(npc);
    }

    // Создаем наблюдателей
    LogFileObserver fileObserver;
    ScreenObserver screenObserver;

    // Симулируем бой
    std::cout << "Simulating combat..." << std::endl;
    combatSystem.simulateCombat();

    // Сохраняем NPC в файл
    std::cout << "Saving NPCs to file..." << std::endl;
    NPCFactory::saveNPCsToFile(npcs, "npcs_after_combat.txt");

    // Выводим выживших NPC
    std::cout << "Survivors:" << std::endl;
    for (const auto& npc : npcs) {
        if (npc->isAlive()) {
            std::cout << npc->getName() << " is alive at (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
        }
    }

    std::cout << "Program finished" << std::endl;
    return 0;
}