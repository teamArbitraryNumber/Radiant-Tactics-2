#include "../header/character.h"

Character::Character(CharacterType char_type, string type, int value, int h, int d, int row, int col)
        : Object(type, value), health(h), damage(d), charType(char_type), row_pos(row), col_pos(col) {}

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

int Character::getRowPosition() const{
    return row_pos;
}
int Character::setRowPosition(int new_row){
    row_pos = new_row;
}  

int Character::getColPosition() const{
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

