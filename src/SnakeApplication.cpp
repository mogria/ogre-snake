#include "SnakeApplication.h"
#include <OgreColourValue.h>

SnakeApplication::SnakeApplication(void)
  : map(Model::coords(32, 24))
{
}

SnakeApplication::~SnakeApplication(void)
{
}

void SnakeApplication::createScene(void)
{
  float Spacing = 0.1;
  float Scaling = 0.1;
  int numX = 10;
  int numY = 10;

  Ogre::Entity* mesh = mSceneMgr->createEntity("cube.mesh");

  while(numX-- > 0)
  {
    while(numY-- > 0)
    {
      Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
      
      node->setScale(Scaling,Scaling,Scaling);
      node->setPosition(mesh->getBoundingBox().getSize().x * Scaling * numX, mesh->getBoundingBox().getSize().y * Scaling * numY, 0.0);
      node->attachObject(mesh->clone(Ogre::StringConverter::toString(numY) + Ogre::StringConverter::toString(numX) + "Yolocube"));

      Ogre::LogManager::getSingleton().logMessage(Ogre::StringConverter::toString(node->getPosition()));
    }
  }

  mCamera->lookAt(.0,.0,.0);
  mCamera->setPosition(Ogre::Vector3(0.0, -20.0, 0.0));

  mSceneMgr->setAmbientLight(Ogre::ColourValue(.5, .5, .5));
  Ogre::Light* light = mSceneMgr->createLight();
  light->setPosition(.0, .0, .0);
  light->setPowerScale(5);
}

bool SnakeApplication::frameRenderingQueued(const Ogre::FrameEvent& evt) {
  if(!BaseApplication::frameRenderingQueued(evt)) return false;

  auto blocks = map.to_array();
  Model::map_coords size = map.get_size();
  for(Model::map_coord y = 0; y < size.second; y++) {
    for(Model::map_coord x = 0; x < size.first; x++) {
      // render block map[y][x]
    }
  }

  return true;
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
