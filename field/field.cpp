#include <iostream>
#include "field.h"

bool Field::CanMove(Shape::Shape& shape, MoveDirection direction)
{
    for(const auto& block : shape.blocks)
    {
        if(block.x - 1 < 0 || cells[block.x - 1][block.y] != BlockColors::NONE)
        {
            if(direction == MoveDirection::LEFT) { return false; }
        }
        if(block.x + 1 >= 10 || cells[block.x + 1][block.y] != BlockColors::NONE)
        {
            if(direction == MoveDirection::RIGHT) { return false; }
        }
        if(block.y + 1 >= 20 || cells[block.x][block.y + 1] != BlockColors::NONE)
        {
            if(direction == MoveDirection::DOWN) { return false; }
        }
    }

    return true;
}

bool Field::Move(Shape::Shape& shape, MoveDirection direction)
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

void Field::UpdateField(Shape::Shape& shape)
{
    for(const auto& block : shape.blocks)
    {
        cells[block.x][block.y] = shape.color;
    }
}