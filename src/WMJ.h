#pragma once
#ifndef  __wmj_H__
#define  __wmj_H__
#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Hero.h"
#include "Hero2.h"
#include "HeroC.h"
#include"Gamepause.h"
USING_NS_CC;


class WMJ :public Scene {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(WMJ);
	void updateProgress(float);
	void updateProgress2(float);
	virtual void update(float dt);
	void pasuecallback(cocos2d::Ref* pSender);
private:
	int Percentage = 100;
	int Percentage2 = 100;
	
};

#endif
