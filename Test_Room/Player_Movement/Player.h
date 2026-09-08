#pragma once
#include <memory>
#include "AssetManager.h"

struct Transform{
  float maxVel;
  sf::Vector2f position;
  sf::Vector2f acceleration;
};

struct Movement{
  bool running;
  bool walking;
  bool moving_up;
  bool moving_down;
  bool moving_left;
  bool moving_right;
};

class Player{
  public:
    bool moving;
    bool squashed;
    sf::Sprite sprite;
    Movement movement;
    Transform transform;

    float mov_pix = 4;
    float mov_seconds = 2;
    sf::Vector2f position = {400,300};

    Player(AssetManager &am);
    void sMovement();
    void Walk_to_destination(sf::Vector2f destination);
    void draw(sf::RenderWindow &window);
};










