#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>
#include <cassert>

#include "field/field.h"

const int WINDOW_WIDTH = 10;
const int WINDOW_HEIGHT = 20;

void Tetris()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH * 40, WINDOW_HEIGHT * 40), "Tetris");

    Field field;
    Shape::Shape shape;

    auto lastFallTime = std::chrono::high_resolution_clock::now();

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
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { direction = MoveDirection::DOWN; }
                field.Move(shape, direction);
            }
        }

        for(int i = 0; i < field.WIDTH; ++i)
        {
            for(int j = 0; j < field.HEIGHT; ++j)
            {
                float x = i * 40.f;
                float y = j * 40.f;

                sf::RectangleShape block(sf::Vector2f(40, 40));
                block.setPosition(x, y);

                block.setFillColor(field.GetColor(j, i));

                block.setOutlineThickness(1.3f);
                block.setOutlineColor(sf::Color(125, 125, 125));

                window.draw(block);
            }
        }

        for(const auto& block : shape.blocks)
        {
            float x = block.x * 40.f;
            float y = block.y * 40.f;

            if(!field.IsCellEmpty(block))
            {
                std::cout << "GAME OVER!";
                return;
            }

            sf::RectangleShape piece(sf::Vector2f(40, 40));

            piece.setFillColor(shape.color);

            piece.setPosition(x, y);

            piece.setOutlineThickness(1.3f);
            piece.setOutlineColor(sf::Color(125, 125, 125));

            window.draw(piece);
        }

        auto now = std::chrono::high_resolution_clock::now();
        int timeSinceLastFall = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastFallTime).count();
        if (timeSinceLastFall > 300) {
            lastFallTime = now;
            if (!field.Move(shape, MoveDirection::DOWN))
            {
                field.UpdateField(shape);
                shape.Change();
            }
        }

        window.display();
    }
}