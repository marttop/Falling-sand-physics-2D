/*
** EPITECH PROJECT, 2022
** Jam1
** File description:
** Window
*/

#include "Window.hpp"

Window::Window(const int screenWidth, const int screenHeight)
  : _screenWidth(screenWidth)
  , _screenHeight(screenHeight)
{
    InitWindow(screenWidth, screenHeight, "Sand Simulator 2D");
    SetTargetFPS(60);
}

Window::~Window()
{
}

std::pair<int, int>
Window::getDimensions() const
{
    return (std::make_pair(_screenWidth, _screenHeight));
}
