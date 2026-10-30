#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"
#include "Player.h"
#include "Helpers.h"

class Gameplay
{
  public:
    Player player;
    Layer ground;
    Layer objects;
    Layer character;
    sf::Text holder;
    sf::View camera;
    sf::Vector2f camera_size = {300,300};

    Gameplay();
    Gameplay(sf::RenderWindow &window,AssetManager &am);

    void draw(AssetManager &am,sf::RenderWindow &window,StatusFlags &flags);
    void update(sf::RenderWindow &window,StatusFlags &flags);
    void event_handling(sf::Event &event,StatusFlags &flags);
};
