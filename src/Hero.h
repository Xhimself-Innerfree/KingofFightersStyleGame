#pragma once
#ifndef _HERO_H_
#define _HERO_H_
#include<iostream>
#include "cocos2d.h"
#include"HeroBase.h"
using namespace cocos2d;
class Hero :public HeroBase
{
public:
	Hero();
	Hero(const Hero& p);
	~Hero();

	void startMovie();
	void moveLeft();
	void moveRight();
	void stopEveryAction();
	void aclench();
	void standBy();
	void defence();


};

#endif