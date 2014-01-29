#ifndef MODELS_SNAKE_PART_H
#define MODELS_SNAKE_PART_H 1

class SnakePart {
  private:
    int pos_x;
    int pos_y;

    bool head;

  public:
    SnakePart(int pos_x, int pos_y, bool head = false);
    SnakePart(SnakePart& to);

    void move_by(int by_x, int by_y);
    void move_to(int pos_x, int pos_y);
    void move_to(SnakePart& to);
};

#endif /* MODELS_SNAKE_PART_H */
