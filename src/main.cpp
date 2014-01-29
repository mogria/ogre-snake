#include <OGRE/Ogre.h>
#include <OGRE/OgreRoot.h>
#include <OGRE/OgreException.h>

#include <OIS/OIS.h>

#include <boost/scoped_ptr.hpp>

void handleKeyboard(OIS::Keyboard& keyboard, bool& running) {
  keyboard.capture();
  if(keyboard.isKeyDown(OIS::KC_ESCAPE)) running = false;
}

void handleMouse() {

}

int main() {

  Ogre::Root root("plugins.cfg");
  if(!root.showConfigDialog()) return EXIT_FAILURE;

  boost::scoped_ptr<Ogre::RenderWindow>
    window(root.initialise(true));

  boost::scoped_ptr<Ogre::SceneManager>
    sceneManager(root.createSceneManager(Ogre::ST_GENERIC));

  // attach camera to scene
  boost::scoped_ptr<Ogre::Camera>
    camera(sceneManager->createCamera("MainCamera"));
  camera->setNearClipDistance(5);
  camera->setNearClipDistance(1000);
  boost::scoped_ptr<Ogre::SceneNode>
    cameraNode(sceneManager->getRootSceneNode()->createChildSceneNode());
  cameraNode->attachObject(camera.get());

  // render camera to window;
  boost::scoped_ptr<Ogre::Viewport>
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

  // main loop
  bool running = true;
  while(!window->isClosed() && running) {
    handleKeyboard(*keyboard, running);
    handleMouse();
    root.renderOneFrame();
  }

  return 0;
}
