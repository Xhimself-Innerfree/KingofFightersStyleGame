#pragma once
#include "cocos2d.h"
using namespace cocos2d;
class setting : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    static int _slidepercent;
    virtual bool init();

    // a selector callback
    void musiccontrollercallback(cocos2d::Ref* pSender);
    void menuCallback(cocos2d::Ref* pSender);
    void updateProgress(float);
    virtual void onTouchMoved(Touch* touch, Event* event);
    // implement the "static create()" method manually
    CREATE_FUNC(setting);
    EventListenerTouchOneByOne* _listener;
private:
    int Percentagevloume = 50;
    
    //string _AudioID;
    //auto backgroundMusic = AudioEngine::play2d("Esaka.mp3", true);
};

