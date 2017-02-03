#include "StartScene.h"
#include "SimpleAudioEngine.h"
#include "ModeScene.h"
#include "SettingsScene.h"
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
                                           "start.png",
                                           "ChooseModeSelected.png",
                                           CC_CALLBACK_1(StartScene::menuChooseModeCallback, this));
	chooseModeButton->setPosition(Vec2(visibleSize.width /2, 4 * visibleSize.height / 5));
	
	auto settingsButton = MenuItemImage::create(
		"SettingsNormal.png",
		"SettingsSelected.png",
		CC_CALLBACK_1(StartScene::menuSettingsCallback, this));
	settingsButton->setPosition(Vec2(visibleSize.width / 2,
		3 * visibleSize.height / 5));

	auto leaderboardButton = MenuItemImage::create(
		"LeaderboardNormal.png",
		"LeaderboardSelected.png",
		CC_CALLBACK_1(StartScene::menuLeaderBoardCallback, this));
	leaderboardButton->setPosition(Vec2(visibleSize.width / 2, 2 * visibleSize.height / 5));

	auto exitButton = MenuItemImage::create(
		"ExitNormal.png",
		"ExitSelected.png",
		CC_CALLBACK_1(StartScene::menuCloseCallback, this));
	exitButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 5));

	

    auto menu = Menu::create(chooseModeButton, leaderboardButton, exitButton, settingsButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
   
    auto sprite = Sprite::create("road960.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    this->addChild(sprite, 0);
    
    return true;
}


void StartScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
}

void StartScene::menuChooseModeCallback(Ref* pSender) {
	auto nextScene = ModeScene::createScene();  
	auto transition = TransitionFade::create(1.0f, nextScene); 
	Director::getInstance()->replaceScene(transition);
}

void StartScene::menuSettingsCallback(Ref* pSender) {
	auto nextScene = SettingsScene::createScene();
	auto transition = TransitionFade::create(1.0f, nextScene);
	Director::getInstance()->replaceScene(transition);
}

void StartScene::menuLeaderBoardCallback(Ref* pSender) {
	Director::getInstance()->end();
}
