#ifndef BLOCK_RENDERER_H
#define BLOCK_RENDERER_H

#include <model/Block.h>
#include <model/Map.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

class BlockRenderer {
  private:
    Ogre::SceneManager* mSceneMgr;
  public:
    BlockRenderer(Ogre::SceneManager* scene);
    virtual void render(Model::map_coords xy, const Model::Block& block);
    virtual void render(Model::map_coords xy, const Model::EmptyBlock& block);
    virtual void render(Model::map_coords xy, const Model::CollisionBlock& block);
    virtual void render(Model::map_coords xy, const Model::SnakePart& block);
    virtual void render(Model::map_coords xy, const Model::SnakeHead& block);
};
#endif /* BLOCK_RENDERER_H */
