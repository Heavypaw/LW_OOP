cmake_minimum_required(VERSION 3.10)
project(CustomMemoryResource)

set(CMAKE_CXX_STANDARD 17)

# Find GTest
find_package(GTest REQUIRED)

# Add the main source files as a library
add_library(CustomMemoryResourceLib
    FixedBlockMemoryResource.cpp
)

# Add the main executable
add_executable(CustomMemoryResource
    main.cpp
)

# Link the main executable with the library
target_link_libraries(CustomMemoryResource CustomMemoryResourceLib)

# Add the test executable
add_executable(CustomMemoryResourceTests
    test_main.cpp
)

# Link the test executable with the library and GTest
target_link_libraries(CustomMemoryResourceTests CustomMemoryResourceLib GTest::GTest GTest::Main)

# Include directories
target_include_directories(CustomMemoryResourceLib PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories(CustomMemoryResourceTests PUBLIC ${CMAKE_SOURCE_DIR})
