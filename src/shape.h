#pragma once

#include <iostream>
#include <array>
#include <vector>

#include "position.h"
#include "colors.h"

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

    Shape(std::initializer_list<Position> positions)
    : blocks(positions)
    {
    }

    std::vector<Position> GetBlocks() const;
    sf::Color GetColor() const;

    void MoveLeft();
    void MoveRight();
    void MoveDown();

    void Change();
    void Rotate();
    void UndoRotate();

private:
    std::vector<Position> blocks;
    SHAPE_TYPES shapeType;
    uint8_t state = 0;
    sf::Color color;

    int shift_x = 0;
    int shift_y = 0;
};

const std::vector<Position> J_BLOCK_STATES[4] =
{
        {{5, 0}, {5, 1}, {5, 2}, {4, 2}},
        {{4, 0}, {4, 1}, {5, 1}, {6, 1}},
        {{5, 0}, {6, 0}, {5, 1}, {5, 2}},
        {{4, 1}, {5, 1}, {6, 1}, {6, 2}}
};

const std::vector<Position> L_BLOCK_STATES[4] =
{
        {{4, 0}, {5, 0}, {5, 1}, {5, 2}},
        {{4, 1}, {5, 1}, {6, 1}, {6, 0}},
        {{5, 0}, {5, 1}, {5, 2}, {6, 2}},
        {{4, 2}, {4, 1}, {5, 1}, {6, 1}}
};

const std::vector<Position> I_BLOCK_STATES[2] =
{
        {{4, 0}, {4, 1}, {4, 2}, {4, 3}},
        {{3, 1}, {4, 1}, {5, 1}, {6, 1}}
};

const std::vector<Position> O_BLOCK_STATES[4] =
{
        {{4, 0}, {4, 1}, {5, 0}, {5, 1}}
};

const std::vector<Position> E_BLOCK_STATES[4] =
{
        {{4, 1}, {5, 0}, {5, 1}, {5, 2}},
        {{5, 0}, {4, 1}, {5, 1}, {6, 1}},
        {{5, 0}, {5, 1}, {5, 2}, {6, 1}},
        {{4, 1}, {5, 1}, {6, 1}, {5, 2}}
};

const std::vector<Position> Z_BLOCK_STATES[4] =
{
        {{5, 0}, {5, 1}, {4, 1}, {4, 2}},
        {{4, 0}, {5, 0}, {5, 1}, {6, 1}}
};

const std::vector<Position> S_BLOCK_STATES[4] =
{
        {{4, 0}, {4, 1}, {5, 1}, {5, 2}},
        {{4, 1}, {5, 1}, {5, 0}, {6, 0}}
};

