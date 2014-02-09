#ifndef SNAKE_APPLICATION_H
#define SNAKE_APPLICATION_H

#include "BaseApplication.h"

#include <model/Map.h>

class SnakeApplication : public BaseApplication
{
private: 
  Model::Map map;
  
public:
  SnakeApplication(void);
  virtual ~SnakeApplication(void);

protected:
  virtual void createScene(void);
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
};

#endif /* SNAKE_APPLICATION_H */
