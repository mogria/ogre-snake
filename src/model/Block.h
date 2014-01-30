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

};

#endif /* MODEL_BLOCK_H */
