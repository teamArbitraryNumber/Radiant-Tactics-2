#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "inventory.h"

class Player : public Character{
    private:
        Inventory inventory;
        int currency;
        static const int MAX_HEALTH;
        
    public:
        // Player Constructor, 
        
        Player(Inventory& inv, int curr, int max_health)    
            : Character(CharacterType::PLAYER, "Player",   0   ,    100  ,    10  ,   0   ,    0   ), inventory(inv), currency(curr), MAX_HEALTH(max_health) {}
                      //    CharacterType    ,  type   , value ,  health , damage , int x ,  int y ) 
        
        // Will need more constructors for different character classes

        Inventory& getInventory();

        int getCurrency() const;
        void setCurrency(int curr);

        string getDisplayChar();

        
        void attack() override;

        
};

#endif
