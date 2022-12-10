/*
** EPITECH PROJECT, 2022
** Falling-sand-physics-2D
** File description:
** Panel
*/

#ifndef PANEL_HPP_
#define PANEL_HPP_

#include "raylib.h"
#include <vector>
#include <string>

enum Position {
    TOP_LEFT,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT
};

class Panel {
    public:
        Panel(int screenWidth, int screenHeight, int width, int height, Position position, Color color, int padding = 10);
        ~Panel();

        void draw();
        void addText(const std::string &text, const std::string &textID, Color color, int fontSize);
        void updateText(int index, const std::string &text);

    protected:
    private:
        int _screenWidth;
        int _screenHeight;
        int _width;
        int _height;
        int _padding;
        Position _position;
        Color _color;
        std::vector<std::tuple<std::string, Color, int>> _texts;
};

#endif /* !PANEL_HPP_ */
