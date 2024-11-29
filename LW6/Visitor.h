#pragma once
#include "NPC.h"

class Visitor {
public:
    virtual void visit(Squirrel& squirrel, NPC& other) = 0;
    virtual void visit(Elf& elf, NPC& other) = 0;
    virtual void visit(Bandit& bandit, NPC& other) = 0;
};
