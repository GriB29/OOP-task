#pragma once

#include <SFML/Graphics.hpp>
#include "Board3x3.h"
#include "Board4x4.h"

class Renderer
{
public:

    static void drawGrid(
        sf::RenderWindow& window,
        int size,
        int startX,
        int startY
    );

    static void drawSymbols(
        sf::RenderWindow& window,
        const Board3x3& game,
        int startX,
        int startY
    );

    static void drawSymbols4x4(
        sf::RenderWindow& window,
        const Board4x4& game,
        int startX,
        int startY
    );

};