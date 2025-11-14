#pragma once
#ifndef _HEROBASE_H_
#define _HEROBASE_H_
#include<iostream>
#include "cocos2d.h"
using namespace cocos2d;
class HeroBase :public Node
{
public:
	//基本函数
	HeroBase();
	HeroBase(const HeroBase& p);
	virtual ~HeroBase();//作为基类，析构函数设为虚函数
	//相同的类
	Sprite* getSprite();    //获取精灵对象
	void bindSprite(Sprite* sprite);    //绑定精灵对象
	EventListener* getEventListener();
	void bindListener(EventListener* listenerKey);
	Rect getBounding();
	Point getSpritePosition();
	//每个人物不同的函数
	virtual void startMovie() = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
	virtual void stopEveryAction() = 0;
	virtual void aclench() = 0;
	virtual void standBy() = 0;
	virtual void defence() = 0;
	
	//数据成员
	Sprite* theSprite;
	EventListener* listenerKey;

};
#endif
