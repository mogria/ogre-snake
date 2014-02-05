#include "Main.h"

namespace Controller {

Main::Main()
  : game_finished(false),
    map(new Map(coords(24, 30))),
    snake(new Snake(*map.get(), coords(12, 15))) {

}

void Main::on_start() {

}

bool Main::is_game_finished() {
  return game_finished;
}

void Main::on_end() {

};

void Main::on_key_input(OIS::Keyboard& keyboard) {
  keyboard.capture();
  if(keyboard.isKeyDown(OIS::KC_ESCAPE)) {
    game_finished = true;
  }
}

void Main::on_mouse_input(OIS::Mouse& mouse) {
  mouse.capture();
}

void Main::on_frame() {
  if(1) {
    on_move();
  }
}

void Main::on_move() {
  
}


}; /* namespace Controller */