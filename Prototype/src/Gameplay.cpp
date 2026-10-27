#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Helpers.h"
#include "Gameplay.h"

Gameplay::Gameplay()
{
}

Gameplay::Gameplay(sf::RenderWindow &window,AssetManager &am)
{
  camera.reset(sf::FloatRect(0,0,camera_size.x,camera_size.y));
  //window.setView(camera);

  player = Player(am);
}

void Gameplay::event_handling(sf::Event &event,StatusFlags &flags)
{
  if((flags.gameplay) && (!flags.pause_menu))
  {
    if(event.type == sf::Event::KeyPressed)
    {
      if(event.key.code == sf::Keyboard::Escape)
      {
        flags.pause_menu = true;
      }
      if(event.key.code == sf::Keyboard::A)
      {
        player.movement.moving_left = true;
      }
      if(event.key.code == sf::Keyboard::D)
      {
        player.movement.moving_right = true;
      }
      if(event.key.code == sf::Keyboard::W)
      {
        player.movement.moving_up = true;
      }
      if(event.key.code == sf::Keyboard::S)
      {
        player.movement.moving_down = true;
      }
    }

    if(event.type == sf::Event::KeyReleased)
    {
      if(event.key.code == sf::Keyboard::A)
      {
        player.movement.moving_left = false;
      }
      if(event.key.code == sf::Keyboard::D)
      {
        player.movement.moving_right = false;
      }
      if(event.key.code == sf::Keyboard::W)
      {
        player.movement.moving_up = false;
      }
      if(event.key.code == sf::Keyboard::S)
      {
        player.movement.moving_down = false;
      }
    }
  }
}

void Gameplay::update(sf::RenderWindow &window,StatusFlags &flags)
{
  if((flags.gameplay) && (!flags.pause_menu))
  {
    player.sMovement();
    camera.setCenter(player.sprite.getPosition().x,player.sprite.getPosition().y);
    window.setView(camera);
  }
}

void Gameplay::draw(sf::RenderWindow &window,StatusFlags &flags)
{
  if((flags.gameplay) && (!flags.pause_menu))
  {
    window.draw(holder);
    player.draw(window);
  }
}
