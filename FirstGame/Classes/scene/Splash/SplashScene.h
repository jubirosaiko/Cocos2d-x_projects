

#ifndef __SPLASH_SCENE_H__
#define __SPLASH_SCENE_H__

#include "cocos2d.h"

class Splash :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	//Label* TitleLabel;

	virtual bool init();



	void menuCloseCallback(cocos2d::Ref* pSender);

	void changeScene(float);



	CREATE_FUNC(Splash);
};

#endif // __SPLASH_SCENE_H__