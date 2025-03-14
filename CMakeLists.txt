cmake_minimum_required(VERSION 3.14)
project(unit-test-exercise VERSION 1.0 LANGUAGES CXX)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

# C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address")


# Include directories
include_directories(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/googletest/googletest/include/
  ${CMAKE_SOURCE_DIR}/googletest/googlemock/include/
)

# Add GoogleTest
add_subdirectory(googletest)

# Main application
# add_executable(main_app src/main.cpp)

# Test executables
add_executable(game
  src/main.cpp
  src/object.cpp
  src/character.cpp
  src/enemy.cpp
  src/player.cpp
  src/game_map.cpp
  src/game_manager.cpp
  src/item.cpp
  src/inventory.cpp
  src/animation.cpp
)
target_link_libraries(game gmock gtest_main)

add_executable(tests
  tests/objectT.cpp
  src/object.cpp
  tests/game_mapT.cpp
  src/game_map.cpp
  src/object.cpp
  src/character.cpp
  src/player.cpp
  tests/playerT.cpp
  src/item.cpp
  src/inventory.cpp
  tests/inventoryT.cpp
  src/enemy.cpp
)
target_link_libraries(tests gtest gmock gtest_main)

add_executable(fun
  # tests/objectT.cpp
  src/object.cpp
  # tests/game_mapT.cpp
  src/item.cpp
  src/inventory.cpp
  src/character.cpp
  src/player.cpp
  src/main2.cpp

)
target_link_libraries(fun gtest gmock gtest_main)
