#include "../header/player.h"

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
    return "placeholder";
}

