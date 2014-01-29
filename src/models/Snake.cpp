#include "Snake.h"

Snake::Snake(int pos_x, int pos_y)
  : Snake(pos_x, pos_y, Direction::UP) {

}

Snake::Snake(int pos_x, int pos_y, Direction _direction)
  : fields_to_grow(0),
    direction(_direction) {

  parts.push_back(std::unique_ptr<SnakePart>(
    new SnakePart(pos_x, pos_y, true)));
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
  grow_part();
  move_body();
  move_head();
}

void Snake::grow_part() {
  if(fields_to_grow <= 0) return;

  // the position of the current last piece
  // is the position of the new spawned piece
  // if the snake is growing
  // we just set the position to (0, 0) because it's
  // overwritten in move_body() anyway
  parts.push_back(std::unique_ptr<SnakePart>(
    new SnakePart(0, 0)));
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
  for(auto it = parts.rbegin();
      it != end;
      it++) {
    auto part = **it;
    auto next_part = **++it;
    it--;
    part.move_to(next_part);
  }
}

void Snake::move_head() {
  auto head = *parts.front();
  bool move_vertical = direction & 1;
  int move_x = move_vertical ? 0 : direction - 1;
  int move_y = move_vertical ? direction - 2 : 0;
  head.move_by(move_x, move_y);
}

