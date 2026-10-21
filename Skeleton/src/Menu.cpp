#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Helpers.h"
#include "Settings.h"

Button::Button()
{
}

Button::Button(AssetManager &am,std::string text,sf::Vector2f p_position,sf::Vector2f p_size)
{
  size = p_size;
  position = p_position;

  label.setFont(am.font);
  label.setString(text);
  label.setCharacterSize(18);
  label.setFillColor(sf::Color::White);
  label.setPosition(position.x + 10,position.y + 10);

  button.setSize(size);
  button.setPosition(position);
  button.setOutlineThickness(4);
  button.setFillColor(sf::Color::Blue);
  button.setOutlineColor(sf::Color::Blue);
}

bool Button::detect_click(sf::RenderWindow &window)
{
  if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    sf::Vector2f m_position = {sf::Mouse::getPosition(window).x/1.0f,sf::Mouse::getPosition(window).y/1.0f};

    if((m_position.x > position.x) && (m_position.x < (position.x + size.x)) && (m_position.y > position.y) && (m_position.y < (position.y + size.y)))
    {
      return true;
    }
  }

  return false;
}

void Button::draw(sf::RenderWindow &window)
{
  window.draw(button);
  window.draw(label);
}


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

void StartMenu::update(sf::Event &event,StatusFlags &flags)
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


PauseMenu::PauseMenu(AssetManager &am,Settings &set)
{
  background.setOutlineThickness(4);
  background.setFillColor(sf::Color::Black);
  background.setSize(sf::Vector2f(400,500));
  background.setOutlineColor(sf::Color::Blue);
  background.setPosition((set.width/2 - 200),(set.height/2 - 250));

  btn_quit = Button(am,"Quit",{410,570},{380,20});
  btn_settings = Button(am,"Settings",{410,540},{380,20});
  btn_continue = Button(am,"Continue",{410,510},{380,20});
}
void PauseMenu::handle_quit(sf::RenderWindow &window)
{
  window.close();
}

void PauseMenu::handle_continue(StatusFlags &flags)
{
  flags.gameplay = true;
  flags.pause_menu = false;
}

void PauseMenu::handle_settings(StatusFlags &flags)
{
  flags.settings_menu = true;
  flags.pause_menu = false;
}

void PauseMenu::update(sf::Event &event,sf::RenderWindow &window,StatusFlags &flags)
{
  if(flags.pause_menu)
  {
    if(event.type == sf::Event::KeyPressed)
    {
      if(event.key.code == sf::Keyboard::Escape)
        {
          flags.gameplay = true;
          flags.pause_menu = false;
        }
    }
    if(btn_quit.detect_click(window))
    {
      handle_quit(window);
    }
    if(btn_continue.detect_click(window))
    {
      handle_continue(flags);
    }
    if(btn_settings.detect_click(window))
    {
      handle_settings(flags);
    }
  }
}

void PauseMenu::draw(sf::RenderWindow &window,StatusFlags &flags)
{
  if(flags.pause_menu)
  {
    window.draw(background);
    btn_quit.draw(window);
    btn_settings.draw(window);
    btn_continue.draw(window);
  }
}


