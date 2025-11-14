#include "setting.h"
#include"HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include<iostream>
#include "AudioEngine.h"
#include"a.h"

USING_NS_CC;
int volume1 = 100.0;
using namespace std;
using namespace ui;
int _audioID;
bool soundflag = true;
 float volume2 = volume1 / 100;
//auto audioID = AudioEngine::play2d("Esaka.mp3", true);
cocos2d::Scene* setting::createScene()
{
    return setting::create();
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool setting::init()
{
    AudioEngine::setEnabled(true);
    auto backgroundMusic = AudioEngine::play2d("music/Esaka.mp3", true);
    _audioID = backgroundMusic;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /*auto func = [=]() {
        AudioEngine::setVolume(backgroundMusic, volume1);
    };*/

    auto sprite = Sprite::create("UI/gamestart.jpg");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        sprite->setScaleX(1.3f);
        // add the sprite as a child to this layer
        this->addChild(sprite, 0);

    }

   /* auto volumeSlider = SliderEx::create();
    volumeSlider->setPercent(100);
    volumeSlider->addEventListener([&](Ref* sender, Slider::EventType event) {
        SliderEx* slider = dynamic_cast<SliderEx*>(sender);
        volume1 = slider->getRatio();
        if (_audioID != AudioEngine::INVALID_AUDIO_ID) {
            AudioEngine::setVolume(_audioID, volume1);
        }
        });
    volumeSlider->setPosition(Vec2(layerSize.width * 0.5f, layerSize.height * 0.35f));
    addChild(volumeSlider);*/

    ////音量条
    //LoadingBar* bar = LoadingBar::create();
    //bar->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    ////放在屏幕正中心
    //bar->setPosition(Vec2(visibleSize.width / 2 + origin.x + 400, visibleSize.height / 2 + origin.y - 100));
    //this->addChild(bar);
    ////加载进度条图片
    //bar->loadTexture("UI/volumebar.png");
    ////设置初始百分比
    //bar->setPercent(50);
    ////设置进度条朝向
    //bar->setDirection(ui::LoadingBar::Direction::LEFT);


    auto backItem = MenuItemImage::create(
        "UI/back2.png",
        "UI/back1.png",
        CC_CALLBACK_1(setting::menuCallback, this));

    if (backItem == nullptr ||
        backItem->getContentSize().width <= 0 ||
        backItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - backItem->getContentSize().width / 2;
        float y = origin.y + backItem->getContentSize().height / 2;
        backItem->setPosition(Vec2(visibleSize.width / 2 + origin.x + 400, visibleSize.height / 2 + origin.y - 100));
        backItem->setScale(1.5f);
    }

    auto menu = Menu::create(backItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    auto onSprite = Sprite::create("UI/button on.png");
    auto offSprite = Sprite::create("UI/button off.png");
    auto onitem = MenuItemSprite::create(onSprite,onSprite);
    auto offitem = MenuItemSprite::create(offSprite, offSprite);
    MenuItemToggle* musiccontroller = MenuItemToggle::createWithCallback(CC_CALLBACK_1(setting::musiccontrollercallback,this),
        onitem,
        offitem, NULL);
    
        musiccontroller->setSelectedIndex(!soundflag);
    
    musiccontroller->setPosition(Vec2(visibleSize.width / 2 + origin.x + 450, visibleSize.height / 2 + origin.y + 150));
   /* musiccontroller->setColor(Color3B(31, 45, 0));
    */
    Menu* menu1 = Menu::create(musiccontroller,nullptr);
    //menu->alignItemsInColumns(2, 2, 1);//这里的布局可以学习下
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1);





    auto musicUI = Sprite::create("UI/music.png");
    musicUI->setPosition(Vec2(visibleSize.width / 2 + origin.x + 250, visibleSize.height / 2 + origin.y + 150));
    musicUI->setScale(0.5f);
    this->addChild(musicUI, 0);



    //滑动条创建
    //auto musicvolumeslider = Slider::create();
    //musicvolumeslider->loadBarTexture("UI/scroll background2.jpg"); // what the slider looks like
    //musicvolumeslider->loadSlidBallTextures("UI/scroll1.png", "UI/scroll2.png", "UI/scroll2.png");
    //musicvolumeslider->loadProgressBarTexture("UI/scroll background1.jpg");
    //musicvolumeslider->setPercent(volume2);
    //musicvolumeslider->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
    //    switch (type)
    //    {
    //    case ui::Widget::TouchEventType::BEGAN:
    //        break;
    //    case ui::Widget::TouchEventType::ENDED:
    //        volume1 = musicvolumeslider->getPercent();
    //        volume2 = static_cast<float>(volume1) / 100;
    //        AudioEngine::setVolume(backgroundMusic, volume2);
    //        /*CallFunc* callFunc = CallFunc::create(func);
    //        this->runAction(callFunc);*/
    //       /* volume1 = musicvolumeslider->getPercent();
    //        CC_CALLBACK_2(setting::onTouchMoved,this);*/
    //        break;
    //    }
    //    });

    //////musicvolumeslider->setTouchEnabled(false);
    ////
    //musicvolumeslider->setScale(1.0f);
    //musicvolumeslider->setPosition(Vec2(visibleSize.width / 2 + origin.x + 450, visibleSize.height / 2 + origin.y + 150));
    //this->addChild(musicvolumeslider);

    //

    //_listener = EventListenerTouchOneByOne::create();
    //_listener->onTouchBegan = [=](Touch* touch, Event* event) -> bool {
    //    return true;
    //};

    ////一个lambda这个用回调，还有两个暂时没用吧
    //_listener->onTouchMoved = CC_CALLBACK_2(setting::onTouchMoved, this);



    //auto volumeminus = Button::create("UI/setvolume2.png", "UI/setvolume1.png", "UI/setvolume2.png");
    //volumeminus->setPosition(Vec2(visibleSize.width / 2 + origin.x + 350, visibleSize.height / 2 + origin.y + 150));
    //volumeminus->setScale(0.5);
    //volumeminus->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
    //    if (volume1 >= 10)
    //    {
    //        volume1 -= 10;
    //        
    //        //musicvolumeslider->setPercent(volume1);
    //    }
    //    else {}
    //    //bar->setPercent(volume1);
    //    AudioEngine::setVolume(backgroundMusic, volume1);
    //    });
    //this->addChild(volumeminus);



    //auto volumeplus = Button::create("UI/setvolume2.png", "UI/setvolume1.png", "UI/setvolume2.png");
    //volumeplus->setPosition(Vec2(visibleSize.width / 2 + origin.x + 550, visibleSize.height / 2 + origin.y + 150));
    //volumeplus->setScaleX(-0.5f);
    //volumeplus->setScaleY(0.5f);
    //volumeplus->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
    //    if (volume1 <= 90)
    //    {
    //        volume1 += 10;
    //        AudioEngine::setVolume(backgroundMusic, volume1);
    //        //musicvolumeslider->setPercent(volume1);
    //    }
    //    else {}
    //    //bar->setPercent(volume1);
    //    });
    //this->addChild(volumeplus);

    


    return true;
}
void setting::menuCallback(Ref* pSender) {
    auto HelloWorld = Scene::create();
    AudioEngine::setEnabled(false);
    Director::getInstance()->replaceScene(HelloWorld::create());
}


void setting::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {
    AudioEngine::setVolume(_audioID,volume1/100);

}

void setting::musiccontrollercallback(cocos2d::Ref* pSender) 
{
    bool bSound = soundflag;
    bSound = !bSound;
    soundflag = bSound;
    if (bSound) {
        AudioEngine::resumeAll();
    }
    else {
        AudioEngine::pauseAll();
    }

}