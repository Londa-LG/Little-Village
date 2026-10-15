#include "Collisions.h"

void handle_collision_player_box(Player &player, BoundingBox &b_box)
{
  float p_top = player.transform.position.y;
  float p_left = player.transform.position.x;
  float p_right = player.transform.position.x + player.size.x;
  float p_bottom = player.transform.position.y + player.size.y;

  if((player.movement.moving_left) && (b_box.right > p_left))
  {
    player.transform.position.x = b_box.left + .5;
    player.sprite.setPosition(player.transform.position);
  }
  if((player.movement.moving_right) && (b_box.left < p_right))
  {
    player.transform.position.x = b_box.left - .5 - player.size.x;
    player.sprite.setPosition(player.transform.position);
  }
  if((player.movement.moving_up) && (b_box.bottom > p_top))
  {
    player.transform.position.y = b_box.bottom + .5;
    player.sprite.setPosition(player.transform.position);
  }
  if((player.movement.moving_down) && (b_box.top < p_bottom))
  {
    player.transform.position.y = b_box.left - .5 - player.size.y;
    player.sprite.setPosition(player.transform.position);
  }
}

bool collision_detection_player(Player &player, BoundingBox b_box)
{
  float p_top = player.transform.position.y;
  float p_left = player.transform.position.x;
  float p_right = player.transform.position.x + player.size.x;
  float p_bottom = player.transform.position.y + player.size.y;

  if(p_right < b_box.left)
  {
    return false;
  }
  if(p_left > b_box.right)
  {
    return false;
  }
  if(p_bottom < b_box.top)
  {
    return false;
  }
  if(p_top > b_box.bottom)
  {
    return false;
  }

  return true;
}

bool collision_detection_box(BoundingBox b_box1,BoundingBox b_box2)
{
  if(b_box1.right < b_box2.left)
  {
    return false;
  }
  if(b_box1.left > b_box2.right)
  {
    return false;
  }
  if(b_box1.bottom < b_box2.top)
  {
    return false;
  }
  if(b_box1.top > b_box2.bottom)
  {
    return false;
  }

  return true;
}

bool collision_detection_point(BoundingBox b_box, sf::Vector2f point)
{
  if((b_box.left < point.x) && (b_box.right > point.x) && (b_box.top < point.y) && (b_box.bottom > point.y))
  {
    return true;
  }

  return false;
}

BoundingBox generate_bounding_box(sf::Vector2f position,sf::Vector2f size)
{
  BoundingBox b_box;

  b_box.size = size;
  b_box.top = position.y;
  b_box.left = position.x;
  b_box.right = position.x + size.x;
  b_box.bottom = position.y + size.y;

  b_box.sprite.setSize(size);
  b_box.sprite.setPosition(position);
  b_box.sprite.setOutlineThickness(2);
  b_box.sprite.setOutlineColor(sf::Color::Blue);
  b_box.sprite.setFillColor(sf::Color::Transparent);

  return b_box;
}
