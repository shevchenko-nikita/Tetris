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

    enum class SHAPE_TYPES
    {
        J_BLOCK,
        L_BLOCK,
        I_BLOCK,
        O_BLOCK,
        E_BLOCK,
        Z_BLOCK,
        S_BLOCK
    };

    class Shape
    {
    public:
        Shape()
        {
            Change();
        }

        Shape(std::initializer_list<Coordinate> positions)
        : blocks(positions)
        {
        }

        std::vector<Coordinate> GetBlocks() const;
        sf::Color GetColor() const;

        void MoveLeft();
        void MoveRight();
        void MoveDown();

        void Change();
        void Rotate();

    private:
        std::vector<Coordinate> blocks;
        SHAPE_TYPES shapeType;
        uint8_t state = 0;
        sf::Color color;

        int shift_x = 0;
        int shift_y = 0;
    };

    const std::vector<Coordinate> J_BLOCK_STATES[4] =
    {
            {{5, 0}, {5, 1}, {5, 2}, {4, 2}},
            {{4, 0}, {4, 1}, {5, 1}, {6, 1}},
            {{5, 0}, {6, 0}, {5, 1}, {5, 2}},
            {{4, 1}, {5, 1}, {6, 1}, {6, 2}}
    };

    const std::vector<Coordinate> L_BLOCK_STATES[4] =
    {
            {{4, 0}, {5, 0}, {5, 1}, {5, 2}},
            {{4, 1}, {5, 1}, {6, 1}, {6, 0}},
            {{5, 0}, {5, 1}, {5, 2}, {6, 2}},
            {{4, 2}, {4, 1}, {5, 1}, {6, 1}}
    };

    const std::vector<Coordinate> I_BLOCK_STATES[2] =
    {
            {{4, 0}, {4, 1}, {4, 2}, {4, 3}},
            {{3, 1}, {4, 1}, {5, 1}, {6, 1}}
    };

    const std::vector<Coordinate> O_BLOCK_STATES[4] =
    {
            {{4, 0}, {4, 1}, {5, 0}, {5, 1}}
    };

    const std::vector<Coordinate> E_BLOCK_STATES[4] =
    {
            {{4, 1}, {5, 0}, {5, 1}, {5, 2}},
            {{5, 0}, {4, 1}, {5, 1}, {6, 1}},
            {{5, 0}, {5, 1}, {5, 2}, {6, 1}},
            {{4, 1}, {5, 1}, {6, 1}, {5, 2}}
    };

    const std::vector<Coordinate> Z_BLOCK_STATES[4] =
    {
            {{5, 0}, {5, 1}, {4, 1}, {4, 2}},
            {{4, 0}, {5, 0}, {5, 1}, {6, 1}}
    };

    const std::vector<Coordinate> S_BLOCK_STATES[4] =
    {
            {{4, 0}, {4, 1}, {5, 1}, {5, 2}},
            {{4, 1}, {5, 1}, {5, 0}, {6, 0}}
    };

};