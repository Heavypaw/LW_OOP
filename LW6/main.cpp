#include "CombatSystem.h"
#include "NPCFactory.h"
#include "LogFileObserver.h"
#include "ScreenObserver.h"

int main() {
    CombatSystem combatSystem;
    LogFileObserver logObserver;
    ScreenObserver screenObserver;
    combatSystem.addObserver(&logObserver);
    combatSystem.addObserver(&screenObserver);

    combatSystem.addNPC(new Squirrel("Squirrely", 50, 50));
    combatSystem.addNPC(new Elf("ElvenGuard", 100, 200));
    combatSystem.addNPC(new Bandit("Bandit1", 150, 250));

    combatSystem.conductCombat(150);

    for (NPC* npc : combatSystem.npcs)
        delete npc;

    return 0;
}
