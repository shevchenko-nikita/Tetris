#include "shape.h"

void Shape::Shape::Change()
{
    static int colorId = 0;
    int shapeId = rand() % 7;

    switch (static_cast<SHAPE_TYPES>(shapeId))
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

    color = COLORS[colorId];
    colorId = (colorId + 1) % 5;
}

void Shape::Shape::Rotate()
{

}