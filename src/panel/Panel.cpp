#include "Panel.hpp"

Panel::Panel(int screenWidth, int screenHeight, int width, int height, Position position, Color color, int padding)
    : _screenWidth(screenWidth), _screenHeight(screenHeight), _width(width), _height(height), _position(position), _color(color), _padding(padding)
{
}

Panel::~Panel()
{
}

void Panel::draw()
{
    int textX = 0;
    int textY = 0;
    if (_position == TOP_LEFT) {
        DrawRectangle(_padding, _padding, _width, _height, Fade(_color, 0.5f));
        textX = _padding + 10;
        textY = _padding + 10;
    }
    else if (_position == TOP_RIGHT) {
        DrawRectangle(_screenWidth - _width - _padding, _padding, _width, _height, Fade(_color, 0.5f));
        textX = _screenWidth - _width - _padding + 10;
        textY = _padding + 10;
    }
    else if (_position == BOTTOM_LEFT) {
        DrawRectangle(_padding, _screenHeight - _height - _padding, _width, _height, Fade(_color, 0.5f));
        textX = _padding + 10;
        textY = _screenHeight - _height - _padding + 10;
    }
    else if (_position == BOTTOM_RIGHT) {
        DrawRectangle(_screenWidth - _width - _padding, _screenHeight - _height - _padding, _width, _height, Fade(_color, 0.5f));
        textX = _screenWidth - _width - _padding + 10;
        textY = _screenHeight - _height - _padding + 10;
    }

    for (auto text : _texts) {
        DrawText(std::get<0>(text.second).c_str(), textX, textY, std::get<2>(text.second), std::get<1>(text.second));
        textY += 10 + std::get<2>(text.second);
    }
}

void Panel::addText(const std::string &text, const std::string &textID, Color color, int fontSize)
{
    _texts.insert({textID, std::make_tuple(text, color, fontSize)});
}
