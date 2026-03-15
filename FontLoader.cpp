#include "FontLoader.h"
#include <iostream>

sf::Font FontLoader::loadFont()
{
    sf::Font font;

    if(!font.loadFromFile("arial.ttf"))
        std::cout<<"Font load failed\n";

    return font;
}