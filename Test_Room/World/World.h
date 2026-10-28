#pragma once
#include <vector>
#include <memory>
#include "AssetManager.h"
#include <SFML/Graphics.hpp>

struct Mapping{
  int id;
  int row;
  int column;
};

class Layer{
  public:
    int tile_size = 16;
    int total_rows = 11;
    int total_columns = 12;
    int total_tiles = 132;
    std::vector<Mapping> layer_tiles;

    Layer(std::string filename);
    void detect_transform(int raw);
    int remove_rotation(int raw);
    void draw(sf::Texture &texture,std::vector<sf::IntRect> &tiles,sf::RenderWindow &window);
};
