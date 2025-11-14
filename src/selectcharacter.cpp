#include "selectcharacter.h"
#include "WMJ.h"

#include "ui/CocosGUI.h"
#include<iostream>

using namespace cocos2d;

USING_NS_CC;
int bashen1 = 0;
int dashe1 = 0;
int huowu1 = 0;
int bashen2 = 0;
int dashe2 = 0;
int huowu2 = 0;

using namespace std;
using namespace ui;
cocos2d::Scene* selectcharacter::createScene()
{
    return selectcharacter::create();
}


static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool selectcharacter::init() {

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //auto backg
    auto background1 = Sprite::create("selectbackground/selectbackground-1.png");
    background1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    background1->setScaleY(1.2f);
    background1->setScaleX(-1.32f);
    this->addChild(background1, 0);
    Vector<SpriteFrame*> animFrames2;
    animFrames2.reserve(6);
    for (int i = 1; i <= 6; i++) {
        animFrames2.pushBack(SpriteFrame::create(("selectbackground/selectbackground-") + to_string(i) + ".png", Rect(0, 0, 960, 940)));
    }
    Animation* animation1 = Animation::createWithSpriteFrames(animFrames2, 0.05f);
    Animate* animate1 = Animate::create(animation1);
    background1->runAction(RepeatForever::create(animate1));


    auto buttonBaShen1 = Button::create("UI/BS1.jpg", "UI/BS2.jpg", "UI/BS3.jpg");

    //buttonBaShen->setTitleText("Button Text");
    buttonBaShen1->setPosition(Vec2(150, 560));
    buttonBaShen1->setScale(0.35f);
    buttonBaShen1->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        bashen1 = 1;
        dashe1 = 0;
        huowu1 = 0;

        });
    this->addChild(buttonBaShen1);

    auto buttonDaShe1 = Button::create("UI/DS2.jpg", "UI/DS1.jpg", "UI/DS3.jpg");

    //buttonBaShen->setTitleText("Button Text");
    buttonDaShe1->setPosition(Vec2(450, 560));
    buttonDaShe1->setScale(1.28f);
    buttonDaShe1->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        bashen1 = 0;
        dashe1 = 1;
        huowu1 = 0;
        });
    this->addChild(buttonDaShe1);

    auto buttonHuoWu1 = Button::create("UI/HW2.png", "UI/HW1.png", "UI/HW3.png");
    //buttonBaShen->setTitleText("Button Text");
    buttonHuoWu1->setPosition(Vec2(750, 560));
    buttonHuoWu1->setScale(1.25f);
    buttonHuoWu1->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        bashen1 = 0;
        dashe1 = 0;
        huowu1 = 1;
        });
    this->addChild(buttonHuoWu1);

    auto buttonBaShen2 = Button::create("UI/BS1.jpg", "UI/BS2.jpg", "UI/BS3.jpg");
    //buttonBaShen->setTitleText("Button Text");
    buttonBaShen2->setPosition(Vec2(150, 300));
    buttonBaShen2->setScale(0.35f);
    buttonBaShen2->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        bashen2 = 1;
        dashe2 = 0;
        huowu2 = 0;
        });
    this->addChild(buttonBaShen2);

    auto buttonDaShe2 = Button::create("UI/DS2.jpg", "UI/DS1.jpg", "UI/DS3.jpg");
    //buttonBaShen->setTitleText("Button Text");
    buttonDaShe2->setPosition(Vec2(450, 300));
    buttonDaShe2->setScale(1.28f);
    buttonDaShe2->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        bashen2 = 0;
        dashe2 = 1;
        huowu2 = 0;
        });

    this->addChild(buttonDaShe2);
    
    auto startItem = MenuItemImage::create("UI/startnormal.png", "UI/startselected.png", CC_CALLBACK_1(selectcharacter::menustart, this));
    startItem->setPosition(Vec2(640, 100));
    startItem->setScale(1.5f);

    auto buttonHuoWu2 = Button::create("UI/HW2.png", "UI/HW1.png", "UI/HW3.png");
    buttonHuoWu2->setPosition(Vec2(750, 300));
    buttonHuoWu2->setScale(1.25f);
    buttonHuoWu2->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        bashen2 = 0;
        dashe2 = 0;
        huowu2 = 1;
        });

    this->addChild(buttonHuoWu2);
    auto menu = Menu::create(startItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    

    return true;
}
void selectcharacter::menustart(Ref* pSender) {
    bool P1 = bashen1 || huowu1 || dashe1;
    bool P2 = bashen2 || huowu2 || dashe2;
    if(P1&&P2)
    Director::getInstance()->replaceScene(WMJ::create());
    else {
        auto label2 = Label::createWithSystemFont("you need enough characters to start the game!", "Consolas", 25);
        label2->setPosition(Vec2(600, 150));
        this->addChild(label2);
    }
}


