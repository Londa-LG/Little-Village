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

class Character{
  public:
    bool moving;
    bool squashed;
    sf::Sprite sprite;
    Movement movement;
    Transform transform;

    float mov_pix = 1;
    float mov_seconds = 2;

    sf::Vector2f destination;
    sf::Vector2f path_start = {200,300};
    sf::Vector2f path_end = {600,300};

    Character(AssetManager &am, int sprite_index,sf::Vector2f start, sf::Vector2f end);

    void sMovement();
    void Walk_to_destination();
    void draw(sf::RenderWindow &window);
};

