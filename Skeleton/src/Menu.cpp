#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Helpers.h"
#include "Settings.h"

StartMenu::StartMenu(AssetManager &am,Settings &set)
{
  title.setFont(am.font);
  title.setString("Little Village");
  title.setCharacterSize(40);
  title.setStyle(sf::Text::Bold);
  title.setFillColor(sf::Color::Black);
  title.setPosition((set.width/2 - 150),(set.height/2 - 50));

  start_ins.setFont(am.font);
  start_ins.setString("Click Enter to start");

  start_ins.setCharacterSize(20);
  start_ins.setFillColor(sf::Color::Black);
  start_ins.setPosition((set.width/2 - 100),(set.height - 200));
}

void StartMenu::draw(sf::RenderWindow &window,StatusFlags &flags)
{
  if(flags.start_menu)
  {
    window.draw(title);
    window.draw(start_ins);
  }
}

void StartMenu::update(sf::Event &event,sf::RenderWindow &window,StatusFlags &flags)
{
  if(flags.start_menu)
  {
    if(event.type == sf::Event::KeyPressed)
    {
      if(event.key.code == sf::Keyboard::Enter)
        {
          flags.gameplay = true;
          flags.start_menu = false;
        }
    }
  }
}
