/*
** EPITECH PROJECT, 2022
** Falling-sand-physics-2D
** File description:
** Pencil
*/

#ifndef PENCIL_HPP_
#define PENCIL_HPP_

#include "raylib.h"

enum Mode {
    SAND_MODE,
    ERASE_MODE,
    WATER_MODE,
};

class Pencil {
    public:
        Pencil(int radius, Color color);
        ~Pencil();

        void setRadius(int radius);
        void setMode(Mode mode);
        void setColor(Color color);

        int getRadius() const;
        Mode getMode() const;
        Vector2 getPos() const;

        void draw();
        void update();

    protected:
    private:
        int _radius;
        Color _color;
        Vector2 _pos;
        Mode _mode;
};

#endif /* !PENCIL_HPP_ */
