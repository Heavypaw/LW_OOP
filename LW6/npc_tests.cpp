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
#include <fstream>
#include <string>

// Helper class for NPC Accept Method Tests
class MockVisitor : public Visitor {
public:
    bool squirrelVisited = false;
    bool elfVisited = false;
    bool banditVisited = false;

    void visit(Squirrel& squirrel, NPC& other) override {
        squirrelVisited = true;
    }

    void visit(Elf& elf, NPC& other) override {
        elfVisited = true;
    }

    void visit(Bandit& bandit, NPC& other) override {
        banditVisited = true;
    }
};

// NPCFactory Tests
TEST(NPCFactoryTest, CreateSquirrel) {
    NPC* squirrel = NPCFactory::createNPC("Squirrel", "Squirrely", 50, 50);
    EXPECT_NE(squirrel, nullptr);
    EXPECT_EQ(squirrel->getType(), "Squirrel");
    EXPECT_EQ(squirrel->getName(), "Squirrely");
    EXPECT_EQ(squirrel->getX(), 50);
    EXPECT_EQ(squirrel->getY(), 50);
    delete squirrel;
}

TEST(NPCFactoryTest, CreateElf) {
    NPC* elf = NPCFactory::createNPC("Elf", "ElvenGuard", 100, 200);
    EXPECT_NE(elf, nullptr);
    EXPECT_EQ(elf->getType(), "Elf");
    EXPECT_EQ(elf->getName(), "ElvenGuard");
    EXPECT_EQ(elf->getX(), 100);
    EXPECT_EQ(elf->getY(), 200);
    delete elf;
}

TEST(NPCFactoryTest, CreateBandit) {
    NPC* bandit = NPCFactory::createNPC("Bandit", "Bandit1", 150, 250);
    EXPECT_NE(bandit, nullptr);
    EXPECT_EQ(bandit->getType(), "Bandit");
    EXPECT_EQ(bandit->getName(), "Bandit1");
    EXPECT_EQ(bandit->getX(), 150);
    EXPECT_EQ(bandit->getY(), 250);
    delete bandit;
}

TEST(NPCFactoryTest, InvalidType) {
    NPC* invalidNPC = NPCFactory::createNPC("InvalidType", "Unknown", 0, 0);
    EXPECT_EQ(invalidNPC, nullptr);
}

// CombatSystem Tests
TEST(CombatSystemTest, SquirrelKillsElf) {
    CombatSystem cs;
    cs.addNPC(new Squirrel("Squirrely", 0, 0));
    cs.addNPC(new Elf("ElvenGuard", 50, 0));
    cs.conductCombat(100);
    bool elfExists = std::any_of(cs.npcs.begin(), cs.npcs.end(), [](NPC* npc) { return npc->getType() == "Elf"; });
    EXPECT_FALSE(elfExists);
}

TEST(CombatSystemTest, ElfKillsBandit) {
    CombatSystem cs;
    cs.addNPC(new Elf("ElvenGuard", 100, 100));
    cs.addNPC(new Bandit("Bandit1", 150, 100));
    cs.conductCombat(100);
    bool banditExists = std::any_of(cs.npcs.begin(), cs.npcs.end(), [](NPC* npc) { return npc->getType() == "Bandit"; });
    EXPECT_FALSE(banditExists);
}

TEST(CombatSystemTest, BanditKillsSquirrel) {
    CombatSystem cs;
    cs.addNPC(new Bandit("Bandit1", 200, 200));
    cs.addNPC(new Squirrel("Squirrely", 250, 200));
    cs.conductCombat(100);
    bool squirrelExists = std::any_of(cs.npcs.begin(), cs.npcs.end(), [](NPC* npc) { return npc->getType() == "Squirrel"; });
    EXPECT_FALSE(squirrelExists);
}

TEST(CombatSystemTest, SameTypeNoKill) {
    CombatSystem cs;
    cs.addNPC(new Elf("ElvenGuard1", 100, 100));
    cs.addNPC(new Elf("ElvenGuard2", 150, 100));
    cs.conductCombat(100);
    int elfCount = std::count_if(cs.npcs.begin(), cs.npcs.end(), [](NPC* npc) { return npc->getType() == "Elf"; });
    EXPECT_EQ(elfCount, 2);
}

TEST(CombatSystemTest, OutOfRangeNoKill) {
    CombatSystem cs;
    cs.addNPC(new Squirrel("Squirrely", 0, 0));
    cs.addNPC(new Elf("ElvenGuard", 150, 0));
    cs.conductCombat(100);
    bool elfExists = std::any_of(cs.npcs.begin(), cs.npcs.end(), [](NPC* npc) { return npc->getType() == "Elf"; });
    EXPECT_TRUE(elfExists);
}

TEST(CombatSystemTest, ExactRangeLimit) {
    CombatSystem cs;
    cs.addNPC(new Elf("ElvenGuard", 0, 0));
    cs.addNPC(new Bandit("Bandit1", 100, 0));
    cs.conductCombat(100);
    bool banditExists = std::any_of(cs.npcs.begin(), cs.npcs.end(), [](NPC* npc) { return npc->getType() == "Bandit"; });
    EXPECT_FALSE(banditExists);
}

TEST(CombatSystemTest, JustInsideRange) {
    CombatSystem cs;
    cs.addNPC(new Squirrel("Squirrely", 0, 0));
    cs.addNPC(new Elf("ElvenGuard", 99, 0));
    cs.conductCombat(100);
    bool elfExists = std::any_of(cs.npcs.begin(), cs.npcs.end(), [](NPC* npc) { return npc->getType() == "Elf"; });
    EXPECT_FALSE(elfExists);
}

TEST(CombatSystemTest, JustOutsideRange) {
    CombatSystem cs;
    cs.addNPC(new Bandit("Bandit1", 0, 0));
    cs.addNPC(new Squirrel("Squirrely", 101, 0));
    cs.conductCombat(100);
    bool squirrelExists = std::any_of(cs.npcs.begin(), cs.npcs.end(), [](NPC* npc) { return npc->getType() == "Squirrel"; });
    EXPECT_TRUE(squirrelExists);
}

TEST(CombatSystemTest, MultipleKills) {
    CombatSystem cs;
    cs.addNPC(new Squirrel("Squirrely1", 0, 0));
    cs.addNPC(new Elf("ElvenGuard1", 50, 0));
    cs.addNPC(new Bandit("Bandit1", 150, 0));
    cs.conductCombat(150);
    bool elfExists = std::any_of(cs.npcs.begin(), cs.npcs.end(), [](NPC* npc) { return npc->getType() == "Elf"; });
    bool banditExists = std::any_of(cs.npcs.begin(), cs.npcs.end(), [](NPC* npc) { return npc->getType() == "Bandit"; });
    EXPECT_FALSE(elfExists);
    EXPECT_FALSE(banditExists);
}

// Observer Tests
TEST(ObserverTest, ScreenObserverNotification) {
    testing::internal::CaptureStdout();
    CombatSystem cs;
    ScreenObserver screenObserver;
    cs.addObserver(&screenObserver);
    cs.addNPC(new Squirrel("Squirrely", 0, 0));
    cs.addNPC(new Elf("ElvenGuard", 50, 0));
    cs.conductCombat(100);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Squirrely kills ElvenGuard"), std::string::npos);
}

TEST(ObserverTest, LogFileObserverNotification) {
    CombatSystem cs;
    LogFileObserver logObserver;
    cs.addObserver(&logObserver);
    cs.addNPC(new Bandit("Bandit1", 200, 200));
    cs.addNPC(new Squirrel("Squirrely", 250, 200));
    cs.conductCombat(100);
    std::ifstream logFile("log.txt");
    std::string content((std::istreambuf_iterator<char>(logFile)), std::istreambuf_iterator<char>());
    EXPECT_NE(content.find("Bandit1 kills Squirrely"), std::string::npos);
    // Clean up the log file
    logFile.close();
    remove("log.txt");
}

// NPC Accept Method Tests
TEST(NPCAcceptTest, SquirrelAccept) {
    MockVisitor visitor;
    Squirrel squirrel("Squirrely", 0, 0);
    squirrel.accept(visitor);
    EXPECT_TRUE(visitor.squirrelVisited);
}

TEST(NPCAcceptTest, ElfAccept) {
    MockVisitor visitor;
    Elf elf("ElvenGuard", 100, 100);
    elf.accept(visitor);
    EXPECT_TRUE(visitor.elfVisited);
}

TEST(NPCAcceptTest, BanditAccept) {
    MockVisitor visitor;
    Bandit bandit("Bandit1", 150, 150);
    bandit.accept(visitor);
    EXPECT_TRUE(visitor.banditVisited);
}

// NPC Getters Tests
TEST(NPCGettersTest, SquirrelGetters) {
    Squirrel squirrel("Squirrely", 50, 50);
    EXPECT_EQ(squirrel.getName(), "Squirrely");
    EXPECT_EQ(squirrel.getX(), 50);
    EXPECT_EQ(squirrel.getY(), 50);
    EXPECT_EQ(squirrel.getType(), "Squirrel");
}

TEST(NPCGettersTest, ElfGetters) {
    Elf elf("ElvenGuard", 100, 200);
    EXPECT_EQ(elf.getName(), "ElvenGuard");
    EXPECT_EQ(elf.getX(), 100);
    EXPECT_EQ(elf.getY(), 200);
    EXPECT_EQ(elf.getType(), "Elf");
}

TEST(NPCGettersTest, BanditGetters) {
    Bandit bandit("Bandit1", 150, 250);
    EXPECT_EQ(bandit.getName(), "Bandit1");
    EXPECT_EQ(bandit.getX(), 150);
    EXPECT_EQ(bandit.getY(), 250);
    EXPECT_EQ(bandit.getType(), "Bandit");
}
