#include "field.h"

bool Field::CanMove(Shape& shape, MoveDirection direction)
{
    for(const auto& block : shape.blocks)
    {
        if(block.x - 1 < 0 || blocks[block.x - 1][block.y] != BlockColors::NONE)
        {
            if(direction == MoveDirection::LEFT) { return false; }
        }
        if(block.x + 1 >= 10 || blocks[block.x + 1][block.y] != BlockColors::NONE)
        {
            if(direction == MoveDirection::RIGHT) { return false; }
        }
        if(block.y + 1 >= 20 || blocks[block.x][block.y + 1] != BlockColors::NONE)
        {
            if(direction == MoveDirection::DOWN) { return false; }
        }
    }

    return true;
}

bool Field::Move(Shape& shape, MoveDirection direction)
{
    if(!CanMove(shape, direction))
    {
        return false;
    }

    for(auto& block : shape.blocks)
    {
        switch (direction)
        {
            case MoveDirection::LEFT:
                block.x -= 1;
                break;
            case MoveDirection::RIGHT:
                block.x += 1;
                break;
            case MoveDirection::DOWN:
                block.y += 1;
                break;
        }
    }

    return true;
}

void Field::UpdateField(Shape& shape, MoveDirection direction)
{
    Move(shape, direction);

    for(const auto& block : shape.blocks)
    {
        blocks[block.x][block.y] = shape.color;
    }
}