#ifndef __Gamepause__H__
#define __Gamepause__H__
#include "cocos2d.h"
#include"WMJ.h"
#include "ui/CocosGUI.h"
#include"HelloWorldScene.h"
#include"selectcharacter.h"
using namespace std;
USING_NS_CC;
class Gamepause : public cocos2d::Scene
{
public:
    virtual bool init();
    static cocos2d::Scene* createScene();
    CREATE_FUNC(Gamepause);
    //¼ÌÐøÓÎÏ·
   /* void menuContinueCallback(cocos2d::Ref* pSender);
    void menuCallback(cocos2d::Ref* pSender);*/

private:

};

#endif // __Gamepause_H__
