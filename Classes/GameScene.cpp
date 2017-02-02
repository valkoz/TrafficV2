#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "PauseScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{   auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto pauseButton = MenuItemImage::create(
                                           "PauseNormal.png",
                                           "PauseSelected.png",
                                           CC_CALLBACK_1(GameScene::menuPauseCallback, this));
    
	pauseButton->setPosition(Vec2(origin.x + visibleSize.width - pauseButton->getContentSize().width/2 ,
                                origin.y + pauseButton->getContentSize().height/2));

	auto roadSprite = Sprite::create("road.jpg");
	roadSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(roadSprite);
    auto menu = Menu::create(pauseButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    return true;
}


void GameScene::menuPauseCallback(Ref* pSender)
{
	auto nextScene = PauseScene::createScene();  
	auto transition = TransitionFade::create(1.0f, nextScene);  
	Director::getInstance()->pushScene(transition);
	// Try use layer, pleaseeeeee
		//Director::getInstance()->pause();      
    //swich HERE!!! to pauseLayer. LAYER!!!!!!!!! 
    
}
