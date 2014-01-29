#ifndef MODELS_SNAKE_H
#define MODELS_SNAKE_H 1

#include "SnakePart.h"
#include <list> 
#include <memory>

class Snake {
  private:
    unsigned int fields_to_grow;

#define NUM_DIRECTIONS (4)
    enum Direction {
      LEFT  = 0,
      UP    = 1,
      RIGHT = 2,
      DOWN  = 3
    } direction;

    std::list<std::unique_ptr<SnakePart>> parts;

  public:
    Snake(int pos_x, int pos_y); 
    Snake(int pos_x, int pos_y, Direction direction); 

    void rotate_left();
    void rotate_right();
    void set_direction(Direction);
    Direction get_direction() const;

    void grow(unsigned int num_fields);

    void move();

  private:
    void move_head();
    void move_body();
    void grow_part();
};

#endif /* MODELS_SNAKE_H */
