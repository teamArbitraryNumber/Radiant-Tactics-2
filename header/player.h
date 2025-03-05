#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "inventory.h"
#include "game_map.h"

class Player : public Character{
    private:
        Inventory inventory;
        int currency;
        
    public:
        // Player Constructor, 
        
        Player(Inventory& inv, int curr, int max_health)    
            : Character(CharacterType::PLAYER, "Player",   0   ,    100  ,    10  ,   0   ,    0   ), inventory(inv), currency(curr) {}
      //                    CharacterType    ,  type   , value ,  health , damage , int x ,  int y ) 
        
        // Will need more constructors for different character classes

        Inventory& getInventory();

        int getCurrency() const;
        void setCurrency(int curr);

        void move(GameMap& map, int new_row, int new_col);

        string getDisplayChar();
        

        void attack() override;

        
};

#endif
