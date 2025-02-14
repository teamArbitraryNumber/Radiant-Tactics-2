#include "object.h"
#include <iostream>
using namespace std;

class Character : public Object {
    protected:
        int health;
        int damage;
        int x_pos;
        int y_pos;

    public:
        // Constructor
        Character(string type, int value, int h, int d, int x, int y)
            : Object(type, value), health(h), damage(d), x_pos(x), y_pos(y) {}
    
        // Health functions
        int getHealth() const { 
            return health; 
        }
        void setHealth(int h) {
            health = h; 
        }
    
        // Damage functions
        int getDamage() const { 
            return damage; 
        }
        void setDamage(int d) { 
            damage = d; 
        }
    
        // Check if the character is alive
        bool isAlive() const { 
            return health > 0; 
        }
    
        //int mod(int a, int b) {  }
    
        // Position functions
        int getPosition() const { 
            return position; 
        }
        void setPosition(int p) { 
            position = p; 
        }
    
        // Attack function (virtual for polymorphism)
        virtual void attack() { 

        }
    };
