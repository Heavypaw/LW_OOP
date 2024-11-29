#include "Elf.h"

Elf::Elf(const std::string& n, int x, int y)
    : NPC(n, x, y, "Elf") {}

void Elf::accept(Visitor& visitor) { visitor.visit(*static_cast<Elf*>(this), *this); }
