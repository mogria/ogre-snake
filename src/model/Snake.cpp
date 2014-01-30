#include "Snake.h"

namespace Model {

Snake::Snake(Map& _map, map_coords position, Direction _direction)
  : map(_map),
    fields_to_grow(0),
    direction(_direction) {

  parts.push_back(position);
  map.set_block<SnakeHead>(position);
}

void Snake::rotate_left() {
  direction = static_cast<Direction>(
    (direction - 1 + NUM_DIRECTIONS) % NUM_DIRECTIONS);
}

void Snake::rotate_right() {
  direction = static_cast<Direction>(
    (direction + 1) % NUM_DIRECTIONS);
}

void Snake::set_direction(Direction new_direction) {
  auto opposite_direction = static_cast<Direction>(
      (direction + 2) % NUM_DIRECTIONS);
  if(new_direction == opposite_direction) return;

  direction = new_direction;
}

Snake::Direction Snake::get_direction() const {
  return direction;
}

void Snake::grow(unsigned int num_fields) {
  fields_to_grow += num_fields;
}

void Snake::move() {
  // the position of the last piece before moving
  // is the position of the new spawned piece
  // if the snake is growing
  map_coords grow_position = parts.back();

  move_body();
  move_head();
  grow_part(grow_position);
}

void Snake::grow_part(map_coords grow_position) {
  if(fields_to_grow <= 0) return;

  parts.push_back(grow_position);
  map.set_block<SnakePart>(grow_position);
  fields_to_grow--;
}

void Snake::move_body() {
  if(parts.size() <= 1) return;

  // don't move the head in this loop
  // because the head doesn't have an
  // other SnakePart before itself
  // the head is moved in move_head()
  auto end = parts.rend();
  end--;
  for(auto it = parts.rbegin(); it != end; it++) {
    auto part = *it;
    auto next_part = *++it;
    it--;
    map.move_block(part, next_part);
  }
}

void Snake::move_head() {
  auto head = parts.front();
  bool move_vertical = direction & 1;
  int move_x = move_vertical ? 0 : direction - 1;
  int move_y = move_vertical ? direction - 2 : 0;
  map.move_block_by(head, move_x, move_y);
}

}; /* namespace Model */
