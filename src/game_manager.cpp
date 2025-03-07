#include "../header/game_manager.h"
#include <iostream>

using namespace std;

struct Map {
    int width;
    int height;
    vector<vector<char>> layout; 
};

void Game_Manager::start(){
    while (!end && !*isOver) {
        while (!end && !*isOver) {
            pair<int, int> playerPos = player.getPosition();
            gameMap.printMap(playerPos.first, playerPos.second); //// Print the map
            takeAction();
            moveEnemies();
        }
    }
}

void Game_Manager::takeAction() {
    char action;
    cout << "Enter your move: ";
    cin >> action;

    if (action == 'q') {
        char choice;
        cout << endl;
        cin >> choice;
        if (choice == '1') {
            cout << "You have quit the game." << endl << endl;
            *isOver = true;
        } else if (choice == '2') {
            cout << "You have chosen not to quit the game." << endl << endl;
        }
    } else if (action == 'w' || action == 'a' || action == 's' || action == 'd') {
        // Calculate the target position
        pair<int, int> pos = player.move(action, gameMap.getHeight(), gameMap.getWidth());

        // Check if the target position is a barrier
        if (!gameMap.isTerrain(pos.first, pos.second)) {
            // Update player position if the target is not a barrier
            player.setPosition(pos.first, pos.second);
        } else {
            cout << "You cannot move onto a barrier!" << endl;
        }
    } else {
        cout << "Invalid action. Please try again." << endl;
    }
}

// void Game_Manager::takeAction(){
//     char action;
//     cout << "Enter your move: ";
//     cin >> action;
//     char choice;
// if(action == 'q'){
//         cout << endl;
//         cin >> choice;
//         if (choice == '1') {
//             cout << "You have quit the game." << endl << endl;
//             *isOver = true;
//         }
// }
//         else if (choice == '2') {
//             cout << "You have chosen not to quit the game." << endl << endl;
//         }
//          else if (action == 'w' || action == 'a' || action == 's' || action == 'd') {
//         pair<int, int> pos = player.move(action, gameMap.getHeight(), gameMap.getWidth());
        
//         // shared_ptr<Object> encounter = gameMap.getObjectAt(pos.first, pos.second);
//     //     if (encounter) {
//     //         string type = encounter->getType();
//     //     if (type == "Goblin") {
//     //             Goblin* goblin = dynamic_cast<Goblin*>(encounter.get());
//     //             if (goblin) {
//     //                 Character& character = *goblin;
//     //                 player.attack(character);
//     //             }
//     //             if (goblin->getHealth() <= 0) {
//     //                 gameMap.removeObjectAt(pos.first, pos.second);
//     //                 enemyGoal--;
//     //                 if (enemyGoal == 0) {
//     //                     cout << "You have defeated all the enemies. You win!" << endl;
//     //                     *isOver = true;
//     //                 }
//     //             }
//     //         }
//     //     else {
//     //         cout << "Invalid action. Please try again." << endl;
//     //     }
//     //     // cout << "You have quit the game." << endl << endl;
//     //     // *isOver = true;
//     // }
// }
// }



// void Game_Manager::movePlayer(char input, int new_x, int new_y){
//     //TODO
// }

// void Game_Manager::managePlayerInventory(shared_ptr<Inventory> inv){
//     //TODO
// }

void Game_Manager::moveEnemies() {
    for (auto& enemy : gameMap.getEnemies()) {
        enemy->move(gameMap); // Move each enemy
    }
}

