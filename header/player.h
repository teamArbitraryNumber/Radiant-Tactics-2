#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "inventory.h"
#include "game_map.h"

using namespace std;

class Player : public Character{
    private:
        shared_ptr<Inventory> inventory;
        char movement;
        int currency;
        int max_health;
        
    public:
        // Player Default Constructor, 
        Player();
        
        // Player Initialization Constructor
        Player(CharacterType char_type, string type, int value, int h, int d, int row, int col, shared_ptr<Inventory> inv, int curr);
        
        // Will need more constructors for different character classes

        shared_ptr<Inventory> getInventory();

        int getCurrency() const;
        void setCurrency(int curr);
        void heal(int amount);


        string getDisplayChar() override;
        int mod(int value, int limit);
        pair<int, int> move(char action, int height, int width);
        pair<int, int> getPosition() const;
        void setPosition(int x, int y);
        
        void attack(Character &opp) override;

        
};

#endif
