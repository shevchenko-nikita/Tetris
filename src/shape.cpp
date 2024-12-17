#include "shape.h"

enum class MOVE_DIRECTION;

std::vector<Position> Shape::GetBlocks() const
{
    std::vector<Position> coordinates = blocks;
    for(auto& pr : coordinates)
    {
        pr.x += shift_x;
        pr.y += shift_y;
    }

    return coordinates;
}

sf::Color Shape::GetColor() const
{
    return color;
}

void Shape::MoveLeft()
{
    shift_x -= 1;
}

void Shape::MoveRight()
{
    shift_x += 1;
}

void Shape::MoveDown()
{
    shift_y += 1;
}

void Shape::Change()
{
    static int colorId = 0;
    shapeType = static_cast<SHAPE_TYPES>(rand() % 7);

    switch (shapeType)
    {
        case SHAPE_TYPES::J_BLOCK:
            blocks = J_BLOCK_STATES[0];
            break;
        case SHAPE_TYPES::L_BLOCK:
            blocks = L_BLOCK_STATES[0];
            break;
        case SHAPE_TYPES::O_BLOCK:
            blocks = O_BLOCK_STATES[0];
            break;
        case SHAPE_TYPES::I_BLOCK:
            blocks = I_BLOCK_STATES[0];
            break;
        case SHAPE_TYPES::E_BLOCK:
            blocks = E_BLOCK_STATES[0];
            break;
        case SHAPE_TYPES::Z_BLOCK:
            blocks = Z_BLOCK_STATES[0];
            break;
        case SHAPE_TYPES::S_BLOCK:
            blocks = S_BLOCK_STATES[0];
            break;
    }

    shift_x = 0;
    shift_y = 0;
    state = 0;
    color = COLORS[colorId];
    colorId = (colorId + 1) % 5;
}

void Shape::Rotate()
{
    ++state;
    switch (shapeType)
    {
        case SHAPE_TYPES::J_BLOCK:
            state %= 4;
            blocks = J_BLOCK_STATES[state];
            break;
        case SHAPE_TYPES::L_BLOCK:
            state %= 4;
            blocks = L_BLOCK_STATES[state];
            break;
        case SHAPE_TYPES::O_BLOCK:
            state %= 1;
            blocks = O_BLOCK_STATES[state];
            break;
        case SHAPE_TYPES::I_BLOCK:
            state %= 2;
            blocks = I_BLOCK_STATES[state];
            break;
        case SHAPE_TYPES::E_BLOCK:
            state %= 4;
            blocks = E_BLOCK_STATES[state];
            break;
        case SHAPE_TYPES::Z_BLOCK:
            state %= 2;
            blocks = Z_BLOCK_STATES[state];
            break;
        case SHAPE_TYPES::S_BLOCK:
            state %= 2;
            blocks = S_BLOCK_STATES[state];
            break;
    }
}