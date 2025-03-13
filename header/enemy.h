#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class GameMap;

using namespace std;

class Enemy : public Character {
protected:
    string enemyType;

public:
    Enemy(CharacterType char_type, string type, int value, int h, int d, int row, int col);

    int mod(int value, int limit);
    // Movement
    void move(shared_ptr<Enemy>& enemy, GameMap& map);

    // Attack
    void attack(Character &) override;
};

// Specific Enemy Types
class Skeleton : public Enemy {
public:
    Skeleton();
    Skeleton(CharacterType charType, string type,  int value,  int h,   int d  ,  int row, int col );
    string getDisplayChar() override;
};

class Goblin : public Enemy {
public:
    Goblin();
    Goblin(CharacterType charType, string type,  int value,  int h,   int d  ,  int row, int col );
    string getDisplayChar() override;
};

#endif