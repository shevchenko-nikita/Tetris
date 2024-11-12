#include <SFML/Graphics.hpp>

#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>

#include "field/field.h"

const int WINDOW_WIDTH = 10;
const int WINDOW_HEIGHT = 20;

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH * 40, WINDOW_HEIGHT * 40), "Tetris");

    Shape shape;

    Field field;

    while (window.isOpen())
    {
        sf::Event event;
        MoveDirection direction = MoveDirection::NONE;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { direction = MoveDirection::LEFT; }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { direction = MoveDirection::RIGHT; }
            }
        }

        field.Move(shape, direction);

        window.clear(sf::Color::White);

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

        for(const auto& block : shape.blocks)
        {
            float x = block.x * 40.f;
            float y = block.y * 40.f;

            sf::RectangleShape piece(sf::Vector2f(40, 40));

            switch (shape.color)
            {
                case BlockColors::RED:
                    piece.setFillColor(sf::Color::Red);
                    break;
                case BlockColors::BLUE:
                    piece.setFillColor(sf::Color::Blue);
                    break;
                case BlockColors::YELLOW:
                    piece.setFillColor(sf::Color::Yellow);
                    break;
                case BlockColors::ORANGE:
                    piece.setFillColor(sf::Color::Magenta);
                    break;
                case BlockColors::GREEN:
                    piece.setFillColor(sf::Color::Red);
                    break;
            }

            piece.setPosition(x, y);

            piece.setOutlineThickness(1.f);
            piece.setOutlineColor(sf::Color(125, 125, 125));

            window.draw(piece);
        }

        field.Move(shape, MoveDirection::DOWN);
//        std::this_thread::sleep_for(std::chrono::milliseconds(650));

        window.display();
    }

    return 0;
}
