#include "object.h"
#include <iostream>
using namespace std;

class Character : public Object {
    protected:
        int health;
        int damage;
        int row_pos;
        int col_pos;

    public:
        // Constructor
        Character(string type, int value, int h, int d, int x, int y)
            : Object(type, value), health(h), damage(d), x_pos(x), y_pos(y) {}
    
        // Health functions
        int getHealth() const;
        void setHealth(int h);
    
        // Damage functions
        int getDamage() const;
        void setDamage(int d);

        // Check if the character is alive
        bool isAlive() const;
    
        // Position functions
        int getRowPosition() const;
        void setRowPosition(int rowIndex);

        int getColPosition() const;
        void setColPosition(int colIndex);
    
        // Attack function (pure virtual for polymorphism, MUST override)
        virtual void attack() = 0;
    };
