add_executable(RadiantTactics
    character.cpp
    enemy.cpp
    game_manager.cpp
    game_map.cpp
    inventory.cpp
    item.cpp
    main.cpp
    object.cpp
    player.cpp
)

add_library(simpleLibrary
    character.cpp
    enemy.cpp
    game_manager.cpp
    game_map.cpp
    inventory.cpp
    item.cpp
    main.cpp
    object.cpp
    player.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})