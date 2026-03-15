#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "GameState.h"

class GestureRecognizer
{
public:

    static GestureType recognizeGesture(
        const std::vector<sf::Vector2f>& points,
        sf::FloatRect cellBounds
    );

};