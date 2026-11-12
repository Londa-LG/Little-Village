#include "Items.h"
#include "Collisions.h"

ItemGenerator::ItemGenerator()
{
  item_count = 0;
}

Item ItemGenerator::generate_wood(Item &wood, AssetManager &am,sf::Vector2f position)
{
  wood.name = "Log";
  wood.collected = false;
  wood.type = Item_type::Resource;
  wood.description = "A log, from a tree.";

  //wood.sprite = am.tiles[106];
  wood.sprite.setTexture(am.world_texture);
  wood.sprite.setTextureRect(am.tiles[106]);
  wood.sprite.setPosition(position);
  wood.bounds = generate_bounding_box(sf::Vector2f(0,0),sf::Vector2f(16,16));

  wood.bounds.sprite.setOutlineThickness(2);
  wood.bounds.sprite.setOutlineColor(sf::Color::Blue);
  wood.bounds.sprite.setFillColor(sf::Color::Transparent);
  
  return wood;
}

Item ItemGenerator::generate_money(Item &coin, AssetManager &am,sf::Vector2f position)
{
  coin.collected = false;
  coin.name = "Gold coin";
  coin.type = Item_type::Money;
  coin.description = "A gold coin used as local currency";

  coin.sprite.setTexture(am.world_texture); 
  coin.sprite.setTextureRect(am.tiles[93]);
  coin.sprite.setPosition(position);
  coin.bounds = generate_bounding_box(sf::Vector2f(0,0),sf::Vector2f(16,16));


  coin.bounds.sprite.setOutlineThickness(2);
  coin.bounds.sprite.setOutlineColor(sf::Color::Blue);
  coin.bounds.sprite.setFillColor(sf::Color::Transparent);

  return coin;
}


Axe AxeGenerator::generate_default_axe(Axe &axe,AssetManager &am,sf::Vector2f position)
{
  axe.damage = 5;
  axe.durability = 60;
  axe.name = "A iron axe";
  axe.collected = false;
  axe.description = "It's an iron axe use it to cut wood";

  axe.type = Item_type::Tool;
  axe.sprite.setTexture(am.world_texture); 
  axe.sprite.setTextureRect(am.tiles[127]);
  axe.sprite.setPosition(position);
  axe.bounds = generate_bounding_box(sf::Vector2f(0,0),sf::Vector2f(16,16));

  axe.bounds.sprite.setOutlineThickness(2);
  axe.bounds.sprite.setOutlineColor(sf::Color::Blue);
  axe.bounds.sprite.setFillColor(sf::Color::Transparent);

  return axe;
}

Axe AxeGenerator::generate_default_battle_axe(Axe &axe,AssetManager &am,sf::Vector2f position)
{
  axe.damage = 10;
  axe.durability = 60;
  axe.name = "A battle axe";
  axe.collected = false;
  axe.description = "It's a battle axe intended for combat but just as good for tree cutting";

  axe.type = Item_type::Tool;
  axe.sprite.setTexture(am.world_texture); 
  axe.sprite.setTextureRect(am.tiles[118]);
  axe.sprite.setPosition(position);
  axe.bounds = generate_bounding_box(sf::Vector2f(0,0),sf::Vector2f(16,16));

  axe.bounds.sprite.setOutlineThickness(2);
  axe.bounds.sprite.setOutlineColor(sf::Color::Blue);
  axe.bounds.sprite.setFillColor(sf::Color::Transparent);

  return axe;
}

TreeGenerator::TreeGenerator()
{
}

Tree TreeGenerator::generate_default_tree(Tree &tree)
{
  tree.health = 100;
  tree.max_health = 100;
  tree.bounds = generate_bounding_box(sf::Vector2f(0,0),sf::Vector2f(16,16));

  return tree;
}

Tree TreeGenerator::generate_tree(Tree &tree,sf::Vector2f position,sf::Vector2f size)
{
  tree.health = 100;
  tree.max_health = 100;
  tree.bounds = generate_bounding_box(position,size);

  return tree;
}
