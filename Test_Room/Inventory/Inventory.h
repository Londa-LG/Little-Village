#pragma once
#include "Items.h"
#include <vector>

struct Inventory_Space{
  int index;
  int count;
  Item item;
  bool taken;
  sf::RectangleShape sprite;
};

class Inventory
{
  public:
    int space_count = 5;
    sf::Vector2f position = {350,525};
    std::vector<Inventory_Space> spaces;

    sf::RectangleShape border;

    Inventory();
    void pop_item();
    void add_item(Item &item);
    void remove_item(Item &item);
    void draw(sf::RenderWindow &window);
};
