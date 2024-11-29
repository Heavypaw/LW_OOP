#include "NPC.h"

NPC::NPC(const std::string& n, int xCoord, int yCoord, const std::string& t)
    : name(n), x(xCoord), y(yCoord), type(t) {}

NPC::~NPC() = default;

std::string NPC::getName() const { return name; }
int NPC::getX() const { return x; }
int NPC::getY() const { return y; }
std::string NPC::getType() const { return type; }
