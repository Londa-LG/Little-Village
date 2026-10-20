#pragma once
#include <SFML/Graphics.hpp>
#include "Helpers.h"
#include "Settings.h"

class StartMenu
{
  public:
    sf::Text title;
    sf::Text start_ins;

    StartMenu(AssetManager &am,Settings &set);

    void draw(sf::RenderWindow &window,StatusFlags &flags);
    void update(sf::Event &event,sf::RenderWindow &window,StatusFlags &flags);
};

class PauseMenu
{
  public:
    PauseMenu();
    void update(StatusFlags &flags);
    void draw(sf::RenderWindow &window);
};

class SettingsMenu
{
  public:
    SettingsMenu();

    void update(StatusFlags &flags);
    void draw(sf::RenderWindow &window);
};
