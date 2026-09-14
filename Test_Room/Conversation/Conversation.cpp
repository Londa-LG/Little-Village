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

void Conversation::turn_page()
{
  ++page_index;
  if(page_index < character_dialog.size())
  {
    d_box.text.setString(character_dialog[page_index]);
  }
  else{
    page_index = 0;
    // Close the conversation box.
  }
   
}

void Conversation::draw(sf::RenderWindow &window)
{
  window.draw(d_box.outline);
  window.draw(d_box.text);
}

std::string Conversation::sub_str(std::string text,int start, int end)
{
  std::string buffer;

  for(int i=start;i<end;i++)
  {
    buffer += text[i];
  }

  return buffer;
}

void Conversation::remove_space(std::vector<std::string> &list)
{
  for(int i=0;i<list.size();i++)
  {
    if(list[i][0] == ' ')
    {
      list[i] = sub_str(list[i],1,list[i].size());
    }
  }
}

void Conversation::load_character_dialog(Dialog p_dialog)
{
  int added = 0;
  std::string buffer;
  int space_index, start;

  if(p_dialog.dialog.size() > max_char)
  {
    while(added < p_dialog.dialog.size())
    {
      for(int i=0; i<46;i++)
      {
        if(p_dialog.dialog[added] == ' ')
        {
          space_index = added;
        }

        if((i == 45) && (p_dialog.dialog[added] != ' '))
        {
          buffer = sub_str(p_dialog.dialog,start,space_index);
          added = added - (added - space_index);
          break;
        }
        buffer += p_dialog.dialog[added];
        added++;
      }
      character_dialog.push_back(buffer);
      buffer = "";
      start = added;
    }
    remove_space(character_dialog);
  }
  else
  {
    character_dialog.push_back(p_dialog.dialog);
  }
  d_box.text.setString(character_dialog[page_index]);
}
