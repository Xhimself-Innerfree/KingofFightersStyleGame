#include "HeroC.h"
using namespace std;
HeroC::HeroC() {
	theSpriteC = NULL;
}

HeroC::HeroC(const HeroC& p) {
	theSpriteC = p.theSpriteC;
}

HeroC::~HeroC() {
}

Sprite* HeroC::getSpriteC() {
	return this->theSpriteC;
}

void HeroC::bindSpriteC(Sprite* sprite)
{
	theSpriteC = sprite;
	return this->addChild(theSpriteC, 3);
}

EventListener* HeroC::getEventListenerC()
{
	return listenerKeyC;
}

void HeroC::bindListenerC(EventListener* listenerKey)
{
	listenerKeyC = listenerKey;
}

void HeroC::startMovieC()
{

}

void HeroC::moveLeftC()
{
	//forward

	theSpriteC->stopAllActions();
	auto moveBy = MoveBy::create(18, Vec2(2000, 0));
	theSpriteC->runAction(moveBy);

	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(6);
	for (int i = 1; i <= 6; i++) { animFrames.pushBack(SpriteFrame::create("cstepforward/cstepforward-" + to_string(i) + ".png", Rect(0, 5, 100, 110))); }
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animateBack = Animate::create(animation);

	theSpriteC->runAction(RepeatForever::create(animateBack));
}

void HeroC::moveRightC()
{
	theSpriteC->stopAllActions();
	auto moveBy = MoveBy::create(18, Vec2(-2000, 0));
	theSpriteC->runAction(moveBy);
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(6);
	for (int i = 1; i <= 6; i++) { animFrames.pushBack(SpriteFrame::create("cstepback/cstepback-" + to_string(i) + ".png", Rect(0, 5, 100, 110))); }
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animateBack = Animate::create(animation);
	theSpriteC->runAction(RepeatForever::create(animateBack));
}

void HeroC::stopEveryActionC()
{
	theSpriteC->stopAllActions();
}

void HeroC::aclenchC()
{
}

void HeroC::standByC()
{
	Vector<SpriteFrame*> animFramesBegin;
	animFramesBegin.reserve(18);
	for (int i = 1; i <= 18; i++) { animFramesBegin.pushBack(SpriteFrame::create("cstanding/cStading-" + to_string(i) + ".png", Rect(0, 3, 90, 111))); }
	Animation* animationBeginning = Animation::createWithSpriteFrames(animFramesBegin, 0.1f);
	Animate* animateBeginning = Animate::create(animationBeginning);
	theSpriteC->runAction(RepeatForever::create(animateBeginning));
}

void HeroC::jumpUpC()
{
}

int HeroC::getPositionXXC()
{
	return 0;
}

void HeroC::attackC()
{
	theSpriteC->stopAllActions();
	auto callBackFunc1 = [&]() {
		listenerKeyC->setEnabled(false);
	};
	CallFunc* callBack1 = CallFunc::create(callBackFunc1);
	auto callBackFunc2 = [&]() {
		listenerKeyC->setEnabled(true);
	};
	CallFunc* callBack2 = CallFunc::create(callBackFunc2);
	Vector<SpriteFrame*> animFramesBegin;
	animFramesBegin.reserve(20);
	for (int i = 1; i <= 20; i++) { animFramesBegin.pushBack(SpriteFrame::create("cattack/cattack-" + to_string(i) + ".png", Rect(20, -15, 190, 350))); }
	Animation* animationBeginning = Animation::createWithSpriteFrames(animFramesBegin, 0.1f);
	Animate* animateBeginning = Animate::create(animationBeginning);
	theSpriteC->stopAllActions();
	auto seq11 = Sequence::create(callBack1, Repeat::create(animateBeginning, 1), callBack2, nullptr);
	theSpriteC->runAction(seq11);
}

Rect HeroC::getBounding()
{
	return theSpriteC->getBoundingBox();
}

Point HeroC::getSpritePosition()
{
	return theSpriteC->getPosition();
}
