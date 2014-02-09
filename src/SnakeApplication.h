#ifndef SNAKE_APPLICATION_H
#define SNAKE_APPLICATION_H

#include "BaseApplication.h"

class SnakeApplication : public BaseApplication
{
public:
    SnakeApplication(void);
    virtual ~SnakeApplication(void);

protected:
    virtual void createScene(void);
};

#endif /* SNAKE_APPLICATION_H */
