#include "SnakeApplication.h"
#include <OgreColourValue.h>

SnakeApplication::SnakeApplication(void)
{
}

SnakeApplication::~SnakeApplication(void)
{
}

void SnakeApplication::createScene(void)
{

  Ogre::Entity* mesh = mSceneMgr->createEntity("yoloblock", "cube.mesh");
  Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
  node->setPosition(0.0, 100.0, 0.0);
  node->attachObject(mesh);

  mCamera->lookAt(node->getPosition());

  mSceneMgr->setAmbientLight(Ogre::ColourValue(.1, .1, .1));
  Ogre::Light* light = mSceneMgr->createLight();
  light->setPosition(.0, .0, .0);
  light->setPowerScale(5);

  light = mSceneMgr->createLight();
  light->setPosition(20.0, 120.0, .0);
  light->setPowerScale(2);

  light = mSceneMgr->createLight();
  light->setPosition(-20.0, 120.0, .0);
  light->setPowerScale(2);
}



#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
  INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
  int main(int argc, char *argv[])
#endif
  {
    // Create application object
    SnakeApplication app;

    try {
      app.go();
    } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
      MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
      std::cerr << "An exception has occured: " <<
          e.getFullDescription().c_str() << std::endl;
#endif
    }
    return 0;
}

#ifdef __cplusplus
}
#endif
