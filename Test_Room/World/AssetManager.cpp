#include <SFML/Graphics.hpp>
#include "AssetManager.h"

AssetManager::AssetManager()
{
  load_tiles("./world.png");
  load_characters("./character.png");
}

void AssetManager::load_characters(std::string texture_name)
{
  character_texture.loadFromFile(texture_name);
  
  for(int y=0; y<(totalTilesV * tileHeight); y += tileHeight)
  {
    for(int x=0; x<(totalTilesH * tileWidth);x += tileWidth)
    {
      sf::IntRect sp = sf::IntRect(x,y,tileWidth,tileHeight);
      characters.push_back(sp);
    }
  }
}

void AssetManager::load_tiles(std::string texture_name)
{
  world_texture.loadFromFile(texture_name);
  
  for(int y=0; y<(totalTilesV * tileHeight); y += tileHeight)
  {
    for(int x=0; x<(totalTilesH * tileWidth);x += tileWidth)
    {
      sf::IntRect sp = sf::IntRect(x,y,tileWidth,tileHeight);
      tiles.push_back(sp);
    }
  }
}


