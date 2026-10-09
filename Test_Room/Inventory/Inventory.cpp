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
    item_boxs.push_back(item_box);
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
  for(int i =0; i<item_boxs.size();i++)
  {
    window.draw(item_boxs[i]);
  }
  if(items.size() > 0)
  {
    for(int i=0; i<items.size();i++)
    {
      window.draw(items[i].sprite);
    }
  }
}

void Inventory::add_item(Item &item)
{
  if(items.size() < space_count)
  {
    int index = (space_count - (space_count - items.size()));
    item.sprite.setPosition(item_boxs[index].getPosition());
    items.push_back(item);
  }
}
