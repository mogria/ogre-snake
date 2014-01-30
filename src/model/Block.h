#ifndef MODEL_BLOCK_H
#define MODEL_BLOCK_H 1

namespace Model {
class Block {
  public:
    virtual void snake_enters() = 0;
};

class EmptyBlock : public Block {
  public:
    virtual void snake_enters();
};

class CollisionBlock : public Block {
  public:
    virtual void snake_enters();
};

class SnakePart : public CollisionBlock {
};

class SnakeHead : public SnakePart {
};

  namespace Blocks {
    extern const ::Model::EmptyBlock Empty;
    extern const ::Model::CollisionBlock Collision;
    extern const ::Model::SnakePart SnakePart;
    extern const ::Model::SnakeHead SnakeHead;
  };

};

#endif /* MODEL_BLOCK_H */
