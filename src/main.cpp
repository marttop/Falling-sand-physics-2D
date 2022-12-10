#include "raylib.h"
#include <iostream>
#include "Core.hpp"

int main(void)
{
    // Initialization
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1720;
    const int screenHeight = 900;
    Core core(screenWidth, screenHeight);

    // Game
    core.gameLoop();

    return 0;
}