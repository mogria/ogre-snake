#include "BlockRenderer.h"
#include <OgreMeshManager.h>
#include <OgreResourceGroupManager.h>

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
  getOrCreateBlock(xy);
}

void BlockRenderer::render(Model::map_coords xy, const Model::EmptyBlock& block) {
}


void BlockRenderer::render(Model::map_coords xy, const Model::CollisionBlock& block) {
}


void BlockRenderer::render(Model::map_coords xy, const Model::SnakePart& block) {
}


void BlockRenderer::render(Model::map_coords xy, const Model::SnakeHead& block) {
}

