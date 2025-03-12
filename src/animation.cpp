// #include <iostream>
// #include <vector>
// #include <thread>
// #include <chrono>
// #include "SlimeanimationArray.h"
// #include "MushroomanimationArray.h"

// using namespace std;

// enum Code
// {
//     RED = 31,
//     GREEN = 32,
//     BLUE = 34,
//     DEFAULT = 39,
//     RED_BG = 41,
//     GREEN_BG = 42,
//     BLUE_BG = 44,
//     DEFAULT_BG = 49
// };

// char SPACE = 32;

// struct animation
// {
//     int width;
//     int height;
//     int frameNum;
//     vector<vector<vector<int> > > animationArray; // Use a 3D vector for animation frames
// };

// animation Slime()
// {
//     animation ani;
//     ani.width = SLIME_WIDTH;
//     ani.height = SLIME_HEIGHT;
//     ani.frameNum = SLIME_FRAMES;
//     ani.animationArray = SlimeAnimation; // Assuming this is defined in the included header
//     return ani;
// }

// animation Mushroom()
// {
//     animation ani;
//     ani.width = MUSHROOM_WIDTH;
//     ani.height = MUSHROOM_HEIGHT;
//     ani.frameNum = MUSHROOM_FRAMES;
//     ani.animationArray = MushroomAnimation; // Assuming this is defined in the included header
//     return ani;
// }

// void playAnimation(animation ani)
// {
//     std::ios_base::sync_with_stdio(false);
//     int frame = 0;

//     while (true)
//     {
//         // Clear screen (optional)
//         cout << "\e[2J"; // Clear screen
//         cout << "\e[H";  // Move cursor to home (top-left corner)

//         // Print each frame of the animation
//         for (int y = 0; y < ani.height; y++)
//         {
//             for (int x = 0; x < ani.width; x++)
//             {
//                 if (ani.animationArray[frame][y][x] == 0)
//                 {
//                     cout << "\e[" << DEFAULT_BG << "m" << SPACE;
//                 }
//                 else
//                 {
//                     cout << "\e[48;5;" << ani.animationArray[frame][y][x] << "m" << SPACE;
//                 }
//             }
//             cout << "\e[" << DEFAULT_BG << "m"
//                  << "\n";
//         }

//         frame = (frame + 1) % ani.frameNum;
//         cout << "\e[" << ani.width << "D";  // Move cursor back to the start of the line
//         cout << "\e[" << ani.height << "A"; // Move cursor up by the height of the animation

//         // Wait for 100 milliseconds before displaying the next frame
//         this_thread::sleep_for(chrono::milliseconds(100));
//         cout << flush;
//     }
// }

// int main()
// {
//     int select;
//     cout << "Which animation you want to play: 1. Slime, 2. Mushroom" << endl;
//     cin >> select;

//     animation ani;
//     switch (select)
//     {
//     case 1:
//         ani = Slime();
//         break;
//     case 2:
//         ani = Mushroom();
//         break;
//     default:
//         cout << "Invalid selection." << endl;
//         return 1;
//     }

//     playAnimation(ani);
//     return 0;
// }


#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "../header/animation.h"

using namespace std;

enum Code
{
    RED = 31,
    GREEN = 32,
    BLUE = 34,
    DEFAULT = 39,
    RED_BG = 41,
    GREEN_BG = 42,
    BLUE_BG = 44,
    DEFAULT_BG = 49
};

char SPACE = 32;

struct animation
{
    int width;
    int height;
    int frameNum;
    vector<vector<vector<int>>> animationArray; // 3D vector for animation frames
};


// Mushroom Animation Setup
animation Mushroom()
{
    animation ani;
    ani.width = MUSHROOM_WIDTH;
    ani.height = MUSHROOM_HEIGHT;
    ani.frameNum = MUSHROOM_FRAMES;
    ani.animationArray = MushroomAnimation;
    return ani;
}

// Function to display the animation
void playAnimation(animation ani)
{
    std::ios_base::sync_with_stdio(false);
    int frame = 0;

    while (true)
    {
        // Clear screen (optional)
        cout << "\e[2J"; // Clear screen
        cout << "\e[H";  // Move cursor to home (top-left corner)

        // Loop through each frame of the animation
        for (int y = 0; y < ani.height; y++)
        {
            for (int x = 0; x < ani.width; x++)
            {
                int colorCode = ani.animationArray[frame][y][x];
                if (colorCode == 0)
                {
                    // Background color (default)
                    cout << "\e[" << DEFAULT_BG << "m" << SPACE;
                }
                else
                {
                    // Set the background color to the appropriate color code
                    cout << "\e[48;5;" << colorCode << "m" << SPACE;
                }
            }
            // Reset the background color to default after printing each row
            cout << "\e[" << DEFAULT_BG << "m" << endl;
        }

        // Move the cursor to the top-left corner for next frame
        frame = (frame + 1) % ani.frameNum;
        cout << "\e[" << ani.height << "A"; // Move cursor up by the height of the animation

        // Delay to make the animation visible (adjust for speed)
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << flush;
    }
}

// Main function to select the animation
int main()
{
    int select;
    cout << "Which animation you want to play: 1. Slime, 2. Mushroom" << endl;
    cin >> select;

    animation ani;
    switch (select)
    {
    case 1:
        ani = Mushroom();
        break;
    default:
        cout << "Invalid selection." << endl;
        return 1;
    }

    // Play the selected animation
    playAnimation(ani);
    return 0;
}
