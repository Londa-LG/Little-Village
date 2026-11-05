#include "Items.h"

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

  wood.sprite = am.tiles[106];
  wood.bounds = sf::RectangleShape(sf::Vector2f(16,16));

  wood.bounds.setOutlineThickness(2);
  wood.bounds.setOutlineColor(sf::Color::Blue);
  wood.bounds.setFillColor(sf::Color::Transparent);
  
  return wood;
}

Item ItemGenerator::generate_money(Item &coin, AssetManager &am)
{
  coin.collected = false;
  coin.name = "Gold coin";
  coin.type = Item_type::Money;
  coin.description = "A gold coin used as local currency";

  coin.sprite = am.tiles[93];
  coin.bounds = sf::RectangleShape(sf::Vector2f(16,16));

  coin.bounds.setOutlineThickness(2);
  coin.bounds.setOutlineColor(sf::Color::Blue);
  coin.bounds.setFillColor(sf::Color::Transparent);

  return coin;
}

Item ItemGenerator::generate_axe(Item &axe,std::string p_name,std::string p_description,AssetManager &am)
{
  axe.name = p_name;
  axe.collected = false;
  axe.description = p_description;

  axe.type = Item_type::Tool;
  axe.sprite = am.tiles[127];
  axe.bounds = sf::RectangleShape(sf::Vector2f(16,16));

  axe.bounds.setOutlineThickness(2);
  axe.bounds.setOutlineColor(sf::Color::Blue);
  axe.bounds.setFillColor(sf::Color::Transparent);

  return axe;
}

Item ItemGenerator::generate_battle_axe(Item &axe,std::string p_name,std::string p_description,AssetManager &am)
{
  axe.name = p_name;
  axe.collected = false;
  axe.description = p_description;

  axe.type = Item_type::Tool;
  axe.sprite = am.characters[118];
  axe.bounds = sf::RectangleShape(sf::Vector2f(16,16));

  axe.bounds.setOutlineThickness(2);
  axe.bounds.setOutlineColor(sf::Color::Blue);
  axe.bounds.setFillColor(sf::Color::Transparent);

  return axe;
}

