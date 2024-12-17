#pragma once

#include "shape.h"

#include <vector>
#include <cstdlib>

enum class MOVE_DIRECTION
{
    NONE,
    DOWN,
    LEFT,
    RIGHT
};

class Field
{
public:
    const int CELL_SIZE = 40;

    // Field size in blocks
    //
    const int WIDTH = 10;
    const int HEIGHT = 20;

    Field()
    {
        for(int i = 0; i < HEIGHT; ++i)
        {
            for(int j = 0; j < WIDTH; ++j)
            {
                cells[i][j] = sf::Color::White;
            }
        }
    }

    bool IsCellEmpty(Shape::Coordinate position) const;
    bool CanMove(Shape::Shape& shape, MOVE_DIRECTION direction) const;
    bool Move(Shape::Shape& shape, MOVE_DIRECTION direction);

    sf::Color GetColor(int i, int j) { return cells[i][j]; }

    void UpdateField(Shape::Shape& shape);

private:
    sf::Color cells[20][10];
};