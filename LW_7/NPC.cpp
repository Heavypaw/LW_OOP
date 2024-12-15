#include "NPC.h"

NPC::NPC(int x, int y, std::string name, NPCType type)
    : x(x), y(y), name(name), type(type), alive(true) {}

NPCType NPC::getType() const { return type; }
std::string NPC::getName() const { return name; }
int NPC::getX() const { return x; }
int NPC::getY() const { return y; }
bool NPC::isAlive() const { return alive; }
void NPC::kill() { alive = false; }
void NPC::move(int dx, int dy) {
    x += dx;
    y += dy;
}