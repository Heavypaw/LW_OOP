#pragma once
#include "NPC.h"

class Squirrel : public NPC {
public:
    Squirrel(const std::string& n, int x, int y);
    void accept(Visitor& visitor) override;
};
