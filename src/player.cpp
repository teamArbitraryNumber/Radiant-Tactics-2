#include "../header/player.h"
#include <iostream>

using namespace std;

Player::Player(CharacterType char_type, string type, int value, int h, int d, int row, int col, int curr)    

    : Character(char_type, type, value, h, d,  row, col), currency(curr), max_health(h){}

Player::Player(PlayerType pType, CharacterType char_type, string type, int value, int h, int d, int row, int col, int curr) 
    : Character(char_type, type, value, h, d,  row, col), currency(curr), max_health(h), playerType(pType){}
    

int Player::mod(int value, int limit){
    return (value % limit + limit ) % limit;
}

pair<int, int> Player::move(char action, int height, int width){
    int newX = getColPosition(), newY = getRowPosition();
    if (action == 'w') { // Move up
        newY = mod(newY - 1, height);
    } else if (action == 's') { // Move down
        newY = mod(newY + 1, height);
    } else if (action == 'a') { // Move left
        newX = mod(newX - 1, width);
    } else if (action == 'd') { // Move right
        newX = mod(newX + 1, width);
    }
    

    return {newX, newY};//{newX, newY};
    //      col , row
}

pair<int, int> Player::getPosition() const{
    int row = getRowPosition();
    int col = getColPosition();
    return {col, row};
}

void Player::setPosition(int newX, int newY){
    // cout << "the player is moved to " << newX << " " << newY << endl;
    setColPosition(newX);
    setRowPosition(newY);
}

void Player::heal(int amount){
    if(health + amount <= max_health){
        health = health + amount;
    }
    else{
        health = max_health;
    }
    
}
PlayerType Player::getPlayerType() const {
    return playerType;
}

Inventory& Player::getInventory() {
    return playerInventory;
}

int Player::getCurrency() const{
    return currency;
}
void Player::setCurrency(int curr){
    currency = curr;
}

string Player::getDisplayChar(){
    switch (playerType) {
        case PlayerType::WARRIOR:
            return "🛡️"; // Warrior symbol
        case PlayerType::MAGE:
            return "🧙"; // Mage symbol
        case PlayerType::ROGUE:
            return "🥷"; // Rogue symbol
        case PlayerType::GOD:
            return "👑";
        default:
            return "👼"; // Default symbol
    }
}

// In Player class
void Player::attack(Character &target) {
    /*int damage = getDamage(); // Assuming getDamage() returns the player's damage
    target.setHealth(target.getHealth() - damage);
    cout << "Player attacks for " << damage << " damage!" << endl;*/
    if (getHealth() <= 0) {
        cout << "Player is dead and cannot attack." << endl;
        return;
    }

    if (target.getHealth() <= 0) {
        cout << "Target is already dead." << endl;
        return;
    }

    int damage = getDamage(); // Assuming getDamage() returns the player's damage
    int newHealth = target.getHealth() - damage;
    target.setHealth(newHealth < 0 ? 0 : newHealth); // Ensure health doesn't go below 0

    cout << "Player attacks for " << damage << " damage!" << endl;
}

void Player::addCurrency(int amount) {
    currency += amount;
    cout << "You gained " << amount << " currency! Total: " << currency << endl;
}


