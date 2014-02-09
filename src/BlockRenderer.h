#ifndef BLOCK_RENDERER_H
#define BLOCK_RENDERER_H

#include <model/Block.h>
#include <model/Map.h>
#include <OgreSceneManager.h>

class BlockRenderer {
  private:
    Ogre::SceneManager* mSceneMgr;
  public:
    BlockRenderer(Ogre::SceneManager* scene);
    void render(Model::map_coords xy, Model::EmptyBlock block);
    void render(Model::map_coords xy, Model::CollisionBlock block);
    void render(Model::map_coords xy, Model::SnakePart block);
    void render(Model::map_coords xy, Model::SnakeHead block);
};
#endif /* BLOCK_RENDERER_H */
