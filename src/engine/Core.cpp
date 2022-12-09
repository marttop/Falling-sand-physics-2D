/*
** EPITECH PROJECT, 2022
** Jam1
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(const int screenWidth, const int screenHeight, const int fps)
{
    std::srand(time(0));
    _w = std::make_shared<Window>(screenWidth, screenHeight);
    SetTargetFPS(fps);
    _backgroundColor = (Color){ 76, 63, 47, 255 };
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;
    _isSPacePressed = false;

    for (int i = 0, index = 0; i < screenHeight; i += 5, index++) {
        std::vector<std::shared_ptr<Element>> e;
        _2DArray.push_back(e);
        for (int j = 0; j < screenWidth; j += 5) {
            _2DArray[index].push_back(std::make_shared<Element>((Vector2){(float)j, (float)i}, (Color){ 0, 0, 0, 0 }, _screenWidth, _screenHeight));
        }
    }
}

Core::~Core()
{
}

void
Core::gameUpdate()
{
    Vector2 mousePos = GetMousePosition();

    if (_isSPacePressed) {

        for (auto rows : _2DArray) {
            for (auto e : rows) {
                if (e->isMouseOn(mousePos) && e->getType() == EMPTY) {
                    e->setType(SAND);
                }
            }
        }

    }

    for (int y = _2DArray.size() - 2; y > 0; y--) {
        for (int x = _2DArray[y].size() - 2; x > 0; x--) {
            if (_2DArray[y][x]->getType() == SAND) {
                int direction = std::rand() % 2 == 0 ? 1 : -1;
                if (_2DArray[y + 1][x]->getType() == EMPTY) {
                    _2DArray[y + 1][x]->setType(SAND);
                    _2DArray[y][x]->setType(EMPTY);
                }
                else if (_2DArray[y + 1][x + direction]->getType() == EMPTY) {
                    _2DArray[y + 1][x + direction]->setType(SAND);
                    _2DArray[y][x]->setType(EMPTY);
                }
            }
        }
    }
}

void
Core::gameDraw()
{
    BeginDrawing();
    ClearBackground(_backgroundColor);

    // Draw here
    //----------------------------------------------------------------------------------
    for (auto rows : _2DArray) {
        for (auto elem : rows) {
            elem->draw();
        }
    }
    //----------------------------------------------------------------------------------
    EndDrawing();
}

void
Core::keyEvents()
{
    if (IsKeyPressed(KEY_SPACE) && !_isSPacePressed) {
        _isSPacePressed = true;
    } else if (IsKeyPressed(KEY_SPACE) && _isSPacePressed) {
        _isSPacePressed = false;
    }
}

void
Core::gameLoop()
{
    while (!WindowShouldClose()) {
        // Update
        //----------------------------------------------------------------------------------
        keyEvents();
        gameUpdate();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        gameDraw();
        //----------------------------------------------------------------------------------
    }
}
