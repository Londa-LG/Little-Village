#pragma once
#include <SFML/Grahics.hpp>
#include "Helpers.h"

class StartMenu
{
  public:
    StartMenu();
    void draw(sf::RenderWindw &window);
    void update(StatusFlags &flags);
};

class PauseMenu
{
  public:
    PauseMenu();
    void draw(sf::RenderWindw &window);
    void update(StatusFlags &flags);
};

class SettingsMenu
{
  public:
    SettingsMenu();
    void draw(sf::RenderWindw &window);
    void update(StatusFlags &flags);
};
