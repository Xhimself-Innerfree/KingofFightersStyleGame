#pragma once
#include "cocos2d.h"
USING_NS_CC;
class GameOver:public Scene
{
private:

public:
	virtual bool init();
	static cocos2d::Scene* scene();
	void playAgain(Ref* pSender);
	CREATE_FUNC(GameOver);
};

