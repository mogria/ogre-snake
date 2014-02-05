#ifndef CONTROLLER_MAIN_H
#define CONTROLLER_MAIN_H 1

#include <model/Map.h>
#include <model/Snake.h>

#include <memory>
#include <OIS/OIS.h>

namespace Controller {
using namespace Model;

class Main {
  private: 
    bool game_finished;
    std::unique_ptr<Map> map;
    std::unique_ptr<Snake> snake;


    

  public:
    Main();
    void on_start();
    bool is_game_finished();
    void on_end();

    void on_key_input(OIS::Keyboard& keyboard);
    void on_mouse_input(OIS::Mouse& mouse);

    void on_frame();
    void on_move();
};
};

#endif /* CONTROLLER_MAIN_H */