#pragma once
#include <SFML/Graphics.hpp>
#include "Helpers.h"
#include "Player.h"

class Gameplay
{
  public:
    Player player;
    sf::Text holder;
    sf::View camera;
    sf::Vector2f camera_size = {160,160};

    Gameplay();
    Gameplay(sf::RenderWindow &window,AssetManager &am);

    void draw(sf::RenderWindow &window,StatusFlags &flags);
    void update(sf::RenderWindow &window,StatusFlags &flags);
    void event_handling(sf::Event &event,StatusFlags &flags);
};
