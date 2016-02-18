
#include"TitleScene.h"
#include"../Menu/MenuScene.h"
#include"../GameMain/GameMainScene.h"

USING_NS_CC;

Scene* Title::createScene()
{
	auto scene = Scene::create();
	auto layer = Title::create();
	scene->addChild(layer);
	return scene;
}

bool Title::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	auto background = Sprite::create("Title.png");
	background->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->addChild(background, 0);
	
	//タッチ用
	listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Title::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Title::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Title::onTouchEnded, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	this->scheduleUpdate();

	
	//this->scheduleOnce(schedule_selector(Title::changeMenuScene),0.0f);
	
	
	
	return true;
}

void Title::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}


bool Title::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	/*auto nextScene = GameMenu::createScene();
	Director::getInstance()->replaceScene(nextScene);*/
	changeMenuScene();
	return true;
}

void Title::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
}

void Title::onToucheEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
}


void Title::changeMenuScene()
{

	//画面遷移する。
	auto nextScene = GameMain::createScene(); // 後で変える

	TransitionFade* fade = TransitionFade::create(1.0f, nextScene, Color3B::WHITE);
	if (fade){
		Director::getInstance()->replaceScene(fade);
	}
}





