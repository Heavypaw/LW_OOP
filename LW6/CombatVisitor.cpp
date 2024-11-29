#include "CombatVisitor.h"

CombatVisitor::CombatVisitor(CombatSystem& cs) : combatSystem(cs) {}

void CombatVisitor::visit(Squirrel& squirrel, NPC& other) {
    if (other.getType() == "Elf") {
        combatSystem.notifyObservers(squirrel.getName() + " kills " + other.getName());
        combatSystem.removeNPC(&other);
    }
}

void CombatVisitor::visit(Elf& elf, NPC& other) {
    if (other.getType() == "Bandit") {
        combatSystem.notifyObservers(elf.getName() + " kills " + other.getName());
        combatSystem.removeNPC(&other);
    }
}

void CombatVisitor::visit(Bandit& bandit, NPC& other) {
    if (other.getType() == "Squirrel") {
        combatSystem.notifyObservers(bandit.getName() + " kills " + other.getName());
        combatSystem.removeNPC(&other);
    }
}
