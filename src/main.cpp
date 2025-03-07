#include "../header/game_manager.h"
#include <iostream>
using namespace std;

bool startMenu()
{
    cout << "Welcome to Radiant Tactics: Dungeon Crawler!" << endl << endl;
    cout << "Would you like to start a game? (type 'y' for yes or 'n' for no)" << endl;
    string input;
    getline(cin, input);

    while (input != "y" && input != "n")
    {
        cout << "invalid input: (type 'y' for yes or 'n' for no)" << endl;
        getline(cin, input);
    }

    if (input == "y")
    {
        return true;
    }

    return false;
}

int main(){
    if(startMenu()){
        Game_Manager gameManager;
    // Start the game
    gameManager.start();

    // Main game loop
        while (true) {
            gameManager.takeAction(); // Handle player and enemy actions

            // Check if the game is over
            if (gameManager.isOver) {
                cout << "Game Over!" << endl;
                break;
            }
        }
    }
    
    return 0;
}