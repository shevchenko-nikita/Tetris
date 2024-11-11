#pragma once

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
    DOWN,
    LEFT,
    RIGHT
};

class Field
{
public:
    const int BLOCK_SIZE = 40;
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
                blocks[i][j] = BlockColors::NONE;
            }
        }
    }

//    bool CanMove(MoveDirection direction);
//    bool Move(MoveDirection direction);


private:
    // In blocks[i][j] we contain info about color of the block.
    // If there is no block in this position - there will be NONE.
    //
    BlockColors blocks[20][10];

};