/*
** EPITECH PROJECT, 2022
** Jam1
** File description:
** Element
*/

#ifndef SAND_HPP_
#define SAND_HPP_

#include "raylib.h"

#include <memory>

enum ElementType {
    EMPTY = 0,
    SAND,
    WALL
};

class Element {
    public:
        Element(Vector2 pos, Color color, int screenWidth, int screenHeight, int size = 5, ElementType type = EMPTY);
        ~Element();

        void draw();
        void fall();
        void fallLeft();
        void fallRight();

        void setType(ElementType type);

        bool isMouseOn(Vector2 pos) const;
        bool isColliding(std::shared_ptr<Element> element) const;

        Vector2 getPos() const;
        ElementType getType() const;

    protected:
    private:
        Vector2 _pos;
        Color _color;
        int _size;
        ElementType _type;
        int _screenWidth;
        int _screenHeight;
};

#endif /* !SAND_HPP_ */
