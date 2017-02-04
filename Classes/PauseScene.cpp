#include "PauseScene.h"
#include "SimpleAudioEngine.h"
#include "ModeScene.h"
#include "StartScene.h"
USING_NS_CC;

Scene* PauseScene::createScene()
{
    auto scene = Scene::create();
    auto layer = PauseScene::create();
    scene->addChild(layer);
    return scene;
}

bool PauseScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backButton = MenuItemImage::create(
         "UI/BackNormalIcon.png",
         "UI/BackSelectedIcon.png",
         CC_CALLBACK_1(PauseScene::menuBackCallback, this));
	backButton->setPosition(Vec2(visibleSize.width - backButton->getContentSize().width / 2,
		visibleSize.height  - backButton->getContentSize().height / 2));

	auto settingsButton = MenuItemImage::create(
		"UI/SettingsNormalIcon.png",
		"UI/SettingsSelectedIcon.png",
		CC_CALLBACK_1(PauseScene::menuSettingsCallback, this));
	settingsButton->setPosition(Vec2(visibleSize.width - settingsButton->getContentSize().width / 2,
		visibleSize.height - settingsButton->getContentSize().height * 2));

	auto exitButton = MenuItemImage::create(
		"UI/ToMainMenuNormal.png",
		"UI/ToMainMenuSelected.png",
		CC_CALLBACK_1(PauseScene::menuExitToMainMenuCallback, this));
	exitButton->setPosition(Vec2(visibleSize.width - exitButton->getContentSize().width / 2,
		visibleSize.height - exitButton->getContentSize().height * 4));

    auto menu = Menu::create(backButton, settingsButton, exitButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
   
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    this->addChild(sprite, 0);
    
    return true;
}


void PauseScene::menuSettingsCallback(Ref* pSender)
{
	Director::getInstance()->end(); //Заглушка
}

void PauseScene::menuBackCallback(Ref* pSender) {
	//auto nextScene = ModeScene::createScene();  
	//auto transition = TransitionFade::create(1.0f, nextScene); 
	Director::getInstance()->popScene();
}

void PauseScene::menuExitToMainMenuCallback(cocos2d::Ref * pSender)
{
	auto nextScene = StartScene::createScene();
	auto transition = TransitionFade::create(1.0f, nextScene);
	Director::getInstance()->replaceScene(transition);
}
