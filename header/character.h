#ifndef CHARACTER_H
#define CHARACTER_H

#include "object.h"
#include <iostream>
using namespace std;

enum class CharacterType {
    PLAYER,
    SKELETON,
    GOBLIN
};

class Character : public virtual Object {
    protected:
        int health;
        int damage;
        CharacterType charType;
        int row_pos, col_pos;
    public:
        // Default Constructor
        Character(): Object("Character", 1), health(100), damage(20) {}
        
        // Initialization Constructor
        Character(CharacterType char_type, string type, int value, int h, int d, int row, int col);
        virtual ~Character() {};
    
        // Health functions
        int getHealth() const;
        void setHealth(int h);
    
        // Damage functions
        int getDamage() const;
        void setDamage(int d);

        // Check if the character is alive
        bool isAlive() const;

        int getRowPosition() const;
        void setRowPosition(int new_row);

        int getColPosition() const;
        void setColPosition(int new_col);

        // Position functions
        // Attack function (pure virtual for polymorphism, MUST override)
        virtual void attack(Character &opp) = 0;
    };

    #endif
