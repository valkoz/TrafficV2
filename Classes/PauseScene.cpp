#include "PauseScene.h"
#include "SimpleAudioEngine.h"
#include "ModeScene.h"
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

    auto chooseModeButton = MenuItemImage::create(
                                           "BackNormal.png",
                                           "BackModeSelected.png",
                                           CC_CALLBACK_1(PauseScene::menuBackCallback, this));
	chooseModeButton->setPosition(Vec2(visibleSize.width - chooseModeButton->getContentSize().width / 2, visibleSize.height  - chooseModeButton->getContentSize().height / 2));

	auto exitButton = MenuItemImage::create(
		"SettingsNormal.png",
		"SettingsSelected.png",
		CC_CALLBACK_1(PauseScene::menuSettingsCallback, this));
	exitButton->setPosition(Vec2(visibleSize.width - chooseModeButton->getContentSize().width / 2, visibleSize.height - chooseModeButton->getContentSize().height * 2));


    auto menu = Menu::create(chooseModeButton, exitButton, NULL);
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
