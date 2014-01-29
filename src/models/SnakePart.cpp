#include "SnakePart.h"

SnakePart::SnakePart(int _pos_x, int _pos_y, bool _head)
  : pos_x(_pos_x),
    pos_y(_pos_y),
    head(_head) {
}

SnakePart::SnakePart(SnakePart& copy) {
  this->move_to(copy);
  head = copy.head;
}

void SnakePart::move_by(int by_x, int by_y) {
  pos_x += by_x;
  pos_y += by_y;
}


void SnakePart::move_to(int _pos_x, int _pos_y) {
  pos_x = _pos_x;
  pos_y += _pos_y;
}

void SnakePart::move_to(SnakePart& to) {
  pos_x = to.pos_x;
  pos_y = to.pos_y;
}
