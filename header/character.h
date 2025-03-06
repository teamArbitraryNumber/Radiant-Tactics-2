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
        // Constructor
        Character(): Object("Null", 1), health(100), damage(20) {}
        Character(CharacterType char_type, string type, int value, int h, int d)
            : Object(type, value), health(h), damage(d) {}
        virtual ~Character() {};
    
        // Health functions
        int getHealth() const;
        void setHealth(int h);
    
        // Damage functions
        int getDamage() const;
        void setDamage(int d);

        // Check if the character is alive
        bool isAlive() const;

        int getRowPosition();
        int setRowPosition(int new_row);

        int getColPosition();
        int setColPosition(int new_col);



    
        // Position functions
        // Attack function (pure virtual for polymorphism, MUST override)
        virtual void attack(Character &opp);
    };

    #endif
