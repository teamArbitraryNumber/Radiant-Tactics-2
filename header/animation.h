#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>

const int MUSHROOM_WIDTH = 8;
const int MUSHROOM_HEIGHT = 6;
const int MUSHROOM_FRAMES = 3;

// Animation array for Mushroom
extern std::vector<std::vector<std::vector<int> > > MushroomAnimation = { 
    { // Frame 1
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 255, 255, 255, 255, 255, 0},
        {0, 255, 255, 255, 255, 255, 255, 0},
        {0, 0, 255, 255, 255, 255, 255, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    },
    { // Frame 2
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 255, 255, 255, 0, 0},
        {0, 0, 255, 255, 255, 255, 255, 0},
        {0, 255, 255, 255, 255, 255, 0, 0},
        {0, 255, 255, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    },
    { // Frame 3
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 255, 0, 0, 0, 255, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    }
};

#endif // MUSHROOMANIMATIONARRAY_H

