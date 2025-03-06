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

    }
}
}

// void Game_Manager::takeAction(){
//     char action;
//     cout << "Enter your move: ";
//     cin >> action;
//     pair<int, int> playerPos = player.getPosition();
//     pair<int, int> newPos = player.move(action, gameMap.getHeight(), gameMap.getWidth());
//     char whatIsThis = gameMap.getObjectAt(newPos.first, newPos.second)->getDisplayChar();
//     if (whatIsThis == 'E') {
//         movePlayer(whatIsThis, newPos.first, newPos.second);
//     } else if (whatIsThis == 'I') {
//         managePlayerInventory(inventory);
//     } else {
//         movePlayer(whatIsThis, newPos.first, newPos.second);
//     }
// }

void Game_Manager::takeAction(){
    char action;
    cout << "Enter your move: ";
    cin >> action;
if(action == 'q'){
        cout << endl;
        char choice;
        cin >> choice;
        if (choice == '1') {
            cout << "You have quit the game." << endl << endl;
            *isOver = true;
        }
        else if (choice == '2') {
            cout << "You have chosen not to quit the game." << endl << endl;
        }
        else {
            cout << "Invalid action. Please try again." << endl;
        }
        // cout << "You have quit the game." << endl << endl;
        // *isOver = true;
    }
}

void Game_Manager::movePlayer(char input, int new_x, int new_y){
    //TODO
}

void Game_Manager::managePlayerInventory(shared_ptr<Inventory> inv){
    //TODO
}

void moveEnemies(){
    //TODO
}


// class Game_Manager{
//     private:
//         GameMap gameMap;
//         bool isPlayerTurn;
//         void initMap1();
//         void startLevel();
//         void start();
//         void takeAction();
//         GameMap& getGameMap();
//         void movePlayer(char whatIsThis, int new_x, int new_y);
//         void managePlayerInventory(Inventory& inv);
//         void moveEnemies();