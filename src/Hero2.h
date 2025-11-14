#pragma once
#ifndef _HERO2_H_
#define _HERO2_H_
#include<iostream>
#include "cocos2d.h"
#include"HeroBase.h"
using namespace cocos2d;
class Hero2 :public HeroBase
{
public:
	Hero2();
	Hero2(const Hero2& p);
	~Hero2();

	void startMovie();
	void moveLeft();
	void moveRight();
	void stopEveryAction();
	void aclench();
	void standBy();
	void defence();
};
#endif