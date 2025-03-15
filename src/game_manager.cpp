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

void Game_Manager::displayCommands() {
    cout << "List of Commands:" << endl;
    cout << "w - Move Up" << endl;
    cout << "a - Move Left" << endl;
    cout << "s - Move Down" << endl;
    cout << "d - Move Right" << endl;
    cout << "h - Display Health" << endl;
    cout << "c - Display Currency" << endl;
    cout << "q - Quit Game" << endl;
    cout << "i - Display Inventory" << endl;
    cout << "m - Open Merchant Shop" << endl;
    cout << "v - Display Damage You Can Deal" << endl;
    cout << "z - Show This List of Commands" << endl;
}

void Game_Manager::start() {
        displayCommands(); // Show commands at the start of the game
    while (!end && !*isOver) {
        pair<int, int> playerPos = player->getPosition();
        gameMap.printMap(); //// Print the map before players move
        bool doorEntered = takeAction();// player can either quit, move, or attack
        //gameMap.printMap();//output Map after  move
        if(doorEntered == 1){ //break while loop if door is entered
            end = true;
            break;
        }      
        shared_ptr<Enemy> enemy = getAdjacentEnemy();
        // Check if the player is next to an enemy and initiate combat
        if (enemy) {
            gameMap.printMap();
            startCombat(enemy);
        }

        if (player->getPosition() != playerPos) { // Only move enemies if player moved
            moveEnemies();   // Enemies move
            enemy = getAdjacentEnemy();
        }

        
        // Check if the player is next to an enemy after enemies move
        if (enemy && enemy->getHealth() > 0) {
            gameMap.printMap();//output Map before enemies move
            startCombat(enemy);
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
            if (obj && (obj->getType() == "Skeleton" || obj->getType() == "Goblin" || obj->getType() == "Orc" || obj->getType() == "Slime" || obj->getType() == "Knight")) {
                return true;
            }
        }
    }

    return false;
}

shared_ptr<Enemy> Game_Manager::getAdjacentEnemy() {
    pair<int, int> playerPos = player->getPosition();
    int playerX = playerPos.first;
    int playerY = playerPos.second;
    int width = gameMap.getWidth();
    int height = gameMap.getHeight();

    // Check all four directions around the player, including wrap-around
    pair<int, int> possibleMoves[4] = {
        {(playerX - 1 + width) % width, playerY}, // Left (wrap-around)
        {(playerX + 1) % width, playerY},         // Right (wrap-around)
        {playerX, (playerY - 1 + height) % height}, // Up (wrap-around)
        {playerX, (playerY + 1) % height}          // Down (wrap-around)
    };

    for (int i = 0; i < 4; i++) {
        int newX = possibleMoves[i].first;
        int newY = possibleMoves[i].second;

        if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
            shared_ptr<Object> obj = gameMap.getObjectAt(newX, newY);
            if (obj && (obj->getType() == "Skeleton" || obj->getType() == "Goblin" || obj->getType() == "Orc" || obj->getType() == "Knight" || obj->getType() == "Slime")) {
                return dynamic_pointer_cast<Enemy>(obj);
            }
        }
    }

    return nullptr;
}

void Game_Manager::startCombat(shared_ptr<Enemy>& enemy) {
    cout << "Combat with " << enemy->getType() << " has started!" << endl << endl;
    bool combatOver = false;

    while (!combatOver) {
        // Player's turn
        cout << "Your turn!\t\t" << "Your Health: " << player->getHealth() << "\tEnemy Health: " << enemy->getHealth() << endl << endl;
        playerTurn();

        //Check if the enemy is defeated
        if(enemy->getHealth() <= 0){
            cout << "Enemy defeated!" << endl;
            combatOver = true;
            break;
        }
        // Check if the enemy is defeated
        if (isEnemyDefeated()) {
            cout << "Enemies defeated!" << endl;
            combatOver = true;
            return;
        }
        //Check if player is dead
        if (player->getHealth() <= 0) {
            cout << "Player defeated!" << endl;
            combatOver = true;
            *isOver = true;
            break;
        }
        // Enemy's turn
        if(enemy->getHealth() > 0){
            cout << "Enemy's turn!" << endl;
            enemyTurn();
        }
        else{
            cout << "No enemy to attack." << endl;
        }
        //cout << "Enemy's turn!" << endl;
        //enemyTurn();

        // Check if the player is defeated
        if (player->getHealth() <= 0) {
            // cout << "Player defeated!" << endl;
            combatOver = true;
            *isOver = true;
            animateGameOver(3); // Display for 5 seconds
            break;
        }
    }
}

void Game_Manager::playerTurn() {
    char action;
    if(player->getHealth() <=0){
        cout << "Player is dead and cannot attack." << endl;
        return;
    }
    cout << "Do you want to attack (a), use an item (i), or do nothing (n)? ";
    cin >> action;
    cout << endl;
    if (action == 'a') {
        // Player attacks
        pair<int, int> playerPos = player->getPosition();
        int playerX = playerPos.first;
        int playerY = playerPos.second;

        // Find the enemy next to the player
        pair<int, int> possibleMoves[4] = {
            {(playerX - 1 + gameMap.getWidth()) % gameMap.getWidth(), playerY}, // Left (wrap-around)
            {(playerX + 1) % gameMap.getWidth(), playerY},         // Right (wrap-around)
            {playerX, (playerY - 1 + gameMap.getHeight()) % gameMap.getHeight()}, // Up (wrap-around)
            {playerX, (playerY + 1) % gameMap.getHeight()}          // Down (wrap-around)
        };

        for (int i = 0; i < 4; i++) {
            int newX = possibleMoves[i].first;
            int newY = possibleMoves[i].second;

            if (newX >= 0 && newX < gameMap.getWidth() && newY >= 0 && newY < gameMap.getHeight()) {
                shared_ptr<Object> obj = gameMap.getObjectAt(newX, newY);
                if (obj && (obj->getType() == "Skeleton" || obj->getType() == "Goblin" || obj->getType() == "Orc" || obj->getType() == "Knight" || obj->getType() == "Slime") ){
                    shared_ptr<Enemy> enemy = dynamic_pointer_cast<Enemy>(obj);
                    if (enemy) {
                        player->attack(*enemy);
                        if (enemy->getHealth() <= 0) {
                            // Enemy is defeated
                            int droppedCurrency = enemy->dropCurrency();
                            player->setCurrency(player->getCurrency() + droppedCurrency); // Add currency to player
                            cout << "Enemy dropped " << droppedCurrency << " currency!" << endl;
                            gameMap.removeObjectAt(newX, newY); // Remove defeated enemy

                            cout << "Enemy defeated!" << endl;
                            // End combat immediately
                            //*isOver = true; 
                            //break;
                            return;

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
        {(playerX - 1 + gameMap.getWidth()) % gameMap.getWidth(), playerY}, // Left (wrap-around)
        {(playerX + 1) % gameMap.getWidth(), playerY},         // Right (wrap-around)
        {playerX, (playerY - 1 + gameMap.getHeight()) % gameMap.getHeight()}, // Up (wrap-around)
        {playerX, (playerY + 1) % gameMap.getHeight()}          // Down (wrap-around)
    };

    for (int i = 0; i < 4; i++) {
        int newX = possibleMoves[i].first;
        int newY = possibleMoves[i].second;

        if (newX >= 0 && newX < gameMap.getWidth() && newY >= 0 && newY < gameMap.getHeight()) {
            shared_ptr<Object> obj = gameMap.getObjectAt(newX, newY);
            if (obj && (obj->getType() == "Skeleton" || obj->getType() == "Goblin" || obj->getType() == "Orc" || obj->getType() == "Knight" || obj->getType() == "Slime")) {
                shared_ptr<Enemy> enemy = dynamic_pointer_cast<Enemy>(obj);
                //if (enemy) {
                    //enemy->attack(*player);
                    //break;
                //}
                if (enemy && enemy->getHealth() > 0) {
                    if (player->getHealth() > 0) {
                        enemy->attack(*player);
                        if (player->getHealth() <= 0) {
                            cout << "Player defeated!" << endl;
                            *isOver = true;
                            return;
                        }
                    }
                }
            }
        }
    }
}

bool Game_Manager::isEnemyDefeated() {
    // Check if all enemies are defeated
    for (const auto& enemy : gameMap.getEnemies()) {
        if (enemy->getHealth() >= 0) {
            return false;
        }
    }
    return true;
}


int Game_Manager::takeAction() {
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
        // Handle movement
        pair<int, int> currPos = player->getPosition();
        pair<int, int> pos = player->move(action, gameMap.getHeight(), gameMap.getWidth());

        if (gameMap.getMapMatrix()[pos.second][pos.first]->isDoor()) {
            return 1; // Player entered a door
        }

        // Check if the target position is a barrier or enemy
        if (!gameMap.isTerrain(pos.first, pos.second) && !gameMap.isEnemy(pos.first, pos.second)) {
            gameMap.removeObjectAt(currPos.first, currPos.second);
            gameMap.setObjectAt(pos.first, pos.second, player);
            player->setPosition(pos.first, pos.second);
        } else if (gameMap.isTerrain(pos.first, pos.second)) {
            cout << endl;
            //gameMap.printMap();
            cout << "You cannot move onto a barrier!" << endl;
        } else if (gameMap.isEnemy(pos.first, pos.second)) {
            cout << endl;
            //gameMap.printMap();
            cout << "You cannot move onto an enemy!" << endl;
        }
    } else if (action == 'x') {
        // Player wants to attack
        shared_ptr<Enemy> enemy = getAdjacentEnemy();
        if (enemy != nullptr) {
            startCombat(enemy);
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
    } else if (action == 'h') {
        // Display player health
        cout << "Player Health: " << player->getHealth() << "/" << player->max_health << endl;
    } else if (action == 'c') {
        // Display player currency
        cout << "Player Currency: " << player->getCurrency() << endl;
    } else if (action == 'm') {
        // Open merchant shop
        int currentGold = player->getCurrency();
        int newGold = player->getInventory().market(currentGold);
        player->setCurrency(newGold);
    } else if (action == 'v') {
        // Display player damage
        cout << "Player Damage: " << player->getDamage() << endl;
    } else if (action == 'z') {
        // Display list of commands
        displayCommands();
    } else {
        // Invalid action
        cout << endl;
        //gameMap.printMap();
        cout << "Invalid action. Please try again." << endl;
    }
    return 0;
}

void Game_Manager::moveEnemies() {
    for (auto& enemy : gameMap.getEnemies()) {
        enemy->move(enemy, gameMap); // Move each enemy
    }
}




