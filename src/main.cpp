#include <OGRE/Ogre.h>
#include <OGRE/OgreRoot.h>
#include <OGRE/OgreException.h>

#include <OIS/OIS.h>

#include <memory>

#include <controller/Main.h>

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif


//|||||||||||||||||||||||||||||||||||||||||||||||

int run()
{
	
  Ogre::Root root("plugins.cfg");
  if(!root.showConfigDialog()) return EXIT_FAILURE;

  std::unique_ptr<Ogre::RenderWindow>
  window(root.initialise(true));

  Ogre::SceneManager* sceneManager =
  root.createSceneManager(Ogre::ST_GENERIC);

  // attach camera to scene
  Ogre::Camera* camera = sceneManager->createCamera("MainCamera");
  camera->setNearClipDistance(5);
  camera->setNearClipDistance(1000);
  Ogre::SceneNode* cameraNode =
  sceneManager->getRootSceneNode()->createChildSceneNode();
  cameraNode->attachObject(camera);

  // render camera to window;
  Ogre::Viewport* viewport = window->addViewport(camera);
  viewport->setClearEveryFrame(true);

  // capture input
  size_t windowHnd;
  window->getCustomAttribute("WINDOW", &windowHnd);
  std::ostringstream windowHndStream;
  windowHndStream << windowHnd;
  std::string windowHndStr = windowHndStream.str();

  OIS::ParamList specialParameters;
  //#ifdef OIS_LINUX_PLATFORM
    specialParameters.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
    specialParameters.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("false")));
    specialParameters.insert(std::make_pair(std::string("x11_keyboard_grab"), std::string("false")));
    specialParameters.insert(std::make_pair(std::string("XAutoRepeatOn"), std::string("true")));
  //#endif
  specialParameters.insert(std::make_pair(std::string("WINDOW"), windowHndStr));

  OIS::InputManager* inputManager = OIS::InputManager::createInputSystem(specialParameters);

  OIS::Keyboard* keyboard = static_cast<OIS::Keyboard*>(inputManager->createInputObject(OIS::OISKeyboard, false));
  OIS::Mouse* mouse = static_cast<OIS::Mouse*>(inputManager->createInputObject(OIS::OISMouse, false));

  View::Main view(*window.get(), *sceneManager, *camera, *cameraNode, *viewport);

  Controller::Main controller(view);

  controller.on_start();
  while(!window->isClosed() && !controller.is_game_finished()) {
	  controller.on_key_input(*keyboard);
	  controller.on_mouse_input(*mouse);
	  controller.on_frame();
	  root.renderOneFrame();
  }
  controller.on_end();


  delete mouse;
  delete keyboard;
  delete cameraNode;
  delete camera;
  delete sceneManager;

  return 0;
}
 
#ifdef __cplusplus
extern "C" {
#endif
 
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
  INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
  int main(int argc, char *argv[])
#endif
{
 
  try 
  {
    //run();
  } catch( Ogre::Exception& e ) {
  #if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    //MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR| MB_TASKMODAL); 
  #else
    std::cerr << "An exception has occured: " << e.getFullDescription().c_str() << std::endl;
  #endif
  }
 
return 0;
}
 
#ifdef __cplusplus
}
#endif
