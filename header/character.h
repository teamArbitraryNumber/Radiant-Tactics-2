#ifndef CHARACTER_H
#define CHARACTER_H

#include "object.h"
#include <iostream>
using namespace std;

enum class CharacterType {
    PLAYER,
    ORC,
    SKELETON,
    MAGE,
    BANDIT,
    DRAGON
};

class Character : public virtual Object {
    protected:
        int health;
        int damage;
        CharacterType charType;
    public:
        // Constructor
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
    
        // Position functions
        // Attack function (pure virtual for polymorphism, MUST override)
        virtual void attack() = 0;
    };

    #endif
