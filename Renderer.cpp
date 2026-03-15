#include "Renderer.h"
#include "Constants.h"

void Renderer::drawGrid(
    sf::RenderWindow& window,
    int size,
    int startX,
    int startY)
{
    for(int i=0;i<=size;i++)
    {
        sf::Vertex vLine[] =
        {
            sf::Vertex(sf::Vector2f(startX+i*CELL_SIZE,startY)),
            sf::Vertex(sf::Vector2f(startX+i*CELL_SIZE,startY+size*CELL_SIZE))
        };

        window.draw(vLine,2,sf::Lines);

        sf::Vertex hLine[] =
        {
            sf::Vertex(sf::Vector2f(startX,startY+i*CELL_SIZE)),
            sf::Vertex(sf::Vector2f(startX+size*CELL_SIZE,startY+i*CELL_SIZE))
        };

        window.draw(hLine,2,sf::Lines);
    }
}

void Renderer::drawSymbols(
    sf::RenderWindow& window,
    const Board3x3& game,
    int startX,
    int startY)
{
    for(int i=0;i<MAX_SIZE;i++)
        for(int j=0;j<MAX_SIZE;j++)
        {
            std::string s=game.getCell(i,j);

            if(s=="x")
            {
                sf::Vertex l1[]={
                    sf::Vertex(sf::Vector2f(startX+j*CELL_SIZE+15,startY+i*CELL_SIZE+15),sf::Color::Red),
                    sf::Vertex(sf::Vector2f(startX+j*CELL_SIZE+CELL_SIZE-15,startY+i*CELL_SIZE+CELL_SIZE-15),sf::Color::Red)
                };

                window.draw(l1,2,sf::Lines);
            }

            if(s=="o")
            {
                sf::CircleShape c(CELL_SIZE/2-15);
                c.setOutlineColor(sf::Color::Blue);
                c.setOutlineThickness(2);
                c.setFillColor(sf::Color::Transparent);

                c.setPosition(startX+j*CELL_SIZE+15,startY+i*CELL_SIZE+15);

                window.draw(c);
            }
        }
}

void Renderer::drawSymbols4x4(
    sf::RenderWindow& window,
    const Board4x4& game,
    int startX,
    int startY)
{
    for(int i=0;i<MAX_SIZE_4;i++)
        for(int j=0;j<MAX_SIZE_4;j++)
        {
            std::string s=game.getCell(i,j);

            if(s=="x")
            {
                sf::Vertex l1[]={
                    sf::Vertex(sf::Vector2f(startX+j*CELL_SIZE+15,startY+i*CELL_SIZE+15),sf::Color::Red),
                    sf::Vertex(sf::Vector2f(startX+j*CELL_SIZE+CELL_SIZE-15,startY+i*CELL_SIZE+CELL_SIZE-15),sf::Color::Red)
                };

                window.draw(l1,2,sf::Lines);
            }

            if(s=="o")
            {
                sf::CircleShape c(CELL_SIZE/2-15);

                c.setOutlineColor(sf::Color::Blue);
                c.setOutlineThickness(2);
                c.setFillColor(sf::Color::Transparent);

                c.setPosition(startX+j*CELL_SIZE+15,startY+i*CELL_SIZE+15);

                window.draw(c);
            }
        }
}