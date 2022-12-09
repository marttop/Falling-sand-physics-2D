/*
** EPITECH PROJECT, 2022
** Jam1
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <iostream>
#include <memory>
#include "raylib.h"

class Window {
    public:
        Window(const int screenWidth, const int screenHeight);
        ~Window();

        /**
         * @brief Get the Dimensions object
         *
         * @return ** std::pair<int, int> (first = width ; second = height)
         */
        std::pair<int, int> getDimensions() const;

    protected:
    private:
        int _screenWidth;
        int _screenHeight;

};

#endif /* !WINDOW_HPP_ */
