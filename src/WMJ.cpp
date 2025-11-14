#include"WMJ.h"
#include<iostream>
#include<ctime>
#include"a.h"
#include"selectcharacter.h"
#include"GameOver.h"
#include"HelloWorldScene.h"
using namespace std;
USING_NS_CC;
bool P1win = false;
bool P2win = false;
static bool pausestate = false;
Scene* WMJ::createScene() {
	auto scene = Scene::create();
	auto layer = WMJ::create();
	scene->addChild(layer);
	return scene;
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool WMJ::init() {
	//Director::getInstance()->resume();
	AudioEngine::setEnabled(soundflag);
	//BGM
	auto backgroundmusic = AudioEngine::play2d("music/Esaka_battle.mp3", true);
	AudioEngine::setVolume(backgroundmusic,0.5f);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	this->removeAllChildren();
	//背景
	auto background1 = Sprite::create("background1/background1-1.png");
	background1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	background1->setScaleY(2.6f);
	background1->setScaleX(2.0f);
	this->addChild(background1, 0);
	Vector<SpriteFrame*> animFrames2;
	animFrames2.reserve(4);
	for (int i = 1; i <= 4; i++) {
		animFrames2.pushBack(SpriteFrame::create(("background1/background1-") + to_string(i) + ".png", Rect(0, 0, 900, 275)));
	}
	Animation* animation1 = Animation::createWithSpriteFrames(animFrames2, 0.05f);
	Animate* animate1 = Animate::create(animation1);
	background1->runAction(RepeatForever::create(animate1));

	//血条(P2)
	auto sp = Sprite::create("bloodbar.png");
	auto progress = ProgressTimer::create(sp);
	progress->setPosition(Vec2(1090, 610));
	progress->setType(ProgressTimer::Type::BAR);
	progress->setMidpoint(Vec2(0, 0));
	progress->setBarChangeRate(Vec2(1, 0));
	progress->setPercentage(0);
	this->addChild(progress, 1, 10);
	schedule(CC_CALLBACK_1(WMJ::updateProgress, this), 0.1f,"progress");

	//血条(P1)
	auto sp2 = Sprite::create("bloodbar.png");
	auto progress2 = ProgressTimer::create(sp2);
	progress2->setPosition(Vec2(170, 610));
	progress2->setType(ProgressTimer::Type::BAR);
	progress2->setMidpoint(Vec2(0, 0));
	progress2->setBarChangeRate(Vec2(1, 0));
	progress2->setPercentage(0);
	this->addChild(progress2, 1, 11);
	schedule(CC_CALLBACK_1(WMJ::updateProgress2, this), 0.1f, "progress2");

	


	//暂停按钮
	auto buttonpause = Button::create("UI/pause.png");
	buttonpause->setPosition(Vec2(1150, 700));
	this->addChild(buttonpause,7);
	buttonpause->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
		auto Gamepause = Scene::create();
		
		Director::getInstance()->pushScene(Gamepause::create());

		});
	this->schedule(CC_SCHEDULE_SELECTOR(WMJ::update), 0.1);



	//player1创建
	Hero* test1 = new Hero;
	test1->setPosition(Vec2(visibleSize.width / 2 + origin.x - 200, visibleSize.height / 2 + origin.y - 180));
	test1->setScale(2.0);
	test1->bindSprite(Sprite::create("aclench3.png"));
	auto listenerKey = EventListenerKeyboard::create();
	test1->bindListener(listenerKey);
	if (bashen1 == 1) {
		this->addChild(test1);
		test1->startMovie();
	}
	else if (bashen2 == 1) {
		test1->setPosition(Vec2(visibleSize.width / 2 + origin.x + 300, visibleSize.height / 2 + origin.y - 180));
		test1->setScaleX(-2);
		this->addChild(test1);
		test1->startMovie();
	}
	else if (bashen1 == 0 || bashen2 == 0)
	{
		this->removeChild(test1);
	}

	//player2创建
	auto listenerKey2 = EventListenerKeyboard::create();
	Hero2* test2 = new Hero2;
	test2->bindSprite(Sprite::create("bigsnake start/bigsnake start-1.png"));
	test2->bindListener(listenerKey2);
	if (dashe2 == 1) {
		test2->setPosition(Vec2(visibleSize.width / 2 + origin.x + 300, visibleSize.height / 2 - 80));//原基础上-30
		test2->setScale(2.0);
		test2->setScaleX(-2);
		this->addChild(test2);
		test2->startMovie();
	}
	else if (dashe1 == 1) {
		test2->setPosition(Vec2(visibleSize.width / 2 + origin.x - 300, visibleSize.height / 2 - 80));
		test2->setScale(2.0);
		this->addChild(test2);
		test2->startMovie();
	}
	else if (dashe1 == 0 || dashe2 == 0) {
		this->removeChild(test2);
	}

	//playerC创建
	HeroC* testC = new HeroC;
	testC->setScale(2.0);
	testC->bindSpriteC(Sprite::create("cstanding/cStading-1.png"));
	auto listenerKeyC = EventListenerKeyboard::create();
	testC->bindListenerC(listenerKeyC);
	if (huowu1 == 1) {
		testC->setPosition(Vec2(visibleSize.width / 2 + origin.x - 300, visibleSize.height / 2 - 200));
		this->addChild(testC);
		testC->standByC();
	}
	else if (huowu2 == 1) {
		testC->setPosition(Vec2(visibleSize.width / 2 + origin.x + 300, visibleSize.height / 2 - 200));//原基础上-30
		testC->setScaleX(-2);
		this->addChild(testC);
		testC->standByC();
	}
	else if (huowu1 == 0 || huowu2 == 0) {
		this->removeChild(testC);
	}
	
	//键盘操控环节
	//八神庵键盘监听
	listenerKey->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keyCode == EventKeyboard::KeyCode::KEY_2 && bashen2 == 1) test1->moveLeft();
		if (keyCode == EventKeyboard::KeyCode::KEY_1 && bashen2 == 1) test1->moveRight();
		if (keyCode == EventKeyboard::KeyCode::KEY_D && bashen1 == 1) test1->moveRight();
		if (keyCode == EventKeyboard::KeyCode::KEY_A && bashen1 == 1)test1->moveLeft();
		if (keyCode == EventKeyboard::KeyCode::KEY_J && bashen1 == 1) {
			Rect aaa = test1->getBounding();
			bool ab = 0, ac = 0;
			if (dashe2 == 1) { Rect bbb = test2->getBounding(); ab = aaa.intersectsRect(bbb); }
			if (huowu2 == 1) { Rect ccc = testC->getBounding(); ac = aaa.intersectsRect(ccc); }
			if (ac || ab) { Percentage -= 10; }
			
			test1->aclench();
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_3 && bashen2 == 1) {
			Rect aaa = test1->getBounding();
			bool ab = 0, ac = 0;
			if (dashe1 == 1) { Rect bbb = test2->getBounding(); ab = aaa.intersectsRect(bbb); }
			if (huowu1 == 1) { Rect ccc = testC->getBounding(); ac = aaa.intersectsRect(ccc); }
			if (ac || ab) { Percentage2 -= 10; }
			
			test1->aclench();
		}
	};

	listenerKey->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		if ((keyCode == EventKeyboard::KeyCode::KEY_1 || keyCode == EventKeyboard::KeyCode::KEY_2) && bashen2 == 1) {
			test1->stopEveryAction();
			test1->standBy();
		}
		if ((keyCode == EventKeyboard::KeyCode::KEY_A || keyCode == EventKeyboard::KeyCode::KEY_D) && bashen1 == 1) {
			test1->stopEveryAction();
			test1->standBy();
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKey, this);
	
	//大蛇键盘监听
	listenerKey2->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keyCode == EventKeyboard::KeyCode::KEY_1 && dashe2 == 1) test2->moveLeft();
		if (keyCode == EventKeyboard::KeyCode::KEY_2 && dashe2 == 1) test2->moveRight();
		if (keyCode == EventKeyboard::KeyCode::KEY_D && dashe1 == 1) test2->moveLeft();
		if (keyCode == EventKeyboard::KeyCode::KEY_A && dashe1 == 1) test2->moveRight();
		if (keyCode == EventKeyboard::KeyCode::KEY_J && dashe1 == 1) {
			Rect bbb = test2->getBounding();
			bool ba = 0, bc = 0;
			if (huowu2 == 1) { Rect ccc = testC->getBounding(); bc = bbb.intersectsRect(ccc); }//
			if (bashen2 == 1) { Rect aaa = test1->getBounding(); ba = bbb.intersectsRect(aaa); }//
			if (bc || ba) { Percentage -= 10; }
			
			test2->aclench();
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_3 && dashe2 == 1) {
			Rect bbb = test2->getBounding();
			bool ba = 0, bc = 0;
			if (huowu1 == 1) { Rect ccc = testC->getBounding(); bc = bbb.intersectsRect(ccc); }//
			if (bashen1 == 1) { Rect aaa = test1->getBounding(); ba = bbb.intersectsRect(aaa); }//
			if (ba || bc) { Percentage2 -= 10; }
			
			test2->aclench();
		}

	};
	listenerKey2->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		if ((keyCode == EventKeyboard::KeyCode::KEY_1 || keyCode == EventKeyboard::KeyCode::KEY_2) && dashe2 == 1) {
			test2->stopEveryAction();

		}
		if ((keyCode == EventKeyboard::KeyCode::KEY_A || keyCode == EventKeyboard::KeyCode::KEY_D) && dashe1 == 1) {
			test2->stopEveryAction();

		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKey2, this);

	//不知火舞键盘监听
	listenerKeyC->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keyCode == EventKeyboard::KeyCode::KEY_1 && huowu2 == 1) testC->moveLeftC();
		if (keyCode == EventKeyboard::KeyCode::KEY_2 && huowu2 == 1) testC->moveRightC();
		if (keyCode == EventKeyboard::KeyCode::KEY_D && huowu1 == 1) testC->moveLeftC();
		if (keyCode == EventKeyboard::KeyCode::KEY_A && huowu1 == 1)testC->moveRightC();
		if (keyCode == EventKeyboard::KeyCode::KEY_J && huowu1 == 1) {
			Rect ccc = testC->getBounding();
			bool cb = 0, ca = 0;
			if (dashe2 == 1) { Point bbb = test2->getSpritePosition() + Vec2(135.5, -55.5); cb = ccc.containsPoint(bbb); }//
			if (bashen2 == 1) { Point aaa = test1->getSpritePosition() + Vec2(70, -55.5); ca = ccc.containsPoint(aaa); }//
			if (cb || ca) { Percentage -= 10; 
			}
			
			testC->aclenchC();
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_3 && huowu2 == 1) {
			Rect ccc = testC->getBounding();
			bool cb = 0, ca = 0;
			if (dashe1 == 1) { Point bbb = test2->getSpritePosition(); cb = ccc.containsPoint(bbb); }//
			if (bashen1 == 1) { Point aaa = test1->getSpritePosition(); ca = ccc.containsPoint(aaa); }//
			if (cb || ca) { Percentage2 -= 10; }
			
			testC->aclenchC();
		}

	};
	listenerKeyC->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		if ((keyCode == EventKeyboard::KeyCode::KEY_1 || keyCode == EventKeyboard::KeyCode::KEY_2) && huowu2 == 1) {
			testC->stopEveryActionC();
			testC->standByC();
		}
		if ((keyCode == EventKeyboard::KeyCode::KEY_A || keyCode == EventKeyboard::KeyCode::KEY_D) && huowu1 == 1) {
			testC->stopEveryActionC();
			testC->standByC();
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyC, this);


	return true;
}
//此处为血条的增减
void WMJ::updateProgress(float)
{
	auto progress = (ProgressTimer*)this->getChildByTag(10);
	if (Percentage <= 100)progress->setPercentage(Percentage);
}

void WMJ::updateProgress2(float)
{
	auto progress2 = (ProgressTimer*)this->getChildByTag(11);
	if (Percentage2 <= 100)progress2->setPercentage(Percentage2);
}

void WMJ::update(float dt)
{
	if (Percentage<= 0 || Percentage2 <= 0)
	{
		if (Percentage2 <= 0)
			P2win = true;
		if (Percentage <= 0)
			P1win = true;//为胜利判定传参数

		Scene* scene = Scene::create();
		scene->addChild(GameOver::create());
		AudioEngine::setEnabled(false);
		Director::getInstance()->replaceScene(GameOver::create());
	}
	
}

