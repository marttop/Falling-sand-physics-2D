/*
** EPITECH PROJECT, 2022
** Falling-sand-physics-2D
** File description:
** Pencil
*/

#include "Pencil.hpp"

Pencil::Pencil(int radius, Color color) : _radius(radius), _color(color), _mode(SAND_MODE)
{
}

Pencil::~Pencil()
{
}

void Pencil::setRadius(int radius)
{
    _radius = radius;
}

void Pencil::setMode(Mode mode)
{
    _mode = mode;
}

void Pencil::setColor(Color color)
{
    _color = color;
}

int Pencil::getRadius() const
{
    return _radius;
}

Mode Pencil::getMode() const
{
    return _mode;
}

Vector2 Pencil::getPos() const
{
    return _pos;
}

void Pencil::draw()
{
    DrawCircle(_pos.x, _pos.y, _radius, _color);
}

void Pencil::update()
{
    _pos = GetMousePosition();
}
