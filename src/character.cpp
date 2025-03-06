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

int Character::getRowPosition(){
    return row_pos;
}
int Character::setRowPosition(int new_row){
    row_pos = new_row;
}  

int Character::getColPosition(){
    return col_pos;
}
int Character::setColPosition(int new_col){
    col_pos = new_col;
}

void Character::attack(Character &opp){
    // if (!enemy.isalive()) {
    //     std::cout << name << " is already defeated! " << enemy.getType() << " cannot attack.\n";
    //     return;
    // }
    // std::cout << name << " attacks " << enemy.getType() << attackAmount << " hits!\n";
    // enemy.receiveDamage(attackAmount);
    // if (!enemy.isalive()) {
    //     std::cout << enemy.getType()<< " has been defeated!\n";
    // }
}

