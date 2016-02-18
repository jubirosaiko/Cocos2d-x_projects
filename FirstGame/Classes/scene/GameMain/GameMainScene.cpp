
#include"GameMainScene.h"
#include"object/player/player.h"
#include"scene/Splash/SplashScene.h"
USING_NS_CC;

Scene* GameMain::createScene()
{
	auto scene = Scene::create();
	auto layer = GameMain::create();
	scene->addChild(layer);
	return scene;
}

bool GameMain::init()
{
	if (!Layer::init()){
		return false;
	}
	this->scheduleUpdate();

	Player* player;


	Size winSize = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//”wŒi
    auto background = Sprite::create("background.png");
	 background->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	 this->addChild(background, 0);

	//ƒ^ƒbƒ`—p
	listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameMain::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameMain::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameMain::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	this->scheduleUpdate();


	rightButtonPos = cocos2d::Vec2(90, 30);;
	leftButtonPos = cocos2d::Vec2(0, 30);;
	upButtonPos = cocos2d::Vec2(225, 215);;
	downButtonPos = cocos2d::Vec2(225, 215);;
	jumpButtonPos = cocos2d::Vec2(225, 215);;

	buttonSize = 0.25f;

	rightButton = MenuItemImage::create("GameMain/buttonright.png", "GameMain/buttonleft.png", [&](Ref*sender)
	{
		/*Sprite* selectedButtonRight = Sprite::create("GameMain/buttonleft.png");
		selectedButtonRight->setPosition(rightButtonPos);
		selectedButtonRight->setScale(buttonSize);
		selectedButtonRight->setTag(BUTTON_RIGHT_TAG);
		this->addChild(selectedButtonRight);*/

	});
	rightButton->setPosition(rightButtonPos);
	rightButton->setScale(buttonSize);
	
	leftButton = MenuItemImage::create("GameMain/buttonleft.png", "GameMain/buttonleft.png", [&](Ref*sender)
	{

		//‰æ–Ê‘JˆÚ‚·‚éB
		auto nextScene = Splash::createScene(); // Œã‚Å•Ï‚¦‚é

		TransitionFade* fade = TransitionFade::create(1.0f, nextScene, Color3B::WHITE);
		if (fade){
			Director::getInstance()->replaceScene(fade);
		}
	});
	leftButton->setPosition(leftButtonPos);
	leftButton->setScale(buttonSize);
	/*
	upButton = MenuItemImage::create("GameMain/buttonup.png", nullptr, [&](Ref*sender)
	{

	});

	downButton = MenuItemImage::create("GameMain/buttondown.png", nullptr, [&](Ref*sender)
	{

	});

	jumpButton = MenuItemImage::create("GameMain/buttonjump.png", nullptr, [&](Ref*sender)
	{

	});*/


	buttonMenu = Menu::create(rightButton, leftButton, NULL);
	buttonMenu->setPosition(rightButtonPos);
	this->addChild(buttonMenu);







	return true;
}

bool GameMain::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	

	return true;
}

void GameMain::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
}

void GameMain::onToucheEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
}



void GameMain::update()
{
}

void GameMain::changeResultScene()
{

}
