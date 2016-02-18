
#include "player.h"

USING_NS_CC;

bool Player::Init()
{
	if (!Sprite::init()){
		return false;
	}
	this->scheduleUpdate();

	Size winSize = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	return true;
}

void Player::Move()
{

}
