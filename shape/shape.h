#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <array>
#include <vector>

const std::array<sf::Color, 5> COLORS =
{
        sf::Color(3, 65, 174),
        sf::Color(114, 203, 59),
        sf::Color(255, 213, 0),
        sf::Color(255, 151, 28),
        sf::Color(255, 50, 19)
};

namespace Shape
{
    struct Coordinate
    {
        int x;
        int y;
    };

    const std::vector<std::vector<Coordinate>> ALL_SHAPES =
            {
                    {{4, 0}, {5, 0}, {5, 1}, {5, 2}},
                    {{4, 0}, {4, 1}, {4, 2}, {4, 3}},
                    {{5, 0}, {5, 1}, {5, 2}, {4, 2}},
                    {{4, 0}, {4, 1}, {5, 0}, {5, 1}},
                    {{5, 0}, {5, 1}, {4, 1}, {4, 2}},
                    {{4, 1}, {5, 0}, {5, 1}, {5, 2}},
                    {{4, 0}, {4, 1}, {5, 1}, {5, 2}}
            };

    struct Shape
    {
        Shape()
        {
            Change();
        }

        void Change()
        {
            static int colorId = 0;
            int shapeId = rand() % 7;

            blocks = ALL_SHAPES[shapeId];
            color = COLORS[colorId];
            colorId = (colorId + 1) % 5;
        }

        std::vector<Coordinate> blocks;
        sf::Color color;
    };
};