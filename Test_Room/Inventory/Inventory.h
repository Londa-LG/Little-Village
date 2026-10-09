#pragma once
#include "Items.h"
#include <vector>

class Inventory
{
  public:
    int space_count = 5;
    std::vector<Item> items;
    sf::Vector2f position = {350,525};
    std::vector<sf::RectangleShape> item_boxs;

    sf::RectangleShape border;

    Inventory();
    void add_item(Item &item);
    void draw(sf::RenderWindow &window);
};
