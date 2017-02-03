#include "SettingsScene.h"
#include "SimpleAudioEngine.h"
#include "ModeScene.h"
#include "StartScene.h"
USING_NS_CC;

Scene* SettingsScene::createScene()
{
    auto scene = Scene::create();
    auto layer = SettingsScene::create();
    scene->addChild(layer);
    return scene;
}

bool SettingsScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backButton = MenuItemImage::create(
         "BackNormal.png",
         "BackModeSelected.png",
         CC_CALLBACK_1(SettingsScene::menuBackCallback, this));
	backButton->setPosition(Vec2(visibleSize.width - backButton->getContentSize().width / 2,
		backButton->getContentSize().height / 2));

    auto menu = Menu::create(backButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
   
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    this->addChild(sprite, 0);
    
    return true;
}


void SettingsScene::menuBackCallback(Ref* pSender) {
	auto nextScene = StartScene::createScene();
	auto transition = TransitionFade::create(1.0f, nextScene);
	Director::getInstance()->replaceScene(transition);
}
