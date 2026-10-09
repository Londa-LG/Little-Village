#pragma once
#include "AssetManager.h"

enum Item_type { Resource,Money,Tool };

struct Item
{
  int u_id;
  bool collected;
  Item_type type;
  std::string name;
  std::string description;

  sf::Sprite sprite;
  sf::RectangleShape bounds;
};

class ItemGenerator
{
  public:
    int item_count;

    ItemGenerator();
    Item generate_wood(Item &wood,AssetManager &am);
    Item generate_money(Item &coin,AssetManager &am);
    Item generate_axe(Item &axe,std::string p_name,std::string description,AssetManager &am);
    Item generate_battle_axe(Item &axe,std::string p_name,std::string description,AssetManager &am);
};

