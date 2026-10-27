#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

struct StatusFlags
{
  bool gameplay;
  bool start_menu;
  bool pause_menu;
  bool settings_menu;
};

class AssetManager
{ 
  public:
    int tileWidth = 16;
    int tileHeight = 16;
    int totalTilesV = 11;
    int totalTilesH = 12;

    sf::Font font;
    sf::Texture world_texture;
    sf::Texture character_texture;
    std::vector<sf::IntRect> tiles;
    std::vector<sf::IntRect> characters;

    AssetManager();

    void load_tiles(std::string texture_name);
    void load_characters(std::string texture_name);
};
