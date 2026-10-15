#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

struct BoundingBox
{
  int top;
  int left;
  int right;
  int bottom;
  sf::Vector2f size;
  sf::RectangleShape sprite;
};

void handle_collison_player_box(Player &player, BoundingBox &b_box);
bool collision_detection_player(Player &player, BoundingBox b_box);
bool collision_detection_box(BoundingBox b_box1,BoundingBox b_box2);
bool collision_detection_point(BoundingBox b_box, sf::Vector2f point);
BoundingBox generate_bounding_box(sf::Vector2f position,sf::Vector2f size);
