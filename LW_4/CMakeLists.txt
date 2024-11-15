cmake_minimum_required(VERSION 3.10)
project(Figures)

set(CMAKE_CXX_STANDARD 17)

# Добавление исходных файлов
set(SOURCES
    main.cpp
    Figure.h
    Triangle.h
    Square.h
    Rectangle.h
    Array.h
)

# Добавление исполняемого файла
add_executable(Figures ${SOURCES})

# Добавление Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Добавление тестов
add_executable(FiguresTests tests.cpp)
target_link_libraries(FiguresTests GTest::GTest GTest::Main)

# Установка зависимостей для тестов
target_include_directories(FiguresTests PRIVATE ${CMAKE_SOURCE_DIR})