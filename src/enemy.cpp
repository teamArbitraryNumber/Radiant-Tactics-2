#include "../header/enemy.h"
#include "../header/player.h"
#include "../header/game_map.h"
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <limits>
#include <cstdlib> // For rand()
#include <ctime>  // For time()

Enemy::Enemy(CharacterType char_type, string type, int value, int h, int d, int row, int col)
    : Character(char_type, type, value, h, d, row, col), enemyType(type) {}

int Enemy::mod(int value, int limit){
    return (value % limit + limit ) % limit;
}
// Movement logic: Move towards the player
void Enemy::move(shared_ptr<Enemy>& enemy, GameMap& map) {

    int width = map.getWidth();
    int height = map.getHeight();

    // Get player position
    shared_ptr<Object> playerObj;
    int playerX = -1, playerY = -1;

    // Find the player's position
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            shared_ptr<Object> obj = map.getObjectAt(x, y);
            if (obj && obj->getType() == "Player") {
                playerX = x;
                playerY = y;
                break;
            }
        }
    }

    if (playerX == -1 || playerY == -1) {
        return; // Player not found, do nothing
    }

    // Check if the enemy is already adjacent to the player
    int enemyX = getColPosition();
    int enemyY = getRowPosition();

    // Directions: Up, Down, Left, Right
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool isAdjacent = false;
    for (auto [dx, dy] : directions) {
        int adjacentX = (enemyX + dx + width) % width; // Wrap around horizontally
        int adjacentY = (enemyY + dy + height) % height; // Wrap around vertically

        if (adjacentX == playerX && adjacentY == playerY) {
            isAdjacent = true;
            break;
        }
    }

    // If the enemy is already adjacent to the player, do not move
    if (isAdjacent) {
        return;
    }

    // BFS setup
    queue<pair<int, int>> q;
    unordered_map<int, pair<int, int>> parent; // Tracks movement path
    unordered_map<int, bool> visited;

    // Lambda to convert (x, y) to a unique key
    auto toKey = [&](int x, int y) { return y * width + x; };

    // Start BFS from the enemy's current position
    int startX = getColPosition();
    int startY = getRowPosition();
    q.push({startX, startY});
    visited[toKey(startX, startY)] = true;

    bool found = false;

    // Perform BFS to find the shortest path to the player
    while (!q.empty() && !found) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int newX = (x + dx + width) % width; // Wrap around horizontally
            int newY = (y + dy + height) % height; // Wrap around vertically

            // Check if already visited
            if (visited[toKey(newX, newY)]) continue;

            // Check if the space is walkable (empty or player)
            shared_ptr<Object> obj = map.getObjectAt(newX, newY);
            if (obj) {
                // Avoid barriers and other enemies
                if (obj->isBarrier() || (obj->getType() != "Player" && obj->getType() != "Null")) {
                    continue;
                }
            }

            // Mark as visited and store parent for pathfinding
            visited[toKey(newX, newY)] = true;
            parent[toKey(newX, newY)] = {x, y};

            // If we reach the player, stop BFS
            if (newX == playerX && newY == playerY) {
                found = true;
                break;
            }

            q.push({newX, newY});
        }
    }

    if (!found) return; // No valid path to player

    // Backtrack to find the first move
    pair<int, int> current = {playerX, playerY};
    pair<int, int> previous = {startX, startY};

    while (parent.count(toKey(current.first, current.second))) {
        previous = current;
        current = parent[toKey(current.first, current.second)];

        if (current == make_pair(startX, startY)) break; // Stop at the first move
    }

    // Move the enemy to the first step in the path
    int newX = previous.first;
    int newY = previous.second;

    // Update the enemy's position
    setColPosition(newX);
    setRowPosition(newY);

    // Update the game map
    map.removeObjectAt(startX, startY);
    map.setObjectAt(newX, newY, enemy);
}


// Attack logic
void Enemy::attack(Character &player) {
    /*int damage = getDamage(); // Assuming getDamage() returns the enemy's damage
    player.setHealth(player.getHealth() - damage);
    cout << enemyType << " attacks for " << damage << " damage!" << endl;*/
    if (getHealth() <= 0) {
        cout << enemyType << " is dead and cannot attack." << endl;
        return;
    }

    if (player.getHealth() <= 0) {
        cout << "Player is already dead." << endl;
        return;
    }

    int damage = getDamage(); // Assuming getDamage() returns the enemy's damage
    int newHealth = player.getHealth() - damage;
    player.setHealth(newHealth < 0 ? 0 : newHealth); // Ensure health doesn't go below 0

    cout << enemyType << " attacks for " << damage << " damage!" << endl;
}

// Skeleton enemy implementation
Skeleton::Skeleton() : Enemy(CharacterType::SKELETON, "Skeleton",  5    ,  70,   10  ,  0   ,  0  ) {}
//                                  CharacterType      type      value     h     d     row   col
Skeleton::Skeleton(CharacterType charType, string type,  int value,  int h,   int d  ,  int row, int col ) : Enemy(charType, type, value, h, d, row, col) {}

string Skeleton::getDisplayChar(){
    return "💀";
}

// Goblin enemy implementation
Goblin::Goblin() : Enemy(CharacterType::GOBLIN,   "Goblin",    2     ,  80   , 5  ,   0   ,   0) {}
//                              CharacterType       type      value     h      d     row     col
Goblin::Goblin(CharacterType charType, string type,  int value,  int h,   int d  ,  int row, int col ) : Enemy(charType, type, value, h, d, row, col){}

string Goblin::getDisplayChar(){
    return "👺";
}


// ORC: Deals 50% more damage when under half health
Orc::Orc() : Enemy(CharacterType::ORC, "Orc", 3, 120, 15, 0, 0) {}
Orc::Orc(CharacterType charType, string type,  int value,  int h,   int d  ,  int row, int col ) : Enemy(charType, type, value, h, d, row, col){}
std::string Orc::getDisplayChar() { return "🏹"; }

void Orc::specialAbility(Character& player) {
    if (getHealth() < 60) {  // If Orc is below 50% HP
        int boostedDamage = getDamage() * 1.5;
        player.setHealth(player.getHealth() - boostedDamage);
        std::cout << "Orc is enraged! It deals " << boostedDamage << " damage!" << std::endl;
    } else {
        player.setHealth(player.getHealth() - getDamage());
    }
}

// SLIME: Splits into two and changes color to purple
Slime::Slime() : Enemy(CharacterType::SLIME, "Slime", 1, 60, 5, 0, 0) {}
Slime::Slime(CharacterType charType, string type,  int value,  int h,   int d  ,  int row, int col ) : Enemy(charType, type, value, h, d, row, col){}
std::string Slime::getDisplayChar() {
    return hasSplit ? "🟣" : "🟢";  // Green before split, Purple after split
}

bool Slime::specialAbility(GameMap& map) {
    if (getHealth() <= 0 && !hasSplit) {
        hasSplit = true;
        std::cout << "Slime splits into two smaller slimes!" << std::endl;

        // Find two open spaces near the Slime
        std::vector<std::pair<int, int>> possibleSpots = {
            {getRowPosition() + 1, getColPosition()},
            {getRowPosition() - 1, getColPosition()},
            {getRowPosition(), getColPosition() + 1},
            {getRowPosition(), getColPosition() - 1}
        };

        std::vector<std::pair<int, int>> validSpots;
        for (auto& spot : possibleSpots) {
            if (map.isPositionEmpty(spot.first, spot.second)) {
                validSpots.push_back(spot);
            }
        }

        // Spawn slimes only in available spaces
        int spawnCount = 0;
        for (auto& spot : validSpots) {
            if (spawnCount >= 2) break; // Ensure only two Slimes spawn
            std::shared_ptr<Slime> newSlime = std::make_shared<Slime>();
            newSlime->setRowPosition(spot.first);
            newSlime->setColPosition(spot.second);
            newSlime->hasSplit = true;
            map.addEnemy(newSlime);
            spawnCount++;
        }
    
        return spawnCount > 0;  // True if at least one new slime was placed
    }
    return false;
}

// KNIGHT: Tanky enemy with high health
Knight::Knight() : Enemy(CharacterType::KNIGHT, "Knight", 5, 150, 20, 0, 0) {}
Knight::Knight(CharacterType charType, string type,  int value,  int h,   int d  ,  int row, int col ) : Enemy(charType, type, value, h, d, row, col){}
std::string Knight::getDisplayChar() { return "⚔️"; }

int Enemy::dropCurrency() {
    srand(time(0)); // Seed the random number generator
    int minCurrency = 5;  // Minimum currency dropped
    int maxCurrency = 20; // Maximum currency dropped
    return minCurrency + (rand() % (maxCurrency - minCurrency + 1));
}

