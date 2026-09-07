#include "Player.h"
#include <math.h>

void Player::sMovement(){
  if((movement.moving_left) && (movement.moving_up == false) && (movement.moving_down == false))
  {
    transform.position.x -= transform.acceleration.x;
    sprite.setPosition(transform.position);
  }
  else if((movement.moving_right) && (movement.moving_up == false) && (movement.moving_down == false))
  {
    transform.position.x += transform.acceleration.x;
    sprite.setPosition(transform.position);
  }

  if((movement.moving_up) && (movement.moving_left == false) && (movement.moving_right == false))
  {
    transform.position.y -= transform.acceleration.y;
    sprite.setPosition(transform.position);
  }
  else if((movement.moving_down) && (movement.moving_left == false) && (movement.moving_right == false))
  {
    transform.position.y += transform.acceleration.y;
    sprite.setPosition(transform.position);
  }
}

void Player::Walk_to_destination(sf::Vector2f destination)
{

  if((destination.y > sprite.getPosition().y) && ((destination.y - sprite.getPosition().y) >= transform.acceleration.y))
  {
    transform.position.y += transform.acceleration.y;
    sprite.setPosition(transform.position);

    return;
  }
  else if(destination.y < sprite.getPosition().y && ((sprite.getPosition().y - destination.y) >= transform.acceleration.y))
  {
    transform.position.y -= transform.acceleration.y;
    sprite.setPosition(transform.position);
    return;
  }
  
  if(destination.x > sprite.getPosition().x && ((destination.x - sprite.getPosition().x) >= transform.acceleration.x))
  {
    transform.position.x += transform.acceleration.x;
    sprite.setPosition(transform.position);
    return;
  }
  else if(destination.x < sprite.getPosition().x && ((sprite.getPosition().x - destination.x) >= transform.acceleration.x))
  {
    transform.position.x -= transform.acceleration.x;
    sprite.setPosition(transform.position);
    return;
  }
}

Player::Player(AssetManager &am)
{
  // Generate transform
  transform.position = position;
  transform.maxVel = mov_pix / (0.5 * mov_seconds);
  transform.acceleration.x = pow(transform.maxVel,2) / (2 * mov_pix);
  transform.acceleration.y = pow(transform.maxVel,2) / (2 * mov_pix);

  // Assign sprite
}


