#pragma once
#include <string>

class Visitor;

class NPC {
protected:
    std::string name;
    int x, y;
    std::string type;
public:
    NPC(const std::string& n, int xCoord, int yCoord, const std::string& t);
    virtual ~NPC() = 0;
    virtual void accept(Visitor& visitor) = 0;
    std::string getName() const;
    int getX() const;
    int getY() const;
    std::string getType() const;
};
