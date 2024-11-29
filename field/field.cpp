#include <iostream>
#include "field.h"

bool Field::IsCellEmpty(Shape::Coordinate position) const
{
    if(position.x < 0 || position.y < 0) { return false; }
    if(position.x >= 10 || position.y >= 20) { return false; }
    if(cells[position.y][position.x] != BlockColors::NONE) { return false; }
    return true;
}

bool Field::CanMove(Shape::Shape& shape, MoveDirection direction) const
{
    for(const auto& block : shape.blocks)
    {
        if(!IsCellEmpty({block.x - 1, block.y}))
        {
            if(direction == MoveDirection::LEFT) { return false; }
        }
        if(!IsCellEmpty({block.x + 1, block.y}))
        {
            if(direction == MoveDirection::RIGHT) { return false; }
        }
        if(!IsCellEmpty({block.x, block.y + 1}))
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
        cells[block.y][block.x] = shape.color;
    }
}