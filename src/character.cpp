#include "../header/character.h"

// Health functions
int Character::getHealth() const { 
    return health; 
}
void Character::setHealth(int h) {
    health = h; 
}

// Damage functions
int Character::getDamage() const { 
    return damage; 
}
void Character::setDamage(int d) { 
    damage = d; 
}

// Check if the character is alive
bool Character::isAlive() const { 
    return health > 0; 
}

//int mod(int a, int b) {  }

// Position functions
int Character::getRowPosition() const { 
    return row_pos; 
}
void Character::setRowPosition(int rowIndex) { 
    row_pos = rowIndex; 
}

int Character::getColPosition() const{
    return col_pos;
}
void Character::setColPosition(int colIndex){
    col_pos = colIndex;
}
