#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class MenuButton
{
private:

    sf::RectangleShape rect;
    sf::Text text;
    bool hovered;

public:

    MenuButton(
        float x,
        float y,
        float width,
        float height,
        const std::string& buttonText,
        sf::Font& font
    );

    bool isMouseOver(const sf::Vector2i& mousePos);

    void draw(sf::RenderWindow& window);

    sf::FloatRect getBounds() const;

};