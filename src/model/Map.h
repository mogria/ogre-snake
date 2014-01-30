#ifndef MODEL_MAP_H
#define MODEL_MAP_H

#include "Block.h"
#include <vector>
#include <utility>


namespace Model {

typedef unsigned int map_coord;
typedef std::pair<map_coord, map_coord> map_coords;

map_coords coords(map_coord x, map_coord y);

class Map {
  private:
    std::vector<std::vector<const Block*>> blocks;
    map_coord size_x;
    map_coord size_y;
  public:
    Map(map_coords size);

    void clear_block(map_coords coord);
    void set_block(map_coords coord, const Block& new_block);
    void move_block(map_coords coord_from, map_coords coord_to);

    void move_block_by(map_coords coord,
                       int by_x, int by_y);

    const std::vector<std::vector<const Block *>> to_array() const;
  private:
    void wrap_coords(map_coords& coord);
};
};

#endif /* MODEL_MAP_H */
