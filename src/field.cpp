#include <iostream>
#include "field.h"

bool Field::IsCellEmpty(Position position) const
{
    if(position.x < 0 || position.y < 0) { return false; }
    if(position.x >= 10 || position.y >= 20) { return false; }
    if(cells[position.y][position.x] != sf::Color::White) { return false; }
    return true;
}

bool Field::CanMove(Shape::Shape& shape, MOVE_DIRECTION direction) const
{
    for(const auto& block : shape.GetBlocks())
    {
        if(!IsCellEmpty({block.x - 1, block.y}))
        {
            if(direction == MOVE_DIRECTION::LEFT) { return false; }
        }
        if(!IsCellEmpty({block.x + 1, block.y}))
        {
            if(direction == MOVE_DIRECTION::RIGHT) { return false; }
        }
        if(!IsCellEmpty({block.x, block.y + 1}))
        {
            if(direction == MOVE_DIRECTION::DOWN) { return false; }
        }
    }

    return true;
}

bool Field::Move(Shape::Shape& shape, MOVE_DIRECTION direction)
{
    if(!CanMove(shape, direction))
    {
        return false;
    }

    switch (direction)
    {
        case MOVE_DIRECTION::LEFT:
            shape.MoveLeft();
            break;
        case MOVE_DIRECTION::RIGHT:
            shape.MoveRight();
            break;
        case MOVE_DIRECTION::DOWN:
            shape.MoveDown();
            break;
    }

    return true;
}

void Field::UpdateField(Shape::Shape& shape)
{
    for(const auto& block : shape.GetBlocks())
    {
        cells[block.y][block.x] = shape.GetColor();
    }

    for(int i = 19; i >= 0; --i)
    {
        bool f = false;
        for(int j = 0; j < 10; ++j)
        {
            if(cells[i][j] == sf::Color::White)
            {
                f = true;
                break;
            }
        }

        if(f) { continue; }

        for(int j = 0; j < 10; ++j)
        {
            cells[i][j] = sf::Color::White;
        }

        for(int k = i - 1; k >= 0; --k)
        {
            for(int j = 0; j < 10; ++j)
            {
                cells[k + 1][j] = cells[k][j];
                cells[k][j] = sf::Color::White;
            }
        }

        i++;
    }
}