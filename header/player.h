#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "inventory.h"
#include "game_map.h"

using namespace std;

class Player : public Character{
    private:
    Inventory playerInventory; // Inventory specific to the Player
        char movement;
        int currency;
        int max_health;
        
    public:
        // Player Default Constructor, 
        Player() = default;
        
        // Player Initialization Constructor
        Player(CharacterType char_type, string type, int value, int h, int d, int row, int col, int curr);
        
        // Will need more constructors for different character classes

    Inventory& getInventory(); // Accessor for Inventory

        int getCurrency() const;
        void setCurrency(int curr);
            void addCurrency(int amount);
        void heal(int amount);


        string getDisplayChar() override;
        int mod(int value, int limit);
        pair<int, int> move(char action, int height, int width);
        pair<int, int> getPosition() const;
        void setPosition(int x, int y);
        
        void attack(Character &opp) override;

        
};

#endif