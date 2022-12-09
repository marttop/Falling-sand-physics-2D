/*
** EPITECH PROJECT, 2022
** Jam1
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "Window.hpp"
#include <vector>
#include <unordered_map>
#include "Element.hpp"
#include <iostream>
#include <random>

enum Scene {
    GAME,
};

class Core {
    public:
        Core(const int screenWidth = 800, const int screenHeight = 450, const int fps = 60);
        ~Core();

        void gameLoop();

    protected:
    private:
        void gameUpdate();
        void gameDraw();
        void keyEvents();

        Color _backgroundColor;

        std::shared_ptr<Window> _w;
        std::vector<std::vector<std::shared_ptr<Element>>> _2DArray;
        int _screenWidth;
        int _screenHeight;
        bool _isSPacePressed;
};

#endif /* !CORE_HPP_ */
