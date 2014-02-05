#ifndef VIEW_MAIN_H
#define VIEW_MAIN_H 1

#include "Main.h"
#include <model/Map.h>
#include <model/Snake.h>

#include <OGRE/Ogre.h>
#include <OGRE/OgreRoot.h>
#include <OGRE/OgreException.h>

namespace View {
using namespace Model;

class Main {
  private: 
    Ogre::RenderWindow& window;
    Ogre::SceneManager& scene;
    Ogre::Camera& camera;
    Ogre::SceneNode& cameraNode;
    Ogre::Viewport& viewport;


  public:
    Main(Ogre::RenderWindow& window,
         Ogre::SceneManager& scene,
         Ogre::Camera& camera,
         Ogre::SceneNode& cameraNode,
         Ogre::Viewport& viewport);

    void render(Map& map, Snake& snake);
};
};

#endif /* VIEW_MAIN_H */
