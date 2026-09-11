#include "Character.h"
#include <math.h>

void Character::sMovement(){
  if((destination.y == sprite.getPosition().y) && (destination.x == sprite.getPosition().x) && (destination.y == path_end.y) && (destination.x == path_end.x))
  {
    destination = path_start;
  }
  else if((destination.y == sprite.getPosition().y) && (destination.x == sprite.getPosition().x) && (destination.y == path_start.y) && (destination.x == path_start.x))
  {
    destination = path_end;
  }
}

void Character::Walk_to_destination()
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

Character::Character(AssetManager &am,int sprite_index, sf::Vector2f start, sf::Vector2f end)
{
  movement = {false,false,false,false,false,false};
  path_start = start;
  path_end = end;

  // Generate transform
  transform.position = path_start;
  transform.maxVel = mov_pix / (0.5 * mov_seconds);
  transform.acceleration.x = pow(transform.maxVel,2) / (2 * mov_pix);
  transform.acceleration.y = pow(transform.maxVel,2) / (2 * mov_pix);

  // Destination
  destination = path_end;

  // Assign sprite
  sprite = am.characters[sprite_index];
  sprite.setPosition(path_start);
  sprite.scale(2,2);
}

void Character::draw(sf::RenderWindow &window)
{
  window.draw(sprite);
}
