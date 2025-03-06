#include "../header/player.h"
#include <iostream>

using namespace std;

Player::Player(int x, int y) : x(x), y(y) {}

int Player::mod(int value, int limit){
    return (value % limit + limit ) % limit;
}

pair<int, int> Player::move(char action, int height, int width){
    int newX = x, newY = y;
    if (action == 'w') { // Move up
        newY = mod(y - 1, height);
    } else if (action == 's') { // Move down
        newY = mod(y + 1, height);
    } else if (action == 'a') { // Move left
        newX = mod(x - 1, width);
    } else if (action == 'd') { // Move right
        newX = mod(x + 1, width);
    }

    setPosition(newX, newY);

    return {newX, newY};
}

pair<int, int> Player::getPosition() const{
    return {x, y};
}

void Player::setPosition(int newX, int newY){
    // cout << "the player is moved to " << newX << " " << newY << endl;
        x = newX;
    y = newY;
}

void Player::heal(int amount){
    health = health + amount;
}

Inventory& Player::getInventory(){
    return inventory;
}

int Player::getCurrency() const{
    return currency;
}
void Player::setCurrency(int curr){
    currency = curr;
}

string Player::getDisplayChar(){
    return "☺";
}

void Player::attack(Character &opp){
    
    //TODO
}
