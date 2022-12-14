/*
** EPITECH PROJECT, 2022
** Jam1
** File description:
** Element
*/

#ifndef SAND_HPP_
#define SAND_HPP_

#include <memory>

#include "raylib.h"

enum ElementType {
    EMPTY = 0,
    SAND,
    WATER,
    WALL
};

class Element
{
   public:
    Element(Vector2 pos, Color color, int screenWidth, int screenHeight, int size = 5, ElementType type = EMPTY);
    ~Element();

    void draw();
    void setType(ElementType type);
    bool isMouseOn(Vector2 pos) const;
    bool isCollidingWithRectangle(std::shared_ptr<Element> element) const;
    bool isCollidingWithCircle(int radius, Vector2 pos) const;
    Vector2 getPos() const;
    ElementType getType() const;
    int getVelocity() const;

   protected:
   private:
    Vector2 _pos;
    Color _color;
    int _size;
    ElementType _type;
    int _screenWidth;
    int _screenHeight;
    int _velocity;
};

#endif /* !SAND_HPP_ */
