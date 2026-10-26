#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Helpers.h"
#include "Gameplay.h"

Gameplay::Gameplay()
{
}

Gameplay::Gameplay(AssetManager &am)
{
  player = Player(am);
  holder.setFont(am.font);
  holder.setString("Gameplay");
  holder.setCharacterSize(60);
  holder.setFillColor(sf::Color::Black);
  holder.setPosition(50,50);
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

void Gameplay::update(StatusFlags &flags)
{
  if((flags.gameplay) && (!flags.pause_menu))
  {
    player.sMovement();
  }
}

void Gameplay::draw(sf::RenderWindow &window,StatusFlags &flags)
{
  if(flags.gameplay)
  {
    //window.draw(holder);
    player.draw(window);
  }
}
