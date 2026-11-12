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

struct Axe
{
  int damage;
  int durability;
  int max_durability;

  bool collected;
  Item_type type;
  std::string name;
  std::string description;

  sf::Sprite sprite;
  BoundingBox bounds;
};

struct Tree
{
  int health;
  int max_health;
  BoundingBox bounds;
};

class ItemGenerator
{
  public:
    int item_count;

    ItemGenerator();
    Item generate_wood(Item &wood,AssetManager &am,sf::Vector2f poistion);
    Item generate_money(Item &coin,AssetManager &am,sf::Vector2f poistion);
};

class AxeGenerator
{
  public:
    AxeGenerator();
    Axe generate_default_axe(Axe &axe,AssetManager &am,sf::Vector2f position);
    Axe generate_default_battle_axe(Axe &axe,AssetManager &am,sf::Vector2f position);
};

class TreeGenerator
{
  public:
    TreeGenerator();
    Tree generate_default_tree(Tree &tree);
    Tree generate_tree(Tree &tree,sf::Vector2f position,sf::Vector2f size);
};
