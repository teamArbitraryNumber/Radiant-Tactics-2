#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "inventory.h"
#include "game_map.h"

class Player : public Character{
    private:
        Inventory inventory;
        char movement;
        int currency;
        int max_health;
        
    public:
        // Player Default Constructor, 
        Player() = default;
        
        // Player Initialization Constructor
        Player(CharacterType char_type, string type, int value, int h, int d, int row, int col, Inventory& inv, int curr)    
            : Character(char_type, type, value, h, d,  row, col), inventory(inv), currency(curr), max_health(h){}
        
        // Will need more constructors for different character classes

        Inventory& getInventory();

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
