#include "Conversation.h"

Conversation::Conversation(DialogBox db1)
{
  d_box = db1;
  d_box.font.loadFromFile("./font/PixelifySans-VariableFont_wght.ttf");
  sf::Vector2f text_position = sf::Vector2f(position.x + 10,position.y + 10);

  d_box.text.setFont(d_box.font);
  d_box.text.setCharacterSize(font_size);
  d_box.text.setString(default_text); // Maximum character size: 46
  d_box.text.setPosition(text_position);
  d_box.text.setFillColor(sf::Color::Black);

  d_box.outline.setPosition(position);
  d_box.outline.setOutlineThickness(2);
  d_box.outline.setFillColor(sf::Color::White);
  d_box.outline.setSize(sf::Vector2f(760,100));
  d_box.outline.setOutlineColor(sf::Color::Black);
}

void Conversation::load_player_dialog(Dialog p_dialog)
{
  player_dialog = p_dialog;
}

void Conversation::load_character_dialog(Dialog p_dialog)
{
  character_dialog = p_dialog;
}

void Conversation::draw(sf::RenderWindow &window)
{
  window.draw(d_box.outline);
  window.draw(d_box.text);
}
