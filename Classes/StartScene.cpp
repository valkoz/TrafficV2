#include "StartScene.h"
#include "SimpleAudioEngine.h"
#include "ModeScene.h"
USING_NS_CC;

Scene* StartScene::createScene()
{
    auto scene = Scene::create();
    auto layer = StartScene::create();
    scene->addChild(layer);
    return scene;
}

bool StartScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto chooseModeButton = MenuItemImage::create(
                                           "ChooseModeNormal.png",
                                           "ChooseModeSelected.png",
                                           CC_CALLBACK_1(StartScene::menuChooseModeCallback, this));
	chooseModeButton->setPosition(Vec2(visibleSize.width /2, 4 * visibleSize.height / 5));

	auto exitButton = MenuItemImage::create(
		"ExitNormal.png",
		"ExitSelected.png",
		CC_CALLBACK_1(StartScene::menuCloseCallback, this));
	exitButton->setPosition(Vec2(visibleSize.width / 2, 3 * visibleSize.height / 5));


    auto menu = Menu::create(chooseModeButton, exitButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
   
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    this->addChild(sprite, 0);
    
    return true;
}


void StartScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}

void StartScene::menuChooseModeCallback(Ref* pSender) {
	auto nextScene = ModeScene::createScene();  
	auto transition = TransitionFade::create(1.0f, nextScene); 
	Director::getInstance()->replaceScene(transition);
}
