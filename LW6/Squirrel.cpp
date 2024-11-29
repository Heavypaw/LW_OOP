#include "Squirrel.h"

Squirrel::Squirrel(const std::string& n, int x, int y)
    : NPC(n, x, y, "Squirrel") {}

void Squirrel::accept(Visitor& visitor) { visitor.visit(*static_cast<Squirrel*>(this), *this); }
