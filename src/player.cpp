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

void Player::move(GameMap& map, int new_row, int new_col){
    //move player to new_row,new_col and update gamemap
    Player* player = this;
    map.setObjectAt(player->row_pos, player->col_pos, nullptr);//set player's old position to null
    player->setRowPosition(new_row);
    player->setColPosition(new_col);
    map.setObjectAt(new_row, new_col, player);// set player to new position
}

string Player::getDisplayChar(){
    return "☺";
}

void Player::attack(){
    //TODO
}

