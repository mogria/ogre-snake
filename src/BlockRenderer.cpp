#include "BlockRenderer.h"

BlockRenderer::BlockRenderer(Ogre::SceneManager* _scene)
  : mSceneMgr(_scene) {

}


void BlockRenderer::render(Model::map_coords xy, Model::EmptyBlock block) {
}


void BlockRenderer::render(Model::map_coords xy, Model::CollisionBlock block) {
}


void BlockRenderer::render(Model::map_coords xy, Model::SnakePart block) {
}


void BlockRenderer::render(Model::map_coords xy, Model::SnakeHead block) {
}
