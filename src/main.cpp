#include <OGRE/Ogre.h>
#include <OGRE/OgreRoot.h>
#include <OGRE/OgreException.h>

#include <OIS/OIS.h>

#include <memory>

#include <controller/Main.h>


int main() {

  Ogre::Root root("plugins.cfg");
  if(!root.showConfigDialog()) return EXIT_FAILURE;

  std::unique_ptr<Ogre::RenderWindow>
    window(root.initialise(true));

  std::unique_ptr<Ogre::SceneManager>
    sceneManager(root.createSceneManager(Ogre::ST_GENERIC));

  // attach camera to scene
  std::unique_ptr<Ogre::Camera>
    camera(sceneManager->createCamera("MainCamera"));
  camera->setNearClipDistance(5);
  camera->setNearClipDistance(1000);
  std::unique_ptr<Ogre::SceneNode>
    cameraNode(sceneManager->getRootSceneNode()->createChildSceneNode());
  cameraNode->attachObject(camera.get());

  // render camera to window;
  std::unique_ptr<Ogre::Viewport>
    viewport(window->addViewport(camera.get()));
  viewport->setClearEveryFrame(true);

  // capture input
  size_t windowHnd;
  window->getCustomAttribute("WINDOW", &windowHnd);
  std::ostringstream windowHndStream;
  windowHndStream << windowHnd;
  std::string windowHndStr = windowHndStream.str();

  OIS::ParamList specialParameters;
  specialParameters.insert(std::make_pair(std::string("WINDOW"), windowHndStr));

  OIS::InputManager* inputManager = OIS::InputManager::createInputSystem(specialParameters);

  OIS::Keyboard* keyboard = static_cast<OIS::Keyboard*>(inputManager->createInputObject(OIS::OISKeyboard, false));
  OIS::Mouse* mouse = static_cast<OIS::Mouse*>(inputManager->createInputObject(OIS::OISMouse, false));

  Controller::Main controller;

  controller.on_start();
  while(!window->isClosed() && controller.is_game_finished()) {
    controller.on_key_input(*keyboard);
    controller.on_mouse_input(*mouse);
    controller.on_frame();
    root.renderOneFrame();
  }
  controller.on_end();

  return 0;
}
