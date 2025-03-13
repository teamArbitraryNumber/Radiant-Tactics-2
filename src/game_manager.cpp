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

void Game_Manager::start(){
    while (!end && !*isOver) {
        pair<int, int> playerPos = player->getPosition();
        gameMap.printMap(); //// Print the map before players move
        bool doorEntered = takeAction();// player can either quit or move
        if(doorEntered == 1){ //break while loop if door is entered
            end = true;
            break;
        }
        //player.attack()      player attacks after move
        if(player->getPosition() != playerPos){// only move enemies if player moved
            moveEnemies();   // enemies move
        }
        //enemies.attack()    enemies attack after their move
    }
}

int Game_Manager::takeAction() {//returns 1 if player tries moving to door, 0 otherwise
    //char action;
    cout << "Enter your move (w, a, s, d) or (q) to quit: ";
    //cin >> action;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer, (without this if player enters ww, they move up twice, etc.)
    char action = getch();
    cout << endl;
    if (action == 'q') {
        char choice;
        cout << endl;
        cout << "Would you like to quit the game? (enter 1 for yes, and anything else for no)" << endl;
        //cin >> choice;
        choice = getch();
        if (choice == '1') {
            cout << "You have quit the game." << endl << endl;
            *isOver = true;
        } else if (choice == '2') {
            cout << "You have chosen not to quit the game." << endl << endl;
        }
    } 
    else if (action == 'w' || action == 'a' || action == 's' || action == 'd') {
        // Calculate the target position
        pair<int, int> currPos = player->getPosition();
        pair<int, int> pos = player->move(action, gameMap.getHeight(), gameMap.getWidth());
        if(gameMap.getMapMatrix()[pos.second][pos.first]->isDoor()){ 
            return 1; 
        } // return 
        // Check if the target position is a barrier or enemy
        if (!gameMap.isTerrain(pos.first, pos.second) && !gameMap.isEnemy(pos.first, pos.second)) {
            // Update player position if the target is not a barrier
            gameMap.removeObjectAt(currPos.first, currPos.second);
            gameMap.setObjectAt(pos.first, pos.second, player);
            player->setPosition(pos.first, pos.second);
        }
        else if(gameMap.isTerrain(pos.first, pos.second)){//object is terrain
            cout << endl;
            gameMap.printMap(); //print map after players move
            cout << "You cannot move onto a barrier!" << endl;
        }
        else if(gameMap.isEnemy(pos.first, pos.second)){//object is an enemy
            cout << endl;
            gameMap.printMap(); //print map after players move
            cout << "You cannot move onto an enemy!" << endl;
        }
    } else {
        cout << endl;
        gameMap.printMap(); //print map after players move
        cout << "Invalid action. Please try again." << endl;
    }
    return 0;
}



// void Game_Manager::movePlayer(char input, int new_x, int new_y){
//     //TODO
// }

// void Game_Manager::managePlayerInventory(shared_ptr<Inventory> inv){
//     //TODO
// }

void Game_Manager::moveEnemies() {
    for (auto& enemy : gameMap.getEnemies()) {
        enemy->move(enemy, gameMap); // Move each enemy
    }
}

