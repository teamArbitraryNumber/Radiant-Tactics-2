#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "inventory.h"
#include "game_map.h"

class Player : public Character{
    private:
        Inventory inventory;
        char movement;
        int x, y;
        int currency;
        
    public:
        // Player Constructor, 
        Player() = default;
        
        Player(Inventory& inv, int curr, int max_health)    
            : Character(CharacterType::PLAYER, "Player", 100, max_health, 10), inventory(inv), currency(curr) {}
      //                    CharacterType    ,  type   , health , max_health , damage , int x ,  int y ) 
        
        // Will need more constructors for different character classes

        Inventory& getInventory();

        int getCurrency() const;
        void setCurrency(int curr);
        void heal(int);
        Player(int x = 0, int y = 0); 


        string getDisplayChar();
        int mod(int value, int limit);
        pair<int, int> move(char action, int height, int width);
        pair<int, int> getPosition() const;
        void setPosition(int x, int y);
        
        void attack(Character &opp) override;

        
};

#endif
