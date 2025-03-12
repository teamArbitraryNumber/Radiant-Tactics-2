#include "../header/player.h"
#include <iostream>

using namespace std;

Player::Player(CharacterType char_type, string type, int value, int h, int d, int row, int col, int curr)    
    : Character(char_type, type, value, h, d,  row, col), currency(curr), max_health(h){}
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
    health = health + amount;
}

// shared_ptr<Inventory> Player::getInventory(){
//     return inventory;
// }

int Player::getCurrency() const{
    return currency;
}
void Player::setCurrency(int curr){
    currency = curr;
}

string Player::getDisplayChar(){
    return "👼";
}

void Player::attack(Character &opp){
    cout << "we attacked";
    //TODO
}