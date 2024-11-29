#pragma once
#include "Visitor.h"
#include "CombatSystem.h"

class CombatVisitor : public Visitor {
    CombatSystem& combatSystem;
public:
    CombatVisitor(CombatSystem& cs);
    void visit(Squirrel& squirrel, NPC& other) override;
    void visit(Elf& elf, NPC& other) override;
    void visit(Bandit& bandit, NPC& other) override;
};
