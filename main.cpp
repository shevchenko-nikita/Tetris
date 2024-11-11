#include <SFML/Graphics.hpp>

#include <iostream>

#include "field/field.h"

const int WIDTH = 10;
const int HEIGHT = 20;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH * 40, HEIGHT * 40), "Tetris");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        Field field;

        for(int i = 0; i < field.WIDTH; ++i)
        {
            for(int j = 0; j < field.HEIGHT; ++j)
            {
                float x = i * 40.f;
                float y = j * 40.f;

                sf::RectangleShape block(sf::Vector2f(40, 40));
                block.setPosition(x, y);

                block.setOutlineThickness(1.f);
                block.setOutlineColor(sf::Color(125, 125, 125));

                window.draw(block);
            }
        }

        window.display();
    }

    return 0;
}
