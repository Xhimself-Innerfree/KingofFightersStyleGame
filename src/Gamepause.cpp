#include "Gamepause.h"
cocos2d::Scene* Gamepause::createScene()
{
    return Gamepause::create();
}

bool Gamepause::init() {

	auto background2 = Sprite::create("UI/systemMenuBox.png");
	auto resume = Button::create("UI/continue.png");
	auto playagain = Button::create("UI/replay.png");
	auto exit = Button::create("UI/exit.png");
	background2->setPosition(Vec2(640, 360));
	resume->setPosition(Vec2(590, 350));
	playagain->setPosition(Vec2(630, 350));
	exit->setPosition(Vec2(670, 350));
	this->addChild(background2);
	this->addChild(resume);
	this->addChild(playagain);
	this->addChild(exit);
	resume->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
		Director::getInstance()->popScene();
		});
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