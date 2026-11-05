#include "Items.h"
#include "Collision.h"

ItemGenerator::ItemGenerator()
{
  item_count = 0;
}

Item ItemGenerator::generate_wood(Item &wood, AssetManager &am)
{
  wood.name = "Log";
  wood.collected = false;
  wood.type = Item_type::Resource;
  wood.description = "A log, from a tree.";

  wood.sprite.setTexture(am.world_texture);
  wood.sprite.setTextureRect(am.tiles[106]);
  wood.sprite.setColor(sf::Color::White);
  wood.sprite.setPosition(0,0);

  wood.bounds = generate_bounding_box(sf::Vectr2f(0,0),sf::Vector2f(16,16));
  
  return wood;
}

Item ItemGenerator::generate_money(Item &coin, AssetManager &am)
{
  coin.collected = false;
  coin.name = "Gold coin";
  coin.type = Item_type::Money;
  coin.description = "A gold coin used as local currency";

  coin.sprite.setTexture(am.world_texture);
  coin.sprite.setTextureRect(am.tiles[93]);
  coin.sprite.setColor(sf::Color::White);
  coin.sprite.setPosition(0,0);

  coin.bounds = generate_bounding_box(sf::Vectr2f(0,0),sf::Vector2f(16,16));

  return coin;
}

Axe AxeGenerator::generate_default_axe(Axe &axe,std::string p_name,std::string p_description,AssetManager &am)
{
  axe.damage = 2;
  axe.name = "Iron axe";
  axe.collected = false;
  axe.description = "It's an axe, use it to cut some tree's";

  axe.sprite.setTexture(am.world_texture);
  axe.sprite.setTextureRect(am.tiles[127]);
  axe.sprite.setColor(sf::Color::White);
  axe.sprite.setPosition(0,0);

  axe.type = Item_type::Tool;
  axe.bounds = generate_bounding_box(sf::Vectr2f(0,0),sf::Vector2f(16,16));

  return axe;
}

Axe AxeGenerator::generate_default_battle_axe(Axe &axe,std::string p_name,std::string p_description,AssetManager &am)
{
  axe.damage = 5;
  axe.name = "Iron battle axe";
  axe.collected = false;
  axe.description = "An old iron battle axe, a little better than using a normal axe";

  axe.sprite.setTexture(am.world_texture);
  axe.sprite.setTextureRect(am.tiles[118]);
  axe.sprite.setColor(sf::Color::White);
  axe.sprite.setPosition(0,0);

  axe.type = Item_type::Tool;
  axe.sprite = am.characters[118];
  axe.bounds = generate_bounding_box(sf::Vectr2f(0,0),sf::Vector2f(16,16));

  return axe;
}

Tree TreeGenerator::generate_default_tree(Tree &tree)
{
  tree.yield = 2;
  tree.health = 100;
  tree.max_health = 100;

  return tree;
}
