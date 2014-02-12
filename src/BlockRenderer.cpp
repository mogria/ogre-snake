#include "BlockRenderer.h"

BlockRenderer::BlockRenderer(Ogre::SceneManager* _scene)
  : mSceneMgr(_scene)
{

}


void BlockRenderer::render(Model::map_coords xy, const Model::Block& block) {
  float scaling = 0.1;
  Ogre::Entity* entity = mSceneMgr->createEntity("cube.mesh");
  Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
  
  node->setScale(scaling, scaling, scaling);
  auto box_size = entity->getBoundingBox().getSize();
  node->setPosition(box_size.x * xy.first * scaling,
                    box_size.y * xy.second * scaling,
                    0.0);
  node->attachObject(entity);
}

void BlockRenderer::render(Model::map_coords xy, const Model::EmptyBlock& block) {
}


void BlockRenderer::render(Model::map_coords xy, const Model::CollisionBlock& block) {
}


void BlockRenderer::render(Model::map_coords xy, const Model::SnakePart& block) {
}


void BlockRenderer::render(Model::map_coords xy, const Model::SnakeHead& block) {
}

BlockRenderer::~BlockRenderer() {
  for(std::list<Ogre::SceneNode*>::iterator it = mCubes.begin; mCubes.back != it; it++)
  {
    it->
  }
}
