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
        // Constructor
        Player(Inventory& inv, int curr, int max_health) 
            : Character("Player", 0, 100, 10, 0, 0), inventory(inv), currency(curr), MAX_HEALTH(max_health);
    
        // Health functions
        int getHealth() const override;
        void setHealth(int h) override;
    
        // Damage functions
        int getDamage() const override;
        void setDamage(int d) override;
    
        // Inventory and Currency functions
        Inventory& getInventory();
        int getCurrency() const;
    
        // Player actions
        void currTurn();
        Object move(char direction, GameMap& map);
        void attack() override;
        
        // Display and interactions
        string getDisplayChar() const;
        void merchantInter();
};

#endif
