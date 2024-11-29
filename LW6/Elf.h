#pragma once
#include "NPC.h"

class Elf : public NPC {
public:
    Elf(const std::string& n, int x, int y);
    void accept(Visitor& visitor) override;
};
