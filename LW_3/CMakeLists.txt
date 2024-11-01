cmake_minimum_required(VERSION 3.10)
project(Figures)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    main.cpp
    figure.h
    triangle.h
    square.h
    rectangle.h
    array.h
)

add_executable(Figures ${SOURCES})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(FiguresTests tests.cpp)
target_link_libraries(FiguresTests GTest::GTest GTest::Main)

target_include_directories(FiguresTests PRIVATE ${CMAKE_SOURCE_DIR})
