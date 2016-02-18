
#include "MenuScene.h"
#include"../GameMain/GameMainScene.h"


USING_NS_CC;

Scene *GameMenu::createScene(){
	auto scene = Scene::create();
	auto layer = GameMenu::create();
	scene->addChild(layer);
	return scene;
}


bool GameMenu::init(){

	if (!Layer::init()){
		return false;
	}
	
	listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(GameMenu::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameMenu::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameMenu::onTouchEnded, this);
	
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	this->scheduleUpdate();


	winSize = Director::getInstance()->getWinSize();
	origin = Director::getInstance()->getVisibleOrigin();
	//auto background = GameMenu::create("");
	//this->addChild(background);
	//this->scheduleOnce(schedule_selector(Title::changeMenuScene), 0.0f);
	
	
	
	return true;
}

void GameMenu::menuCloseCallback(Ref* pSender){

	Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

bool GameMenu::onTouchBegan(cocos2d::Touch*, cocos2d::Event*)
{
	ChangeScene();
	return true;
}

void GameMenu::onTouchMoved(cocos2d::Touch*, cocos2d::Event*)
{
}

void GameMenu::onToucheEnded(cocos2d::Touch*, cocos2d::Event*)
{
}



void GameMenu::ChangeScene(){

	//‰æ–Ê‘JˆÚ‚·‚éB
	auto nextScene = GameMain::createScene(); // Œã‚Å•Ï‚¦‚é

	TransitionFade* fade = TransitionFade::create(1.0f, nextScene, Color3B::WHITE);
	if (fade){
		Director::getInstance()->replaceScene(fade);
	}

}