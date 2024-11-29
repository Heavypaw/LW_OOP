#include "Bandit.h"

Bandit::Bandit(const std::string& n, int x, int y)
    : NPC(n, x, y, "Bandit") {}

void Bandit::accept(Visitor& visitor) { visitor.visit(*static_cast<Bandit*>(this), *this); }
