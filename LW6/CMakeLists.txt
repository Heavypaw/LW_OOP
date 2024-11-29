cmake_minimum_required(VERSION 3.10)
project(BalagurFate3Editor)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    NPC.cpp
    Squirrel.cpp
    Elf.cpp
    Bandit.cpp
    CombatVisitor.cpp
    LogFileObserver.cpp
    ScreenObserver.cpp
    CombatSystem.cpp
    NPCFactory.cpp
    main.cpp
)

add_executable(Editor ${SOURCE_FILES})
target_link_libraries(Editor ${GTEST_LIBRARIES})

set(TEST_FILES
    npc_tests.cpp
)

add_executable(EditorTests ${TEST_FILES})
target_link_libraries(EditorTests ${GTEST_LIBRARIES})

enable_testing()
add_test(NAME EditorTests COMMAND EditorTests)
