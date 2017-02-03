#include "ModeScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "StartScene.h"

USING_NS_CC;

Scene* ModeScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = ModeScene::create();

    scene->addChild(layer);

    return scene;
}

bool ModeScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto policeModeButton = MenuItemImage::create(
                                           "SelectNormal.png",
                                           "SelectSelected.png",
                                           CC_CALLBACK_1(ModeScene::menuCloseCallback, this));
    
	policeModeButton->setPosition(Vec2(visibleSize.width / 2, 3 * visibleSize.height / 4));

	auto emergencyModeButton = MenuItemImage::create(
		"SelectNormal.png",
		"SelectSelected.png",
		CC_CALLBACK_1(ModeScene::menuCloseCallback, this));

	emergencyModeButton->setPosition(Vec2(visibleSize.width / 2, 2 * visibleSize.height / 4));

	auto taxiModeButton = MenuItemImage::create(
		"SelectNormal.png",
		"SelectSelected.png",
		CC_CALLBACK_1(ModeScene::menuCloseCallback, this));

	taxiModeButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 4));

	auto backButton = MenuItemImage::create(
		"BackNormal.png",
		"BackModeSelected.png",
		CC_CALLBACK_1(ModeScene::menuBackCallback, this));
	backButton->setPosition(Vec2(visibleSize.width - backButton->getContentSize().width / 2,
		backButton->getContentSize().height / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(policeModeButton, emergencyModeButton, taxiModeButton, backButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
   

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("road960.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}


void ModeScene::menuCloseCallback(Ref* pSender)
{
	auto nextScene = GameScene::createScene();
	auto transition = TransitionFade::create(1.0f, nextScene);
	Director::getInstance()->replaceScene(transition);
}

void ModeScene::menuBackCallback(Ref* pSender) {
	auto nextScene = StartScene::createScene();
	auto transition = TransitionFade::create(1.0f, nextScene);
	Director::getInstance()->replaceScene(transition);
}