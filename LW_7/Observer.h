#pragma once

class NPC; 

class Observer {
public:
    virtual void update(NPC* killer, NPC* killed) = 0;
    virtual ~Observer() = default;
};