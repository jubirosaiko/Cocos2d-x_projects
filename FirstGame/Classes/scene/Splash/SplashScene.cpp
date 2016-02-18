

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

	//�w�i
	auto background = Sprite::create("beforeTitle.png");

	
	background->setPosition(Point(winSize.width / 2, winSize.height / 2));
	background->setScale(1, 1);
	this->addChild(background, 0);

	// �^�C�g����ʂɉ�ʑJ�ڂ���
	this->scheduleOnce(schedule_selector(Splash::changeScene), 3.0f);
	return true;
}

void Splash::changeScene(float millsecond){

	
	auto nextScene = Title::createScene();

	// 0.5�b�����ăz���C�g�A�E�g���ă^�C�g���Ɉړ�����
	TransitionFade* fade = TransitionFade::create(1.0f, nextScene, Color3B::WHITE);

	
	Director::getInstance()->replaceScene(fade);
}