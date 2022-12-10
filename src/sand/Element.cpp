/*
** EPITECH PROJECT, 2022
** Jam1
** File description:
** Element
*/

#include "Element.hpp"

Element::Element(Vector2 pos, Color color, int screenWidth, int screenHeight, int size, ElementType type)
    : _pos(pos), _color(color), _screenWidth(screenWidth), _screenHeight(screenHeight), _size(size), _type(type)
{
}

Element::~Element()
{
}

void Element::draw()
{
    if (_type != EMPTY)
        DrawRectangle(_pos.x, _pos.y, _size, _size, _color);
}

void Element::setType(ElementType type)
{
    _type = type;
    if (type == SAND) {
        int sandType = std::rand() % 3;
        if (sandType == 0)
            _color = (Color){182, 162, 99, 255};
        else if (sandType == 1)
            _color = (Color){194, 178, 128, 255};
        else
            _color = (Color){166, 145, 80, 255};
    }
    if (type == EMPTY) _color = (Color){0, 0, 0, 0};
}

bool Element::isMouseOn(Vector2 pos) const
{
    return CheckCollisionPointRec(pos, (Rectangle){(float)_pos.x, (float)_pos.y, (float)_size, (float)_size});
}

bool Element::isCollidingWithRectangle(std::shared_ptr<Element> element) const
{
    return CheckCollisionRecs((Rectangle){(float)_pos.x, (float)_pos.y, (float)_size, (float)_size},
                              (Rectangle){(float)element->getPos().x, (float)element->getPos().y, (float)_size, (float)_size});
}

bool Element::isCollidingWithCircle(int radius, Vector2 pos) const
{
    return CheckCollisionCircleRec(pos, radius, (Rectangle){(float)_pos.x, (float)_pos.y, (float)_size, (float)_size});
}

Vector2
Element::getPos() const
{
    return _pos;
}

ElementType
Element::getType() const
{
    return _type;
}
