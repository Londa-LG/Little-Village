#include "Inventory.h"

Inventory::Inventory()
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
    item_box.setOutlineColor(sf::Color::White);
    item_box.setFillColor(sf::Color::Yellow);
    item_box.setPosition(item_pos);

    Inventory_Space space;
    space.index = i;
    space.count = 0;
    space.taken = false;
    space.sprite = item_box;

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

/*
void Inventory::remove_item(Item &item)
{
  std::vector<Item>::iterator itr;
  itr = find(items.begin(),items.end(),item);
  if(itr != items.end())
  {
    items.erase(itr);
  }
}
*/
