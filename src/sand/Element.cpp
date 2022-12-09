/*
** EPITECH PROJECT, 2022
** Jam1
** File description:
** Element
*/

#include "Element.hpp"

Element::Element(Vector2 pos, Color color, int screenWidth, int screenHeight, int size, ElementType type)
  : _pos(pos)
  , _color(color)
  , _screenWidth(screenWidth)
  , _screenHeight(screenHeight)
  , _size(size)
  , _type(type)
{
}

Element::~Element()
{
}

void
Element::draw()
{
    DrawRectangle(_pos.x, _pos.y, _size, _size, _color);
}

void
Element::setType(ElementType type)
{
    _type = type;
    if (type == SAND) _color = (Color){ 255, 255, 255, 255 };
    if (type == EMPTY) _color = (Color){ 0, 0, 0, 0 };
}

bool
Element::isMouseOn(Vector2 pos) const
{
    return CheckCollisionPointRec(pos, (Rectangle){(float)_pos.x, (float)_pos.y, (float)_size, (float)_size});
}

bool
Element::isColliding(std::shared_ptr<Element> element) const
{
    return CheckCollisionRecs((Rectangle){(float)_pos.x, (float)_pos.y, (float)_size, (float)_size},
    (Rectangle){(float)_pos.x, (float)_pos.y, (float)_size, (float)_size});
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
