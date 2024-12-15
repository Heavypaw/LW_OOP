#include <gtest/gtest.h>
#include "NPCFactory.h"
#include "CombatSystem.h"

TEST(NPCTest, CreateNPC) {
    auto npc = NPCFactory::createNPC(NPCType::Squirrel, 10, 20, "Squirrel1");
    EXPECT_EQ(npc->getType(), NPCType::Squirrel);
    EXPECT_EQ(npc->getX(), 10);
    EXPECT_EQ(npc->getY(), 20);
    EXPECT_EQ(npc->getName(), "Squirrel1");
}

TEST(NPCTest, CombatSimulation) {
    CombatSystem combatSystem;
    auto elf = NPCFactory::createNPC(NPCType::Elf, 0, 0, "Elf1");
    auto bandit = NPCFactory::createNPC(NPCType::Bandit, 0, 0, "Bandit1");
    combatSystem.addNPC(elf);
    combatSystem.addNPC(bandit);

    combatSystem.simulateCombat();

    EXPECT_FALSE(elf->isAlive() || bandit->isAlive());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}