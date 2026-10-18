#pragma once
#include <SFML/Graphics.hpp>
#include "Helpers"

class Gameplay
{
  public:
    Gameplay();
    void update(StatusFlags &flags);
    void draw(sf::RenderWindow &window);
};
