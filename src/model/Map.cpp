#include "Map.h"

#include <cstdlib>

namespace Model {

map_coords coords(map_coord x, map_coord y) {
  return std::make_pair(x, y);
}

Map::Map(map_coords size)
  : size_x(size.first),
    size_y(size.second) {
  blocks.resize(size_y);
  for(unsigned int y = 0; y < size_y; y++) {
    blocks[y].resize(size_x);
    for(unsigned int x = 0; x < size_x; x++) {
      this->clear_block(coords(x, y));
    }
  }
}

void Map::clear_block(map_coords coord) {
  this->set_block<EmptyBlock>(coord);
}

void Map::move_block(map_coords coord_from, map_coords coord_to) {
  wrap_coords(coord_from);
  wrap_coords(coord_to);
  blocks[coord_to.second][coord_to.first] = std::unique_ptr<Block>(
    blocks[coord_from.second][coord_from.first].get());
  this->clear_block(coord_from);
}

void Map::move_block_by(map_coords coord,
                        int by_x, int by_y) {
  move_block(coord, coords(coord.first + by_x,
                           coord.second + by_y));
}

void Map::wrap_coords(map_coords& coord) {
  coord = coords(abs(coord.first) % size_x,
                 abs(coord.second) % size_y);
}

}; /* namespace Model */
