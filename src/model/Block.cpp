#include "Block.h"

namespace Model {
void EmptyBlock::snake_enters() {

}

void CollisionBlock::snake_enters() {
  // end game
}

  namespace Blocks {
    const ::Model::EmptyBlock Empty;
    const ::Model::CollisionBlock Collision;
    const ::Model::SnakePart SnakePart;
    const ::Model::SnakeHead SnakeHead;
  };

}; /* namespace Model */
