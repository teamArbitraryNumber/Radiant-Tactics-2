#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
using namespace std;

class Enemy : public Character {
protected:
    string enemyType;

public:
    Enemy(string type, int health, int damage, int x, int y);

    // Movement
    void move(GameMap& map);

    // Attack
    void attack() override;

    // Display character
    string getDisplayChar() const;
};

// Specific Enemy Types
class Skeleton : public Enemy {
public:
    Skeleton(int x, int y);
};

class Goblin : public Enemy {
public:
    Goblin(int x, int y);
};

#endif
