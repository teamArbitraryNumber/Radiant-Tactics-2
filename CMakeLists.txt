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
)
target_link_libraries(game gmock gtest_main)

add_executable(tests
  # tests/objectT.cpp
  # src/object.cpp
  # tests/game_mapT.cpp
  src/game_map.cpp
  src/object.cpp
  src/character.cpp
  src/player.cpp
  tests/playerT.cpp

)
target_link_libraries(tests gtest gmock gtest_main)
