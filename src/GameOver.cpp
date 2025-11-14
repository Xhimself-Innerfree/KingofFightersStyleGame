#include "GameOver.h"
#include"selectcharacter.h"
#include "a.h"
#include"HelloWorldScene.h"
using namespace std;
Scene* GameOver::scene()
{
    Scene* scene = Scene::create();
    GameOver* gameOver = GameOver::create();
    scene->addChild(gameOver);
    return  scene;

}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool GameOver::init() {
    if (!Scene::init()) {
        return false;
    }

    Size winSize = Director::getInstance()->getWinSize();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();



    auto logo = Sprite::create("UI/win.png");
    logo->setPosition(winSize / 2);
    this->addChild(logo);



    auto P1sprite = Sprite::create("UI/1P.png");
    P1sprite->setPosition(winSize / 2);
    if (P1win==true) {
        this->addChild(P1sprite);
    }
    else{
        this->removeChild(P1sprite);
    }
    auto P2sprite = Sprite::create("UI/2P.png");
    P2sprite->setPosition(winSize / 2);
    
    if (P2win==true) {
        this->addChild(P2sprite);
    }
    else {
        this->removeChild(P2sprite);
    }

    
    auto playagain = Button::create("UI/replay.png");
    auto exit = Button::create("UI/exit.png");
    playagain->setPosition(Vec2(520, 100));
    exit->setPosition(Vec2(740, 100));
    playagain->setScale(3.0f);
    exit->setScale(2.5f);
    this->addChild(playagain);
    this->addChild(exit);
    
    
    playagain->setVisible(true);
    exit->setVisible(true);
   
    exit->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        auto HelloWorldScene = Scene::create();
        Director::getInstance()->replaceScene(HelloWorld::create());
        });
    playagain->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        auto selectcharacter = Scene::create();
        Director::getInstance()->replaceScene(selectcharacter::create());
        });



  
    return true;
}


