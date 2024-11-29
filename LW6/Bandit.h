#pragma once
#include "NPC.h"

class Bandit : public NPC {
public:
    Bandit(const std::string& n, int x, int y);
    void accept(Visitor& visitor) override;
};
