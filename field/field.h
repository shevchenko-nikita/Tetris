#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <cstdlib>

const std::array<sf::Color, 5> COLORS =
{
    sf::Color(3, 65, 174),
    sf::Color(114, 203, 59),
    sf::Color(255, 213, 0),
    sf::Color(255, 151, 28),
    sf::Color(255, 50, 19)
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
            static int colorId = 0;
            int shapeId = rand() % 7;

            blocks = ALL_SHAPES[shapeId];
            color = COLORS[colorId];
            colorId = (colorId + 1) % 5;
        }

        std::vector<Coordinate> blocks;
        sf::Color color;
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
                cells[i][j] = sf::Color::White;
            }
        }
    }

    bool IsCellEmpty(Shape::Coordinate position) const;
    bool CanMove(Shape::Shape& shape, MoveDirection direction) const;
    bool Move(Shape::Shape& shape, MoveDirection direction);

    sf::Color GetColor(int i, int j) { return cells[i][j]; }

    void UpdateField(Shape::Shape& shape);

private:
    sf::Color cells[20][10];
};