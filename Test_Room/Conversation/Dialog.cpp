#include "Dialog.h"
#include <iostream>

DialogBox::DialogBox()
{
  font.loadFromFile("./font/PixelifySans-VariableFont_wght.ttf");
  text.setFont(font);
  text.setCharacterSize(font_size);
  text.setString(default_text);
  text.setPosition(text_position);
  text.setFillColor(sf::Color::Black);

  outline.setPosition(position);
  outline.setOutlineThickness(2);
  outline.setFillColor(sf::Color::White);
  outline.setSize(sf::Vector2f(760,100));
  outline.setOutlineColor(sf::Color::Blue);
}

void DialogBox::turn_page()
{
  page_index++;
  if(page_index < dialog.size())
  {
    turned_page = true;
  }
  else if(page_index >= dialog.size())
  {
    show = false;
    page_index = 0;
    text.setString(dialog[page_index]);
  }

}

void DialogBox::load_dialog(std::string p_dialog)
{
  int size = dialog.size();
  dialog.push_back(p_dialog);
  if(size == 0)
  {
    text.setString(dialog[page_index]);
  }
}

void DialogBox::update()
{
  if(turned_page)
  {
    text.setString(dialog[page_index]);
    turned_page = false;
  }
}

void DialogBox::draw(sf::RenderWindow &window)
{
  if(show)
  {
    window.draw(outline);
    window.draw(text);
  }
}
