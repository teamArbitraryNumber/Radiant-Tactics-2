#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "game_map.h"
using namespace std;

class Enemy : public Character {
protected:
    string enemyType;

public:
    Enemy(CharacterType char_type, string type, int value, int h, int d, int row, int col);

    // Movement
    void move(GameMap& map);

    // Attack
    void attack(Character &) override;

    // Display character
    string getDisplayChar() const;
};

// Specific Enemy Types
class Skeleton : public Enemy {
public:
    Skeleton();
};

class Goblin : public Enemy {
public:
    Goblin();
};

#endif
