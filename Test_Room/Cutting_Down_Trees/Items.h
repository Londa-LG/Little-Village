#pragma once
#include "Collisions.h"
#include "AssetManager.h"

enum Item_type { Resource,Money,Tool };

struct Item
{
  bool collected;
  Item_type type;
  std::string name;
  std::string description;

  sf::Sprite sprite;
  BoundingBox bounds;
};

struct Tree
{
  int yield;
  int health;
  int max_health;
};

struct Axe
{
  int damage;
  bool collected;
  Item_type type;
  std::string name;
  std::string description;

  sf::Sprite sprite;
  BoundingBox bounds;
};

class ItemGenerator
{
  public:
    int item_count;

    ItemGenerator();
    Item generate_wood(Item &wood,AssetManager &am);
    Item generate_money(Item &coin,AssetManager &am);
};

class AxeGenerator
{
  public:
    Axe generate_default_axe(Axe &axe,std::string p_name,std::string description,AssetManager &am);
    Axe generate_default_battle_axe(Axe &axe,std::string p_name,std::string description,AssetManager &am);
};

class TreeGenerator
{
  public:
    Tree generate_default_tree(Tree &tree);
};
