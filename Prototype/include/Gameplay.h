#pragma once
#include <SFML/Graphics.hpp>
#include "Helpers.h"
#include "Player.h"

class Gameplay
{
  public:
    Player player;
    sf::Text holder;

    Gameplay();
    Gameplay(AssetManager &am);
    void update(StatusFlags &flags);
    void draw(sf::RenderWindow &window,StatusFlags &flags);
    void event_handling(sf::Event &event,StatusFlags &flags);
};
