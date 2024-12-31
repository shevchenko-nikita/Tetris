#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <time.h>
#include <cassert>

#include "field.h"

const int WINDOW_WIDTH = 18;
const int WINDOW_HEIGHT = 20;

void Tetris()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH * 40, WINDOW_HEIGHT * 40), "Tetris");

    Field field;
    Shape shape;

    auto lastFallTime = std::chrono::high_resolution_clock::now();

    sf::Font font;
    font.loadFromFile("../style/fonts/Poppins-Black.ttf");

    sf::Text record;
    record.setFont(font);
    record.setCharacterSize(24);
    record.setFillColor(sf::Color::Black);
    record.setPosition(12 * 40 + 20, 40);

    while (window.isOpen())
    {
        window.clear(sf::Color::White);

        sf::Event event;
        MOVE_DIRECTION direction = MOVE_DIRECTION::NONE;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { direction = MOVE_DIRECTION::LEFT; }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { direction = MOVE_DIRECTION::RIGHT; }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { direction = MOVE_DIRECTION::DOWN; }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    shape.Rotate();
                    for(const auto& position : shape.GetBlocks())
                    {
                        if (!field.IsCellEmpty(position))
                        {
                            shape.UndoRotate();
                            break;
                        }
                    }
                }
                field.Move(shape, direction);
            }
        }

        for(int i = 0; i < field.HEIGHT; ++i)
        {
            for(int j = 0; j < field.WIDTH; ++j)
            {
                float y = i * 40.f;
                float x = j * 40.f;

                sf::RectangleShape block(sf::Vector2f(40, 40));
                block.setPosition(x, y);

                block.setFillColor(field.GetColor(i, j));

                block.setOutlineThickness(1.3f);
                block.setOutlineColor(sf::Color(125, 125, 125));

                window.draw(block);
            }
        }

        for(const auto& block : shape.GetBlocks())
        {
            float x = block.x * 40.f;
            float y = block.y * 40.f;

            if(!field.IsCellEmpty(block))
            {
                std::cout << "GAME OVER!";
                std::cout << "\n" << field.GetRecord() << std::endl;
                return;
            }

            sf::RectangleShape piece(sf::Vector2f(40, 40));

            piece.setFillColor(shape.GetColor());

            piece.setPosition(x, y);

            piece.setOutlineThickness(1.3f);
            piece.setOutlineColor(sf::Color(125, 125, 125));

            window.draw(piece);
        }

        auto now = std::chrono::high_resolution_clock::now();
        int timeSinceLastFall = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastFallTime).count();
        if (timeSinceLastFall > 300) {
            lastFallTime = now;
            if (!field.Move(shape, MOVE_DIRECTION::DOWN))
            {
                field.UpdateField(shape);
                shape.Change();
            }
        }

        record.setString("Record: " + std::to_string(field.GetRecord()));
        window.draw(record);

        window.display();
    }
}