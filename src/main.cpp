#include "../header/game_manager.h"
#include "../header/enemy.h"
#include "../header/animation.h"
#include <iostream>

using namespace std;

GameMap initMap1();
GameMap initMap2(shared_ptr<Player> p);
GameMap initMap3(shared_ptr<Player> p);

int main() {
    // Initialize the game map with a simple layout
    //                                            All maps will be 11 x 11
    animateWelcomeMessage(3);
    animateTorch(3);


    displayInstructions();
    cout << endl;

    GameMap gameMap1 = initMap1();//initialize gameMap1
    
    // Initialize the game manager
    bool isOver = false;
    Game_Manager gameManager(gameMap1, gameMap1.getPlayer(), &isOver);

    // Start the game

    gameManager.start();//begin map 1
    
    gameMap1 = initMap2(gameMap1.getPlayer());//update game map
    gameManager.end = false;
    gameManager.enemyGoal = 3;//update game manager
    gameManager.start();//begin map 2

    gameMap1 = initMap3(gameMap1.getPlayer());//update game map
    gameManager.end = false;
    gameManager.enemyGoal = 4;//update game manager
    gameManager.start();//begin map 3

    return 0;
}






GameMap initMap1(){
    vector<vector<int>> mapLayout1 = {//0 = empty, 1 = barrier, 2 = door
    {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1}
}; 
    GameMap gameMap1(mapLayout1, 11, 11);
    // Initialize the player
    cout << "\nChoose character type (Enter a number):" << endl;
    cout << "1. Warrior 🛡️ (High health, Medium damage)" << endl;
    cout << "2. Mage    🧙 (Low health, High damage)" << endl;
    cout << "3. Rogue   🥷 (Medium health, Medium damage)" << endl;
    cout << "4. God     👑 (Ridiculous health, Ridiculous damage)" << endl;
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    shared_ptr<Player> player;
    switch (choice) {
        case 1:
            player = make_shared<Player>(PlayerType::WARRIOR, CharacterType::PLAYER, "Warrior", 0, 120, 15, 1, 0, 50);
            break;
        case 2:
            player = make_shared<Player>(PlayerType::MAGE, CharacterType::PLAYER, "Mage", 0, 80, 25, 1, 0, 50);
            break;
        case 3:
            player = make_shared<Player>(PlayerType::ROGUE, CharacterType::PLAYER, "Rogue", 0, 100, 20, 1, 0, 50);
            break;
        case 4:
            player = make_shared<Player>(PlayerType::GOD, CharacterType::PLAYER, "God", 0, 1000000, 100, 1, 0, 50);
            break;
        default:
            cout << "Invalid choice. Defaulting to Warrior." << endl;
            player = make_shared<Player>(PlayerType::WARRIOR, CharacterType::PLAYER, "Warrior", 0, 120, 15, 1, 0, 50);
            break;
    }
    //auto player = make_shared<Player>(CharacterType::PLAYER, "Player", 0, 100, 10, 1, 0, 50);
    gameMap1.setPlayer(player); // Set the player in the map
    player->setType("Player");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    // Add enemies to the map
    auto skeleton = make_shared<Skeleton>(CharacterType::SKELETON, "Skeleton",  5    ,  70,   10  ,  6   ,  4  );
    skeleton->setType("Skeleton");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap1.addEnemy(skeleton);

    auto goblin = make_shared<Goblin>(CharacterType::GOBLIN,   "Goblin",    2     ,  80   , 5  ,   1   ,   4);
    goblin->setType("Goblin");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap1.addEnemy(goblin);
    return gameMap1;
};

GameMap initMap2(shared_ptr<Player> p){
    vector<vector<int>> mapLayout2 = {//0 = empty, 1 = barrier, 2 = door
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 1, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    }; 
    GameMap gameMap2(mapLayout2, 11, 11);
    p->setPosition(2, 2);
    gameMap2.setPlayer(p);

    auto skeleton = make_shared<Skeleton>(CharacterType::SKELETON, "Skeleton",  5    ,  70,   10  ,  9   ,  9  );
    skeleton->setType("Skeleton");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap2.addEnemy(skeleton);

    auto goblin1 = make_shared<Goblin>(CharacterType::GOBLIN,   "Goblin",    2     ,  80   , 5  ,   9   ,   7);
    goblin1->setType("Goblin");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap2.addEnemy(goblin1);

    auto goblin2 = make_shared<Knight>(CharacterType::KNIGHT,   "Knight",    2     ,  80   , 5  ,   2   ,   7);
    goblin2->setType("Knight");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap2.addEnemy(goblin2);
    
    return gameMap2;
}

GameMap initMap3(shared_ptr<Player> p){
    vector<vector<int>> mapLayout3 = {//0 = empty, 1 = barrier, 2 = door
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
        {2, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    }; 
    GameMap gameMap3(mapLayout3, 11, 11);
    p->setPosition(1, 2);
    gameMap3.setPlayer(p);

    auto knight1 = make_shared<Knight>(CharacterType::KNIGHT,   "Knight",    2     ,  80   , 5  ,   2   ,   7);
    knight1->setType("Knight");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap3.addEnemy(knight1);

    auto knight2 = make_shared<Knight>(CharacterType::KNIGHT,   "Knight",    2     ,  80   , 5  ,   9   ,   4);
    knight2->setType("Knight");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap3.addEnemy(knight2);

    auto orc = make_shared<Knight>(CharacterType::ORC, "Orc", 3, 120, 15,   5   ,   2);
    orc->setType("Knight");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap3.addEnemy(orc);

    auto slime = make_shared<Slime>(CharacterType::SLIME, "Slime", 1, 60, 5, 0, 0);
    slime->setType("Slime");
    gameMap3.addEnemy(slime);
    
    
    return gameMap3;
}