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
    string getDisplayChar() override;
};

class Goblin : public Enemy {
public:
    Goblin();
    string getDisplayChar() override;
};

class Orc : public Enemy {
public:
    Orc();
    std::string getDisplayChar() override;
    void specialAbility(Character& player); // 50% more damage under half health
};

class Slime : public Enemy {
private:
    bool hasSplit = false; // Tracks whether the Slime has already split
public:
    Slime();
    std::string getDisplayChar() override;
    bool specialAbility(GameMap& map); // Returns true if it splits
};

class Knight : public Enemy {
public:
    Knight();
    std::string getDisplayChar() override;
}

#endif
