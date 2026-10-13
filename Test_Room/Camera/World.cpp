#include <vector>
#include <memory>
#include <fstream>
#include "World.h"
#include "AssetManager.h"
#include <SFML/Graphics.hpp>

Layer::Layer(std::string filename)
{
  std::ifstream file(filename);
  std::string row,numb;
  int row_index = 0;
  int column_index = 0;

  while(file >> row)
  {
    int start = 0;
    for(int i=0; i<row.length(); i++)
    {
      if(row.at(i) == ',')
      {
        for(int j=start; j<i; j++)
        {
          numb += row.at(j);
        }

        Mapping m1;
        m1.column = column_index * tile_size;
        m1.row = row_index * tile_size;
        m1.id = std::stoi(numb);
        layer_tiles.push_back(m1);

        numb.clear();
        start = i + 1;
        column_index++;
      }
    }
    row_index++;
    column_index = 0;
  }

  file.close();
}

void Layer::detect_transform(int raw)
{
  /* For handling Tiled id system.
     Id's have rotaion incoded in them. */
  uint32_t rawGid = raw;

  bool flipH = (rawGid & 0x80000000) != 0;
  bool flipV = (rawGid & 0x40000000) != 0;
  bool flipD = (rawGid & 0x20000000) != 0;

  uint32_t tileGid = rawGid & 0x1FFFFFF;
}

int Layer::remove_rotation(int raw)
{
  // Getting raw tile id
  uint32_t tileGid = raw & 0x1FFFFFFF;
  return tileGid;
}

void Layer::draw(std::vector<sf::Sprite> &tiles, sf::RenderWindow &window)
{
  int index;
  for(int i=0; i<layer_tiles.size(); i++)
  {
    Mapping m = layer_tiles[i];
    if((m.id >= 0) && (m.id < total_tiles))
    {
      sf::Sprite tile = tiles[m.id];
      tile.setPosition(m.column,m.row);
      window.draw(tile);
    }
    else if(m.id >= 0){
      int id = remove_rotation(m.id);
      sf::Sprite tile = tiles[id];
      tile.setPosition(m.column,m.row);
      window.draw(tile);
    }
  }
}
