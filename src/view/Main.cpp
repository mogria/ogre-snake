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

    std::ifstream file("media/models/cube.mesh");
    std::cout << "opened file ... " << (file.is_open() ? "sucessfully" : "errorously") << std::endl;
    Ogre::FileStreamDataStream cubeFile(&file, true);

    Ogre::MeshPtr pMesh = Ogre::MeshManager::getSingleton().createManual("BlockMesh", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    Ogre::MeshSerializer serializer;
    Ogre::DataStreamPtr stream(&cubeFile);
    serializer.importMesh(stream, pMesh.getPointer());
    Ogre::Entity* mesh = scene.createEntity("yoloblock", "BlockMesh");
    Ogre::SceneNode* node = scene.getRootSceneNode()->createChildSceneNode();
    node->setPosition(0, 0.5, 0);
    node->attachObject(mesh);
};


void Main::render(Map& map, Snake& snake)  {
}


}; /* namespace View */
