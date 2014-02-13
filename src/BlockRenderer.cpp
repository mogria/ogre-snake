#include "BlockRenderer.h"
#include <OgreMeshManager.h>
#include <OgreResourceGroupManager.h>
#include <OgreSubEntity.h>

BlockRenderer::BlockRenderer(Ogre::SceneManager* _scene)
  : mSceneMgr(_scene) {
  Ogre::MeshManager& meshManager = Ogre::MeshManager::getSingleton();
  mMesh = meshManager.load("cube.mesh",
      Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
}

BlockRenderer::~BlockRenderer() {
  for(auto it = mCubes.begin(); mCubes.end() != it; it++)
  {
    it->second->removeAndDestroyAllChildren();
    mSceneMgr->destroySceneNode(it->second);
  }
}

Ogre::SceneNode* BlockRenderer::getOrCreateBlock(Model::map_coords xy) {
  if(mCubes.find(xy) == mCubes.end()) {
    float scaling = 0.1;
    Ogre::Entity* entity = mSceneMgr->createEntity(mMesh);
    Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    
    node->setScale(scaling, scaling, scaling);
    auto box_size = entity->getBoundingBox().getSize();
    node->setPosition(box_size.x * xy.first * scaling,
                      box_size.y * xy.second * scaling,
                      0.0);
    node->attachObject(entity);

    mCubes[xy] = node;
  }
  return mCubes[xy];
}

void BlockRenderer::render(Model::map_coords xy, const Model::Block& block) {
  Ogre::SceneNode* node = getOrCreateBlock(xy);
  Ogre::Entity* entity = static_cast<Ogre::Entity*>(node->getAttachedObject(0));

  // this changes the color of the entitiy,
  // TODO: but it changes the color of all entities (which is not intended)
  // I presume this is because all entities use the same material/mesh
  unsigned int num_entities = entity->getNumSubEntities();
  for(unsigned int counter = 0; counter < num_entities; counter++)
  {
    Ogre::SubEntity *subentity= entity->getSubEntity(counter);
    if(subentity)
    {
      Ogre::MaterialPtr material = subentity->getMaterial();
      material->setAmbient(0, 0, 255);
    }
  }
}

void BlockRenderer::render(Model::map_coords xy, const Model::EmptyBlock& block) {
}


void BlockRenderer::render(Model::map_coords xy, const Model::CollisionBlock& block) {
}


void BlockRenderer::render(Model::map_coords xy, const Model::SnakePart& block) {
}


void BlockRenderer::render(Model::map_coords xy, const Model::SnakeHead& block) {
}

