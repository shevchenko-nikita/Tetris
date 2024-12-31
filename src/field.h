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

    void UpdateRecord(int filledLinesNum);
    void UpdateField(Shape& shape);

    bool Move(Shape& shape, MOVE_DIRECTION direction);

    int GetRecord() const;
    sf::Color GetColor(int i, int j) const;
    bool IsCellEmpty(Position position) const;
    bool CanMove(Shape& shape, MOVE_DIRECTION direction) const;

private:
    sf::Color cells[20][10];
    int record = 0;
};