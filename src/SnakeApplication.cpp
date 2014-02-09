#include "SnakeApplication.h"

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
  node->setPosition(0, 0.5, 0);
  node->attachObject(mesh);
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
