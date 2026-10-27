#include "Helpers.h"
#include <SFML/Graphics.hpp>


AssetManager::AssetManager()
{
  load_tiles("./assets/textures/world.png");
  load_characters("./assets/textures/character.png");
  font.loadFromFile("./assets/font/pixelfy_sans.ttf");
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

