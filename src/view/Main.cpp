#include "Main.h"
#include <model/Map.h>
#include <model/Snake.h>

#include <fstream>


namespace View {

Main::Main( Ogre::RenderWindow& _window,
            Ogre::SceneManager& _scene,
            Ogre::Camera& _camera,
            Ogre::SceneNode& _cameraNode,
            Ogre::Viewport& _viewport)
  : window(_window),
    scene(_scene),
    camera(_camera),
    cameraNode(_cameraNode),
    viewport(_viewport) {

    Ogre::Entity* mesh = scene.createEntity("yoloblock", "cube.mesh");
    Ogre::SceneNode* node = scene.getRootSceneNode()->createChildSceneNode();
    node->setPosition(0, 0.5, 0);
    node->attachObject(mesh);
};


void Main::render(Map& map, Snake& snake)  {
}


}; /* namespace View */
