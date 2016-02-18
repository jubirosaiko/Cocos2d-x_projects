
#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "cocos2d.h"

class Title : public cocos2d::Layer
{
private:
	cocos2d::EventListenerTouchOneByOne* listener;

public:
	static cocos2d::Scene* createScene();

	//Label* TitleLabel;

	virtual bool init();



	void menuCloseCallback(cocos2d::Ref* pSender);

	

	bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	void onToucheEnded(cocos2d::Touch*, cocos2d::Event*);

	void changeMenuScene();

	CREATE_FUNC(Title);
};


#endif // __TITLE_SCENE_H__