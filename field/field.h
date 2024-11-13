#pragma once

#include <vector>
#include <cstdlib>

enum class BlockColors
{
    NONE,
    BLUE, // #0341AE
    GREEN, // #72CB3B
    YELLOW, // #FFD500
    ORANGE, // #FF971C
    RED // FF3213
};

enum class MoveDirection
{
    NONE,
    DOWN,
    LEFT,
    RIGHT
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
            {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
            {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
            {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
            {{1, 0}, {1, 1}, {0, 1}, {0, 2}},
            {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
            {{0, 0}, {0, 1}, {1, 1}, {1, 2}}
    };

    struct Shape
    {
        Shape()
        {
            Change();
        }

        void Change()
        {
            int shape_id = rand() % 7;
            blocks = ALL_SHAPES[shape_id];
            color = static_cast<BlockColors>(rand() % 5 + 1);
        }

        std::vector<Coordinate> blocks;
        BlockColors color;
    };
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
                cells[i][j] = BlockColors::NONE;
            }
        }
    }

    bool CanMove(Shape::Shape& shape, MoveDirection direction);
    bool Move(Shape::Shape& shape, MoveDirection direction);

    BlockColors GetColor(int i, int j) { return cells[i][j]; }

    void UpdateField(Shape::Shape& shape);

private:
    // In cells[i][j] we contain info about color of the block.
    // If there is no block in this position - there will be NONE.
    //
    BlockColors cells[20][10];

};