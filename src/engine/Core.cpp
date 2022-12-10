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
    _backgroundColor = (Color){56, 43, 27, 255};
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;
    _isSPacePressed = false;
    DisableCursor();

    int particleSize = 8;
    int pencilSize = 40;

    _panel = std::make_shared<Panel>(_screenWidth, _screenHeight, 300, 190, BOTTOM_RIGHT, SKYBLUE, 10);
    _panel->addText("Hello I'm gay", "gay", BLACK, 20);
    _panel->addText("Hello I'm gay", "gay2", BLACK, 20);
    _pencil = std::make_shared<Pencil>(pencilSize, (Color){166, 145, 80, 255});
    for (int i = 0, index = 0; i < screenHeight; i += particleSize, index++) {
        std::vector<std::shared_ptr<Element>> e;
        _2DArray.push_back(e);
        for (int j = 0; j < screenWidth; j += particleSize) {
            _2DArray[index].push_back(std::make_shared<Element>((Vector2){(float)j, (float)i}, (Color){0, 0, 0, 0}, _screenWidth, _screenHeight, particleSize));
        }
    }
}

Core::~Core()
{
}

void Core::gameUpdate()
{
    _pencil->update();

    if (_isSPacePressed) {
        for (auto rows : _2DArray) {
            for (auto e : rows) {

                if (e->isCollidingWithCircle(_pencil->getRadius(), _pencil->getPos()) && e->getType() == EMPTY) {
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
                } else if (_2DArray[y + 1][x + direction]->getType() == EMPTY) {
                    _2DArray[y + 1][x + direction]->setType(SAND);
                    _2DArray[y][x]->setType(EMPTY);
                }
            }
        }
    }
}

void Core::gameDraw()
{
    BeginDrawing();
    ClearBackground(_backgroundColor);

    // Draw here
    //----------------------------------------------------------------------------------
    for (auto rows : _2DArray) {
        for (auto elem : rows) {
            if (elem->getType() != EMPTY)
                elem->draw();
        }
    }

    _pencil->draw();
    _panel->draw();

    //----------------------------------------------------------------------------------
    EndDrawing();
}

void Core::keyEvents()
{
    if (IsKeyPressed(KEY_SPACE) && !_isSPacePressed) {
        _isSPacePressed = true;
    } else if (IsKeyPressed(KEY_SPACE) && _isSPacePressed) {
        _isSPacePressed = false;
    }
    if (IsKeyDown(KEY_O)) {
        _pencil->setRadius(_pencil->getRadius() - 1);
    } else if (IsKeyDown(KEY_P)) {
        _pencil->setRadius(_pencil->getRadius() + 1);
    }
}

void Core::gameLoop()
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
