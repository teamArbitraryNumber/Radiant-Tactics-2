# cmake_minimum_required(VERSION 3.2)
# project(unit-test-exercise)

# # Output directories
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

# # C++ flags
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

# # Include directories
# include_directories(
#   ${CMAKE_SOURCE_DIR}/include
#   ${CMAKE_SOURCE_DIR}/header
#   ${CMAKE_SOURCE_DIR}/test/lib/googletest/include/
#   ${CMAKE_SOURCE_DIR}/test/lib/googlemock/include/
# )

# # Link directories
# link_directories(${LIBRARY_OUTPUT_PATH})

# add_subdirectory(googletest)
# add_subdirectory(src)
# add_subdirectory(tests)

# # Define libraries
# # file(GLOB CHARACTER_HEADERS ${CMAKE_SOURCE_DIR}/Character_header/*.h)
# # add_library(CharacterLib STATIC ${CHARACTER_HEADERS})

# # file(GLOB ADDIT_HEADERS ${CMAKE_SOURCE_DIR}/addit_header/*.h)
# # add_library(AdditLib STATIC ${ADDIT_HEADERS})

# # Main application
# # add_executable(main_app main.cpp)
# # target_link_libraries(main_app CharacterLib AdditLib)

# # Test executables for character_tests
# add_executable(character_tests
#   src/object.cpp
#   src/character.cpp
#   src/enemy.cpp
#   src/game_map.cpp
#   src/game_manager.cpp
#   src/item.cpp
#   src/player.cpp
#   src/inventory.cpp
# )
# target_link_libraries(character_tests gtest gmock gtest_main)
# # # # target_link_libraries(Character_tests CharacterLib AdditLib gtest gmock)

# # # Test executables for addit_tests
# # add_executable(addit_tests
# #   addit_tests/GameMaptest.cpp
# #   addit_tests/Objecttest.cpp
# #   addit_tests/Potionstest.cpp
# #   addit_tests/PowersTest.cpp
# #   addit_tests/Swordstest.cpp
# #   addit_tests/LevelsTest.cpp
# #   addit_tests/Inventorytest.cpp
# #   addit_src/GameMap.cpp
# #   addit_src/Object.cpp
# #   addit_src/Potions.cpp
# #   addit_src/Powers.cpp
# #   addit_src/Swords.cpp
  
# #   addit_src/Level.cpp
# #   addit_src/Inventory.cpp
# #   addit_tests/LevelsTest.cpp
# #   addit_src/MenuPrinter.cpp
# #   Character_tests/Character_tests.cpp
# #   Character_tests/Mainchartests.cpp
# #   Character_tests/Goblintests.cpp
# #   Character_src/Character.cpp
# #   Character_src/MainCharacter.cpp
# #   Character_src/Goblin.cpp
# # )
# # target_link_libraries(addit_tests gtest gmock gtest_main)

# # add_executable(game
# #   addit_src/GameMap.cpp
# #   addit_src/Inventory.cpp
# #   addit_src/Level.cpp
# #   addit_src/MenuPrinter.cpp
# #   addit_src/Object.cpp
# #   addit_src/Potions.cpp
# #   addit_src/Powers.cpp
#   addit_src/Swords.cpp
#   Character_src/Character.cpp
#   Character_src/Goblin.cpp
#   Character_src/MainCharacter.cpp
#   main.cpp


  # addit_tests/LevelsTest.cpp
#)
# # target_link_libraries(addit_tests gtest gmock gtest_main)
# target_link_libraries(addit_tests gtest gmock gtest_main)

# # Enable testing
# enable_testing()


# Register tests with CTest
# add_test(NAME CharacterTests COMMAND Character_tests)
# add_test(NAME AdditTests COMMAND addit_tests)
# add_subdirectory(addit_tests)
# add_subdirectory(Character_tests)
# add_subdirectory(addit_header)
# add_subdirectory(Character_header)
