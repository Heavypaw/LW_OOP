#pragma once
#include "NPC.h"

class CombatVisitor {
public:
    void visit(NPC& attacker, NPC& defender);

private:
    int rollDice();
};