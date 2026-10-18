#pragma once
#include "Menu.h"
#include "Helpers.h"
#include "Gameplay.h"

class Game
{
  public:
    AssetManager am;
    StartMenu start;
    PauseMenu pause;
    Gameplay gameplay;
    StatusFlags status;
    SettigsMenu settings;
    sf::RenderWindow window;

    Game();
    void draw();
    void run();
};
