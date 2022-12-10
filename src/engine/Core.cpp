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
    _backgroundColor = (Color){25, 25, 25, 255};
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;
    _isSPacePressed = false;
    DisableCursor();
    _counter = 0;

    int particleSize = 8;
    int pencilSize = 40;

    _controlPanel = std::make_shared<Panel>(_screenWidth, _screenHeight, 400, 230, TOP_LEFT, SKYBLUE, 10);
    _infoPanel = std::make_shared<Panel>(_screenWidth, _screenHeight, 400, 230, TOP_RIGHT, SKYBLUE, 10);

    _controlPanel->addText("Sand Simulator 2D commands :", "title", BLACK, 20);
    _controlPanel->addText("- O/P to change size of the pencil", "subtitle1", BLACK, 15);
    _controlPanel->addText("- SPACE to add use the pencil", "subtitle2", BLACK, 15);
    _controlPanel->addText("- L_SHIFT to toggle pencil functions", "subtitle3", BLACK, 15);

    _infoPanel->addText("Game informations", "title", BLACK, 20);
    _infoPanel->addText("Total grains of sand : 0", "subtitle1", BLACK, 15);

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

    for (int y = _2DArray.size() - 2; y > 0; y--) {
        for (int x = _2DArray[y].size() - 2; x > 0; x--) {
            auto particle = _2DArray[y][x];
            if (particle->getType() == SAND) {
                int direction = std::rand() % 2 == 0 ? 1 : -1;
                if (_2DArray[y + 1][x]->getType() == EMPTY) {
                    _2DArray[y + 1][x]->setType(SAND);
                    particle->setType(EMPTY);
                } else if (_2DArray[y + 1][x + direction]->getType() == EMPTY) {
                    _2DArray[y + 1][x + direction]->setType(SAND);
                    particle->setType(EMPTY);
                }
            }
            else if (particle->getType() == WATER) {
                if (_2DArray[y + 1][x]->getType() == EMPTY) {
                    _2DArray[y + 1][x]->setType(WATER);
                    particle->setType(EMPTY);
                } else if (_2DArray[y + 1][x - 1]->getType() == EMPTY) {
                    _2DArray[y + 1][x - 1]->setType(WATER);
                    particle->setType(EMPTY);
                }  else if (_2DArray[y + 1][x + 1]->getType() == EMPTY) {
                    _2DArray[y + 1][x + 1]->setType(WATER);
                    particle->setType(EMPTY);
                }  else if (_2DArray[y][x - 1]->getType() == EMPTY) {
                    _2DArray[y][x - 1]->setType(WATER);
                    particle->setType(EMPTY);
                }  else if (_2DArray[y][x + 1]->getType() == EMPTY) {
                    _2DArray[y][x + 1]->setType(WATER);
                    particle->setType(EMPTY);
                }
            }
        }
    }
    _counter = 0;
    for (auto i : _2DArray) {
        for (auto j : i) {
            if (j->getType() == SAND) _counter++;
        }
    }
    _infoPanel->updateText(1, "Total grains of sand : " + std::to_string(_counter));
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
    _controlPanel->draw();
    _infoPanel->draw();

    //----------------------------------------------------------------------------------
    EndDrawing();
}

void Core::keyEvents()
{
    if (IsKeyDown(KEY_SPACE)) {
        usePencil();
    }
    if (IsKeyDown(KEY_O)) {
        _pencil->setRadius(_pencil->getRadius() - 1);
    } else if (IsKeyDown(KEY_P)) {
        _pencil->setRadius(_pencil->getRadius() + 1);
    }

    if (IsKeyPressed(KEY_RIGHT_SHIFT) && _pencil->getMode() == ERASE_MODE) {
        _pencil->setMode(SAND_MODE);
        _pencil->setColor((Color){166, 145, 80, 255});
    } else if (IsKeyPressed(KEY_RIGHT_SHIFT) && _pencil->getMode() == SAND_MODE) {
        _pencil->setMode(WATER_MODE);
        _pencil->setColor(BLUE);
    } else if (IsKeyPressed(KEY_RIGHT_SHIFT) && _pencil->getMode() == WATER_MODE) {
        _pencil->setMode(ERASE_MODE);
        _pencil->setColor(RED);
    }
}

void Core::usePencil()
{
    for (auto rows : _2DArray) {
        for (auto e : rows) {
            if (e->isCollidingWithCircle(_pencil->getRadius(), _pencil->getPos())) {
                if (_pencil->getMode() == SAND_MODE)
                    e->setType(SAND);
                else if (_pencil->getMode() == WATER_MODE)
                    e->setType(WATER);
                else if (_pencil->getMode() == ERASE_MODE)
                    e->setType(EMPTY);
            }
        }
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
