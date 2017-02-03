#ifndef __MODE_SCENE_H__
#define __MODE_SCENE_H__

#include "cocos2d.h"

class ModeScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	void menuBackCallback(Ref * pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(ModeScene);
};

#endif // __MODE_SCENE_H__
