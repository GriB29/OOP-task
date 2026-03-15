#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "Constants.h"
#include "GameState.h"

#include "Board3x3.h"
#include "Board4x4.h"
#include "Renderer.h"
#include "AI.h"
#include "MenuButton.h"
#include "FontLoader.h"


void drawMenu(sf::RenderWindow& window, sf::Font& font, std::vector<MenuButton>& buttons)
{
    sf::Text title;

    title.setFont(font);
    title.setString("Infinity TicTac Game");
    title.setCharacterSize(64);
    title.setFillColor(sf::Color(50,100,150));

    title.setPosition(
        WINDOW_WIDTH/2 - title.getGlobalBounds().width/2,
        60
    );

    window.draw(title);

    for(auto& b : buttons)
        b.draw(window);
}



void drawGame3x3(sf::RenderWindow& window, sf::Font& font, Board3x3& board)
{
    int gridX = (WINDOW_WIDTH - MAX_SIZE*CELL_SIZE)/2;
    int gridY = 100;

    Renderer::drawGrid(window, MAX_SIZE, gridX, gridY);

    Renderer::drawSymbols(window, board, gridX, gridY);

    sf::Text info;
    info.setFont(font);
    info.setCharacterSize(28);

    if(board.turn % 2 == 1)
    {
        info.setString("Player 1 Turn (X)");
        info.setFillColor(sf::Color::Red);
    }
    else
    {
        info.setString("Player 2 Turn (O)");
        info.setFillColor(sf::Color::Blue);
    }

    info.setPosition(
        WINDOW_WIDTH/2 - info.getGlobalBounds().width/2,
        20
    );

    window.draw(info);
}



void drawGameVsAI(sf::RenderWindow& window, sf::Font& font, Board3x3& board)
{
    int gridX = (WINDOW_WIDTH - MAX_SIZE*CELL_SIZE)/2;
    int gridY = 100;

    Renderer::drawGrid(window, MAX_SIZE, gridX, gridY);

    Renderer::drawSymbols(window, board, gridX, gridY);

    sf::Text info;
    info.setFont(font);
    info.setCharacterSize(28);

    if(board.turn % 2 == 1)
    {
        info.setString("Your Turn (X)");
        info.setFillColor(sf::Color::Red);
    }
    else
    {
        info.setString("Computer Turn (O)");
        info.setFillColor(sf::Color::Blue);
    }

    info.setPosition(
        WINDOW_WIDTH/2 - info.getGlobalBounds().width/2,
        20
    );

    window.draw(info);
}



void drawGame4x4(sf::RenderWindow& window, sf::Font& font, Board4x4& board)
{
    int gridX = (WINDOW_WIDTH - MAX_SIZE_4*CELL_SIZE)/2;
    int gridY = 80;

    Renderer::drawGrid(window, MAX_SIZE_4, gridX, gridY);

    Renderer::drawSymbols4x4(window, board, gridX, gridY);

    int turn = (board.turn - 1) % 3;

    std::string text;
    sf::Color color;

    if(turn==0)
    {
        text="Player 1 Turn (X)";
        color=sf::Color::Red;
    }
    else if(turn==1)
    {
        text="Player 2 Turn (O)";
        color=sf::Color::Blue;
    }
    else
    {
        text="Computer Turn (C)";
        color=sf::Color::Green;
    }

    sf::Text info;

    info.setFont(font);
    info.setString(text);
    info.setCharacterSize(28);
    info.setFillColor(color);

    info.setPosition(
        WINDOW_WIDTH/2 - info.getGlobalBounds().width/2,
        20
    );

    window.draw(info);
}




int main()
{
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        "Infinity TicTac Game"
    );

    window.setFramerateLimit(60);


    sf::Font font = FontLoader::loadFont();


    GameState state = GameState::MENU;


    Board3x3 board3;
    Board4x4 board4;


    std::vector<MenuButton> buttons;

    float buttonWidth = 500;
    float buttonHeight = 60;

    float x = (WINDOW_WIDTH - buttonWidth)/2;

    buttons.emplace_back(
        x,200,buttonWidth,buttonHeight,
        "Human vs Human (3x3)",
        font
    );

    buttons.emplace_back(
        x,280,buttonWidth,buttonHeight,
        "Human vs AI (3x3)",
        font
    );

    buttons.emplace_back(
        x,360,buttonWidth,buttonHeight,
        "Human vs Human vs AI (4x4)",
        font
    );

    buttons.emplace_back(
        x,440,buttonWidth,buttonHeight,
        "Exit",
        font
    );



    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }


        sf::Vector2i mousePos = sf::Mouse::getPosition(window);


        if(state == GameState::MENU)
        {
            for(auto& b : buttons)
                b.isMouseOver(mousePos);

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if(buttons[0].getBounds().contains((sf::Vector2f)mousePos))
                {
                    board3.reset();
                    state = GameState::GAME_MODE_1;
                }

                if(buttons[1].getBounds().contains((sf::Vector2f)mousePos))
                {
                    board3.reset();
                    state = GameState::GAME_MODE_2;
                }

                if(buttons[2].getBounds().contains((sf::Vector2f)mousePos))
                {
                    board4.reset();
                    state = GameState::GAME_MODE_3;
                }

                if(buttons[3].getBounds().contains((sf::Vector2f)mousePos))
                {
                    window.close();
                }
            }
        }



        if(state == GameState::GAME_MODE_2)
        {
            if(board3.turn % 2 == 0 && !board3.gameEnded)
            {
                AI::computerMove3x3(board3,"o","x");
                board3.turn++;
            }
        }



        window.clear(sf::Color::White);


        if(state == GameState::MENU)
        {
            drawMenu(window,font,buttons);
        }

        else if(state == GameState::GAME_MODE_1)
        {
            drawGame3x3(window,font,board3);
        }

        else if(state == GameState::GAME_MODE_2)
        {
            drawGameVsAI(window,font,board3);
        }

        else if(state == GameState::GAME_MODE_3)
        {
            drawGame4x4(window,font,board4);
        }


        window.display();
    }

    return 0;
}
