#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

struct BoundingBox
{
  bool tree;

  int top;
  int left;
  int right;
  int bottom;
  sf::Vector2f size;
  sf::RectangleShape sprite;
};

bool collision_detection_tree(Player &player,BoundingBox b_box);
bool collision_detection_player(Player &player, BoundingBox b_box);
bool collision_detection_box(BoundingBox b_box1,BoundingBox b_box2);
void handle_collision_player_box(Player &player, BoundingBox &b_box);
bool collision_detection_point(BoundingBox b_box, sf::Vector2f point);
BoundingBox generate_bounding_box(sf::Vector2f position,sf::Vector2f size);
