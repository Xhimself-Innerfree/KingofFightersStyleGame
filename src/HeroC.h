#pragma once
#ifndef _HEROC_H_
#define _HEROC_H_
#include<iostream>
#include "cocos2d.h"
using namespace cocos2d;
class HeroC :public Node
{
public:
	HeroC();
	HeroC(const HeroC& p);
	~HeroC();
	Sprite* getSpriteC();    //获取精灵对象
	void bindSpriteC(Sprite* sprite);    //绑定精灵对象
	EventListener* getEventListenerC();
	void bindListenerC(EventListener* listenerKey);
	void startMovieC();
	void moveLeftC();
	void moveRightC();
	void stopEveryActionC();
	void aclenchC();
	void standByC();
	void jumpUpC();
	int getPositionXXC();
	void attackC();
	Rect getBounding();
	Point getSpritePosition();

private:
	Sprite* theSpriteC;
	EventListener* listenerKeyC;

};

#endif