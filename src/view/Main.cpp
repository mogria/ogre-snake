#include "Main.h"
#include <model/Map.h>
#include <model/Snake.h>


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

    std::fstream file("media/models/cube.mesh");
    Ogre::FileStreamDataStream cubeFile(&file);

    Ogre::MeshPtr pMesh = Ogre::MeshManager::getSingleton().createManual("BlockMesh", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    Ogre::MeshSerializer serializer;
    Ogre::DataStreamPtr stream(&cubeFile);
    serializer.importMesh(stream, pMesh.getPointer());
};


void Main::render(Map& map, Snake& snake)  {
  Ogre::Entity* mesh = scene.createEntity("yoloblock", "BlockMesh");
}


}; /* namespace View */
