#include "CombatVisitor.h"
#include <random>

void CombatVisitor::visit(NPC& attacker, NPC& defender) {
    if (!attacker.isAlive() || !defender.isAlive()) return;

    // Правила совместимости
    if ((attacker.getType() == NPCType::Elf && defender.getType() == NPCType::Bandit) ||
        (attacker.getType() == NPCType::Bandit && defender.getType() == NPCType::Squirrel) ||
        (attacker.getType() == NPCType::Squirrel && defender.getType() == NPCType::Elf)) {

        int attackRoll = rollDice();
        int defenseRoll = rollDice();

        if (attackRoll > defenseRoll) {
            defender.kill();
        } else if (defenseRoll > attackRoll) {
            attacker.kill();
        }
    }
}

int CombatVisitor::rollDice() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(1, 6);
    return dis(gen);
}