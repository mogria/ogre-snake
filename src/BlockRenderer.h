#ifndef BLOCK_RENDERER_H
#define BLOCK_RENDERER_H

#include <model/Block.h>
#include <model/Map.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>
#include <OgreMesh.h>

class BlockRenderer {
  private:
    Ogre::SceneManager* mSceneMgr;
    Ogre::MeshPtr mMesh;

    std::map<Model::map_coords, Ogre::SceneNode*> mCubes; // contains a list of all cubes to prevent reloading
                                        // simple workaround
    // TODO list object contains all active cubes as pointers (Nodes) and removes them if they are not needed anymore
    // -> first object is original cube from witch all the others are cloned .. hope that helps
  public:
    BlockRenderer(Ogre::SceneManager* scene);
    virtual ~BlockRenderer();

    Ogre::SceneNode* getOrCreateBlock(Model::map_coords xy);

    virtual void render(Model::map_coords xy, const Model::Block& block);
    virtual void render(Model::map_coords xy, const Model::EmptyBlock& block);
    virtual void render(Model::map_coords xy, const Model::CollisionBlock& block);
    virtual void render(Model::map_coords xy, const Model::SnakePart& block);
    virtual void render(Model::map_coords xy, const Model::SnakeHead& block);

};
#endif /* BLOCK_RENDERER_H */
