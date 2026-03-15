#include "MenuButton.h"

MenuButton::MenuButton(
    float x,float y,
    float width,float height,
    const std::string& buttonText,
    sf::Font& font)
{
    rect.setSize({width,height});
    rect.setPosition(x,y);

    rect.setFillColor(sf::Color(70,130,180));

    text.setFont(font);
    text.setString(buttonText);
    text.setCharacterSize(24);

    auto b=text.getLocalBounds();

    text.setOrigin(
        b.left+b.width/2,
        b.top+b.height/2
    );

    text.setPosition(x+width/2,y+height/2);

    hovered=false;
}

bool MenuButton::isMouseOver(const sf::Vector2i& mousePos)
{
    hovered=rect.getGlobalBounds().contains(
        (sf::Vector2f)mousePos
    );

    return hovered;
}

void MenuButton::draw(sf::RenderWindow& window)
{
    window.draw(rect);
    window.draw(text);
}

sf::FloatRect MenuButton::getBounds() const
{
    return rect.getGlobalBounds();
}