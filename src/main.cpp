#include "raylib.h"
#include <iostream>
#include "Core.hpp"

int main(void)
{
    // Initialization
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    Core core(screenWidth, screenHeight);

    // Game
    core.gameLoop();

    return 0;
}