

#include "SplashScene.h"
#include "../Title/TitleScene.h"

#include"../GameMain/GameMainScene.h"


USING_NS_CC;



Scene *Splash::createScene(){
	auto scene = Scene::create();
	auto layer = Splash::create();
	scene->addChild(layer);
	return scene;
}

bool Splash::init(){

	if (!Layer::init()) {
		return false;
	}

	
	Size winSize = Director::getInstance()->getWinSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	//背景
	auto background = Sprite::create("beforeTitle.png");

	
	background->setPosition(Point(winSize.width / 2, winSize.height / 2));
	background->setScale(1, 1);
	this->addChild(background, 0);

	// タイトル画面に画面遷移する
	this->scheduleOnce(schedule_selector(Splash::changeScene), 3.0f);
	return true;
}

void Splash::changeScene(float millsecond){

	
	auto nextScene = Title::createScene();

	// 0.5秒かけてホワイトアウトしてタイトルに移動する
	TransitionFade* fade = TransitionFade::create(1.0f, nextScene, Color3B::WHITE);

	
	Director::getInstance()->replaceScene(fade);
}