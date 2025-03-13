#include "../header/game_manager.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

char getch() {//needed for user to not need to hit enter when inputting
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);  // Get current terminal attributes
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);  // Disable buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();  // Read a single character
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restore original settings
    return ch;
}

struct Map {
    int width;
    int height;
    vector<vector<char>> layout; 
};


//start

void Game_Manager::start() {
    while (!end && !*isOver) {
        pair<int, int> playerPos = player->getPosition();
        gameMap.printMap(); //// Print the map before players move
        bool doorEntered = takeAction();// player can either quit, move, or attack
        if(doorEntered == 1){ //break while loop if door is entered
            end = true;
            break;
        }      

        // Check if the player is next to an enemy and initiate combat
        if (isPlayerNextToEnemy()) {
            startCombat();
        }

        if (player->getPosition() != playerPos) { // Only move enemies if player moved
            moveEnemies();   // Enemies move
            gameMap.printMap();//output Map after enemies move
        }

        // Check if the player is next to an enemy after enemies move
        if (isPlayerNextToEnemy()) {
            startCombat();
        }
    }
}

bool Game_Manager::isPlayerNextToEnemy() {
    pair<int, int> playerPos = player->getPosition();
    int playerX = playerPos.first;
    int playerY = playerPos.second;

    // Check all four directions around the player
    pair<int, int> possibleMoves[4] = {
        {playerX, playerY - 1}, // Up
        {playerX, playerY + 1}, // Down
        {playerX - 1, playerY}, // Left
        {playerX + 1, playerY}  // Right
    };

    for (int i = 0; i < 4; i++) {
        int newX = possibleMoves[i].first;
        int newY = possibleMoves[i].second;

        if (newX >= 0 && newX < gameMap.getWidth() && newY >= 0 && newY < gameMap.getHeight()) {
            shared_ptr<Object> obj = gameMap.getObjectAt(newX, newY);
            if (obj && (obj->getType() == "Skeleton" || obj->getType() == "Goblin")) {
                return true;
            }
        }
    }

    return false;
}

void Game_Manager::startCombat() {
    cout << "Combat has started!" << endl;
    bool combatOver = false;

    while (!combatOver) {
        // Player's turn
        cout << "Player's turn!" << endl;
        playerTurn();

        // Check if the enemy is defeated
        if (isEnemyDefeated()) {
            cout << "Enemy defeated!" << endl;
            combatOver = true;
            break;
        }

        // Enemy's turn
        cout << "Enemy's turn!" << endl;
        enemyTurn();

        // Check if the player is defeated
        if (player->getHealth() <= 0) {
            cout << "Player defeated!" << endl;
            combatOver = true;
            *isOver = true;
            break;
        }
    }
}

// void Game_Manager::playerTurn() {
//     char action;
//     cout << "Do you want to attack (a), use an item (i), or do nothing (n)? ";
//     cin >> action;

//     if (action == 'a') {
//         // Player attacks
//         pair<int, int> playerPos = player->getPosition();
//         int playerX = playerPos.first;
//         int playerY = playerPos.second;

//         // Find the enemy next to the player
//         pair<int, int> possibleMoves[4] = {
//             {playerX, playerY - 1}, // Up
//             {playerX, playerY + 1}, // Down
//             {playerX - 1, playerY}, // Left
//             {playerX + 1, playerY}  // Right
//         };

//         for (int i = 0; i < 4; i++) {
//             int newX = possibleMoves[i].first;
//             int newY = possibleMoves[i].second;

//             if (newX >= 0 && newX < gameMap.getWidth() && newY >= 0 && newY < gameMap.getHeight()) {
//                 shared_ptr<Object> obj = gameMap.getObjectAt(newX, newY);
//                 if (obj && (obj->getType() == "Skeleton" || obj->getType() == "Goblin")) {
//                     shared_ptr<Enemy> enemy = dynamic_pointer_cast<Enemy>(obj);
//                     if (enemy) {
//                         player->attack(*enemy);
//                         if (enemy->getHealth() <= 0) {
//                             gameMap.removeObjectAt(newX, newY); // Remove defeated enemy
//                         }
//                         break;
//                     }
//                 }
//             }
//         }
//     } else if (action == 'i') {
//         // Player uses an item from inventory
//         int healingAmount = player->getInventory().usePotion();
//         if (healingAmount > 0) {
//             player->heal(healingAmount);
//             cout << "Player healed for " << healingAmount << " HP!" << endl;
//         }
//     } else if (action == 'n') {
//         // Player does nothing
//         cout << "Player does nothing." << endl;
//     } else {
//         cout << "Invalid action. Player does nothing." << endl;
//     }
// }

void Game_Manager::playerTurn() {
    char action;
    cout << "Do you want to attack (a), use an item (i), or do nothing (n)? ";
    cin >> action;

    if (action == 'a') {
        // Player attacks
        pair<int, int> playerPos = player->getPosition();
        int playerX = playerPos.first;
        int playerY = playerPos.second;

        // Find the enemy next to the player
        pair<int, int> possibleMoves[4] = {
            {playerX, playerY - 1}, // Up
            {playerX, playerY + 1}, // Down
            {playerX - 1, playerY}, // Left
            {playerX + 1, playerY}  // Right
        };

        for (int i = 0; i < 4; i++) {
            int newX = possibleMoves[i].first;
            int newY = possibleMoves[i].second;

            if (newX >= 0 && newX < gameMap.getWidth() && newY >= 0 && newY < gameMap.getHeight()) {
                shared_ptr<Object> obj = gameMap.getObjectAt(newX, newY);
                if (obj && (obj->getType() == "Skeleton" || obj->getType() == "Goblin")) {
                    shared_ptr<Enemy> enemy = dynamic_pointer_cast<Enemy>(obj);
                    if (enemy) {
                        player->attack(*enemy);
                        if (enemy->getHealth() <= 0) {
                            // Enemy is defeated
                            int droppedCurrency = enemy->dropCurrency();
                            player->setCurrency(player->getCurrency() + droppedCurrency); // Add currency to player
                            cout << "Enemy dropped " << droppedCurrency << " currency!" << endl;
                            gameMap.removeObjectAt(newX, newY); // Remove defeated enemy
                        }
                        break;
                    }
                }
            }
        }
    } else if (action == 'i') {
        // Player uses an item from inventory
        int healingAmount = player->getInventory().usePotion();
        if (healingAmount > 0) {
            player->heal(healingAmount);
            cout << "Player healed for " << healingAmount << " HP!" << endl;
        }
    } else if (action == 'n') {
        // Player does nothing
        cout << "Player does nothing." << endl;
    } else {
        cout << "Invalid action. Player does nothing." << endl;
    }
}

void Game_Manager::enemyTurn() {
    // Enemy attacks the player
    pair<int, int> playerPos = player->getPosition();
    int playerX = playerPos.first;
    int playerY = playerPos.second;

    // Find the enemy next to the player
    pair<int, int> possibleMoves[4] = {
        {playerX, playerY - 1}, // Up
        {playerX, playerY + 1}, // Down
        {playerX - 1, playerY}, // Left
        {playerX + 1, playerY}  // Right
    };

    for (int i = 0; i < 4; i++) {
        int newX = possibleMoves[i].first;
        int newY = possibleMoves[i].second;

        if (newX >= 0 && newX < gameMap.getWidth() && newY >= 0 && newY < gameMap.getHeight()) {
            shared_ptr<Object> obj = gameMap.getObjectAt(newX, newY);
            if (obj && (obj->getType() == "Skeleton" || obj->getType() == "Goblin")) {
                shared_ptr<Enemy> enemy = dynamic_pointer_cast<Enemy>(obj);
                if (enemy) {
                    enemy->attack(*player);
                    break;
                }
            }
        }
    }
}

bool Game_Manager::isEnemyDefeated() {
    // Check if all enemies are defeated
    for (const auto& enemy : gameMap.getEnemies()) {
        if (enemy->getHealth() > 0) {
            return false;
        }
    }
    return true;
}


int Game_Manager::takeAction() {//returns 1 if player tries moving to door, 0 otherwise
    //char action;
    cout << "Enter your move (w, a, s, d), attack (x), use item (i), or quit (q): ";
    char action = getch();

    cout << endl;

    if (action == 'q') {
        char choice;
        cout << endl;
        cout << "Would you like to quit the game? (enter 1 for yes, and anything else for no)" << endl;
        choice = getch();
        if (choice == '1') {
            cout << "You have quit the game." << endl << endl;
            *isOver = true;
        } else {
            cout << "You have chosen not to quit the game." << endl << endl;
        }
    } else if (action == 'w' || action == 'a' || action == 's' || action == 'd') {
        pair<int, int> currPos = player->getPosition();
        pair<int, int> pos = player->move(action, gameMap.getHeight(), gameMap.getWidth());

        if(gameMap.getMapMatrix()[pos.second][pos.first]->isDoor()){ 
            return 1; 
        } // return 
        // Check if the target position is a barrier or enemy

        if (!gameMap.isTerrain(pos.first, pos.second) && !gameMap.isEnemy(pos.first, pos.second)) {
            gameMap.removeObjectAt(currPos.first, currPos.second);
            gameMap.setObjectAt(pos.first, pos.second, player);
            player->setPosition(pos.first, pos.second);
        } else if (gameMap.isTerrain(pos.first, pos.second)) {
            cout << endl;
            gameMap.printMap();
            cout << "You cannot move onto a barrier!" << endl;
        } else if (gameMap.isEnemy(pos.first, pos.second)) {
            cout << endl;
            gameMap.printMap();
            cout << "You cannot move onto an enemy!" << endl;
        }
    } else if (action == 'x') {
        // Player wants to attack
        if (isPlayerNextToEnemy()) {
            startCombat();
        } else {
            cout << "No enemy nearby to attack!" << endl;
        }
    } else if (action == 'i') {
        // Player wants to use an item
        int healingAmount = player->getInventory().usePotion();
        if (healingAmount > 0) {
            player->heal(healingAmount);
            cout << "Player healed for " << healingAmount << " HP!" << endl;
        }
    } else {
        cout << endl;
        gameMap.printMap();
        cout << "Invalid action. Please try again." << endl;
    }
    return 0;
}

void Game_Manager::moveEnemies() {
    for (auto& enemy : gameMap.getEnemies()) {
        enemy->move(enemy, gameMap); // Move each enemy
    }
}




