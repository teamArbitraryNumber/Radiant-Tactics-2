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
    return "TODO";
}

void Player::attack(Character &opp){
    //TODO
}


    // private:
    //     Inventory inventory;
    //     char movement;
    //     int x, y;
    //     int currency;
        
    // public:
    //     // Player Constructor, 
    //     Player() = default;
        
    //     Player(Inventory& inv, int curr, int max_health)    
    //         : Character(CharacterType::PLAYER, "Player", 100, max_health, 10), inventory(inv), currency(curr) {}
    //   //                    CharacterType    ,  type   , value ,  health , damage , int x ,  int y ) 
        
    //     // Will need more constructors for different character classes

    //     Inventory& getInventory();

    //     int getCurrency() const;
    //     void setCurrency(int curr);
    //     void heal(int);

    //     string getDisplayChar();
    //     int mod(int value, int limit);
    //     pair<int, int> move(char action, int height, int width);
    //     pair<int, int> getPosition() const;
    //     void setPosition(int x, int y);
        
    //     void attack() override;
