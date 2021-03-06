#include "SnakeApplication.h"
#include <OgreColourValue.h>

SnakeApplication::SnakeApplication(void)
  : mMap(Model::coords(32, 24))
{
}

SnakeApplication::~SnakeApplication(void)
{
}

void SnakeApplication::createScene(void)
{
  mCamera->setPosition(Ogre::Vector3(0.0, -20.0, 0.0));
  mCamera->lookAt(0.0, 0.0, 0.0);

  mSceneMgr->setAmbientLight(Ogre::ColourValue(.5, .5, .5));
  Ogre::Light* light = mSceneMgr->createLight();
  light->setPosition(.0, .0, .0);
  light->setPowerScale(5);

  mBlockRenderer = std::unique_ptr<BlockRenderer>(new BlockRenderer(mSceneMgr));
}

bool SnakeApplication::frameRenderingQueued(const Ogre::FrameEvent& evt) {
  if(!BaseApplication::frameRenderingQueued(evt)) return false;

  auto blocks = mMap.to_array();
  Model::map_coords size = mMap.get_size();
  for(Model::map_coord y = 0; y < size.second; y++) {
    for(Model::map_coord x = 0; x < size.first; x++) {
      mBlockRenderer->render(Model::coords(x, y), *blocks[y][x]);
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
