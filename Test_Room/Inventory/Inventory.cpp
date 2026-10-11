#include "Inventory.h"
#include "AssetManager.h"

Inventory::Inventory(AssetManager &am)
{
  int width = 16;
  int height = 16;
  int outline = 2;
  int margin = 2;

  for(int i=0; i<space_count; i++)
  {
    sf::Vector2f item_pos = sf::Vector2f(position.x + ((outline + width + outline)*i) + margin,position.y + margin);

    sf::RectangleShape item_box = sf::RectangleShape(sf::Vector2f(width,height));
    item_box.setOutlineThickness(1);
    item_box.setOutlineColor(sf::Color::Black);
    item_box.setFillColor(sf::Color::Black);
    item_box.setPosition(item_pos);

    Inventory_Space space;
    space.index = i;
    space.count = 0;
    space.taken = false;
    space.sprite = item_box;
    space.count_display.setFont(am.font);
    space.count_display.setCharacterSize(8);
    space.count_display.setPosition(item_pos);
    space.count_display.setStyle(sf::Text::Bold);
    space.count_display.setFillColor(sf::Color::White);
    space.count_display.setString(std::to_string(space.count));

    spaces.push_back(space);
  }

  border = sf::RectangleShape(sf::Vector2f(((outline + width + outline)*space_count), 20));
  border.setOutlineThickness(2);
  border.setOutlineColor(sf::Color::Blue);
  border.setFillColor(sf::Color::Blue);
  border.setPosition(position);
}

void Inventory::draw(sf::RenderWindow &window)
{
  window.draw(border);
  for(int i =0; i<spaces.size();i++)
  {
    window.draw(spaces.at(i).sprite);
    if(spaces.at(i).taken)
    {
      window.draw(spaces.at(i).item.sprite);
      if(spaces.at(i).count > 1)
      {
        window.draw(spaces.at(i).count_display);
      }
    }
  }
}

void Inventory::add_item(Item &item)
{
  for(int i=0; i<spaces.size(); i++)
  {
    if(!spaces.at(i).taken)
    {
      item.sprite.setPosition(spaces.at(i).sprite.getPosition());
      spaces.at(i).item = item;
      spaces.at(i).taken = true;
      spaces.at(i).count++;
      break;
    }
    else if((spaces.at(i).item.type != Item_type::Tool) && (spaces.at(i).item.type == item.type))
    {
      spaces.at(i).count++;
      spaces.at(i).count_display.setString(std::to_string(spaces.at(i).count));
      break;
    }
  }
}

void Inventory::pop_item()
{
  for(int i=(spaces.size() - 1); i>=0; i--)
  {
    if(spaces.at(i).taken)
    {
      spaces.at(i).taken = false;
      break;
    }
  }
}

void Inventory::remove_item(int space)
{
  spaces.at(space).taken = false;
}
