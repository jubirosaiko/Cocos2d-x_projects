
#ifndef __GAMEMAIN_SCENE_H__
#define __GAMEMAIN_SCENE_H__

#include "cocos2d.h"

class GameMain : public cocos2d::Layer
{
private:
	cocos2d::EventListenerTouchOneByOne* listener;

	enum MOVECOMMAND
	{
		RIGHT,
		LEFT,
		//UP,
		//DOWN,
		JUMP,
	};
	MOVECOMMAND _moveCommand;
	enum TAG
	{
		NULL_TAG,
		BUTTON_RIGHT_TAG,
		BUTTON_LEFT_TAG,
		BUTTON_UP_TAG,
		BUTTON_DOWN_TAG,
		BUTTON_JUMP_TAG,
	};

public:
	static cocos2d::Scene* createScene();


	cocos2d::MenuItemImage* rightButton;
	cocos2d::MenuItemImage* leftButton;
	cocos2d::MenuItemImage* upButton;
	cocos2d::MenuItemImage* downButton;
	cocos2d::MenuItemImage* jumpButton;

	 cocos2d::Vec2 rightButtonPos;
	 cocos2d::Vec2 leftButtonPos;
	 cocos2d::Vec2 upButtonPos;
	 cocos2d::Vec2 downButtonPos;
	 cocos2d::Vec2 jumpButtonPos;

	 cocos2d::Menu* buttonMenu;
	// cocos2d::Sprite 
	 float buttonSize;

	//GameMain();
	virtual bool init();


	virtual void update();

	//void menuCloseCallback(cocos2d::Ref* pSender);

	bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	void onToucheEnded(cocos2d::Touch*, cocos2d::Event*);

	void changeResultScene();


	CREATE_FUNC(GameMain);
};


#endif // __TITLE_SCENE_H__