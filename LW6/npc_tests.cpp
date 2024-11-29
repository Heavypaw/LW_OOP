#include <gtest/gtest.h>
#include "NPC.h"
#include "Squirrel.h"
#include "Elf.h"
#include "Bandit.h"
#include "NPCFactory.h"
#include "CombatSystem.h"
#include "CombatVisitor.h"
#include "LogFileObserver.h"
#include "ScreenObserver.h"

TEST(NPCFactoryTest, CreateSquirrel) {
    NPC* squirrel = NPCFactory::createNPC("Squirrel", "Squirrely", 50, 50);
    EXPECT_NE(squirrel, nullptr);
    EXPECT_EQ(squirrel->getType(), "Squirrel");
    EXPECT_EQ(squirrel->getName(), "Squirrely");
    EXPECT_EQ(squirrel->getX(), 50);
    EXPECT_EQ(squirrel->getY(), 50);
    delete squirrel;
}

// Add more tests for Elf, Bandit, CombatSystem, etc.
