#pragma once
#include <string>

enum class NPCType {
    Squirrel,
    Elf,
    Bandit
};

class NPC {
public:
    NPC(int x, int y, std::string name, NPCType type);
    virtual ~NPC() = default;

    NPCType getType() const;
    std::string getName() const;
    int getX() const;
    int getY() const;
    bool isAlive() const;
    void kill();
    void move(int dx, int dy);

protected:
    int x, y;
    std::string name;
    NPCType type;
    bool alive;
};