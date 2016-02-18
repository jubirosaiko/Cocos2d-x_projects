
#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

class GameMenu : public cocos2d::Layer
{
private:
	cocos2d::EventListenerTouchOneByOne* listener;

public:
	static cocos2d::Scene* createScene();

	cocos2d::Size winSize;
	cocos2d::Vec2 origin;

	virtual bool init();

	void menuCloseCallback(cocos2d::Ref* pSender);

	void ChangeScene();

	bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	void onToucheEnded(cocos2d::Touch*, cocos2d::Event*);







	CREATE_FUNC(GameMenu);
};


#endif // __TITLE_SCENE_H__