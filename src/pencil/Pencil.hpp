/*
** EPITECH PROJECT, 2022
** Falling-sand-physics-2D
** File description:
** Pencil
*/

#ifndef PENCIL_HPP_
#define PENCIL_HPP_

#include "raylib.h"

class Pencil {
    public:
        Pencil(int radius, Color color);
        ~Pencil();

        void setRadius(int radius);
        int getRadius() const;
        Vector2 getPos() const;

        void draw();
        void update();

    protected:
    private:
        int _radius;
        Color _color;
        Vector2 _pos;
};

#endif /* !PENCIL_HPP_ */
