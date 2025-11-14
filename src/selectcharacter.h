#pragma once
#ifndef __SELECTCHARACTER_H__
#define __SELECTCHARACTER_H__
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include"a.h"
using namespace cocos2d::ui;
using namespace cocos2d;
USING_NS_CC;

class selectcharacter : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    // a selector callback

    void menustart(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(selectcharacter);

};

#endif 


