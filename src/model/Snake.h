#ifndef MODEL_SNAKE_H
#define MODEL_SNAKE_H 1

#include "Block.h"
#include "Map.h"
#include <list> 
#include <memory>

namespace Model {
class Snake {
  private:
    Map& map;
    unsigned int fields_to_grow;

#define NUM_DIRECTIONS (4)
    enum Direction {
      LEFT  = 0,
      UP    = 1,
      RIGHT = 2,
      DOWN  = 3
    } direction;

    std::list<map_coords> parts;

  public:
    Snake(Map& map, map_coords position, Direction direction = Direction::UP); 

    void rotate_left();
    void rotate_right();
    void set_direction(Direction);
    Direction get_direction() const;

    void grow(unsigned int num_fields);

    void move();

  private:
    void move_head();
    void move_body();
    void grow_part(map_coords grow_position);
};
};

#endif /* MODEL_SNAKE_H */
