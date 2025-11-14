#include "Hero.h"
using namespace std;


Hero::Hero() {
	theSprite = NULL;
	listenerKey = NULL;
}


Hero::Hero(const Hero& p) {
	theSprite = p.theSprite;
	listenerKey = p.listenerKey;
}

Hero::~Hero() {
}


void Hero::startMovie() {
	auto callBackFunc1 = [&]() {
		listenerKey->setEnabled(false);
	};
	CallFunc* callBack1 = CallFunc::create(callBackFunc1);
	auto callBackFunc2 = [&]() {
		listenerKey->setEnabled(true);
	};
	CallFunc* callBack2 = CallFunc::create(callBackFunc2);
	Vector<SpriteFrame*> animFramesBegin;
	animFramesBegin.reserve(12);
	for (int i = 1; i <= 12; i++) { animFramesBegin.pushBack(SpriteFrame::create("theBeginning" + to_string(i) + ".png", Rect(-20, 10, 150, 140))); }
	Animation* animationBeginning = Animation::createWithSpriteFrames(animFramesBegin, 0.1f);
	Animate* animateBeginning = Animate::create(animationBeginning);
	Vector<SpriteFrame*> animFramesStand;
	animFramesStand.reserve(9);
	for (int i = 1; i <= 9; i++) { animFramesStand.pushBack(SpriteFrame::create("standingBy" + to_string(i) + ".png", Rect(-0, 0, 95, 127))); }
	Animation* animationStand = Animation::createWithSpriteFrames(animFramesStand, 0.1f);
	Animate* animateStand = Animate::create(animationStand);
	auto seq = Sequence::create(callBack1, Repeat::create(animateBeginning, 1), callBack2, Repeat::create(animateStand, 10), nullptr);
	theSprite->runAction(seq);

}

void Hero::moveLeft() {
	theSprite->stopAllActions();
	auto moveBy = MoveBy::create(18, Vec2(-2000, 0));
	theSprite->runAction(moveBy);
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(9);
	for (int i = 1; i <= 9; i++) { animFrames.pushBack(SpriteFrame::create("stepback" + to_string(i) + ".png", Rect(0, 0, 70, 137))); }
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animateBack = Animate::create(animation);
	theSprite->runAction(RepeatForever::create(animateBack));
}

void Hero::moveRight() {
	theSprite->stopAllActions();
	auto moveBy = MoveBy::create(18, Vec2(2000, 0));
	theSprite->runAction(moveBy);
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(10);
	for (int i = 1; i <= 10; i++) { animFrames.pushBack(SpriteFrame::create("stepForward" + to_string(i) + ".png", Rect(0, 0, 100, 137))); }
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animateBack = Animate::create(animation);
	theSprite->runAction(RepeatForever::create(animateBack));
}

void Hero::stopEveryAction() {
	theSprite->stopAllActions();
}

void Hero::aclench()
{
	theSprite->stopAllActions();
	auto callBackFunc1 = [&]() {
		listenerKey->setEnabled(false);
	};
	CallFunc* callBack1 = CallFunc::create(callBackFunc1);
	auto callBackFunc2 = [&]() {
		listenerKey->setEnabled(true);
	};
	CallFunc* callBack2 = CallFunc::create(callBackFunc2);
	Vector<SpriteFrame*> animFramesClench;
	animFramesClench.reserve(5);
	for (int i = 1; i <= 5; i++) { animFramesClench.pushBack(SpriteFrame::create("aclench" + to_string(i) + ".png", Rect(-12, 5, 160, 137))); }
	Animation* animation = Animation::createWithSpriteFrames(animFramesClench, 0.1f);//È­Í·¹¥»÷
	Animate* animateBack1 = Animate::create(animation);
	theSprite->stopAllActions();
	auto seq11 = Sequence::create(callBack1, Repeat::create(animateBack1, 1), callBack2, nullptr);
	theSprite->runAction(seq11);
}

void Hero::standBy()
{
	theSprite->stopAllActions();
	Vector<SpriteFrame*> animFramesStand;
	animFramesStand.reserve(9);
	for (int i = 1; i <= 9; i++) { animFramesStand.pushBack(SpriteFrame::create("standingBy" + to_string(i) + ".png", Rect(-0, 0, 95, 127))); }
	Animation* animationStand1 = Animation::createWithSpriteFrames(animFramesStand, 0.1f);
	Animate* animateBack = Animate::create(animationStand1);
	theSprite->runAction(RepeatForever::create(animateBack));
}

void Hero::defence()
{
	theSprite->stopAllActions();
	Vector<SpriteFrame*> animFramesStand;
	animFramesStand.reserve(9);
	for (int i = 1; i <= 9; i++) { animFramesStand.pushBack(SpriteFrame::create("standingBy" + to_string(i) + ".png", Rect(-0, 0, 95, 127))); }
	Animation* animationStand1 = Animation::createWithSpriteFrames(animFramesStand, 0.1f);
	Animate* animateBack = Animate::create(animationStand1);
	theSprite->runAction(RepeatForever::create(animateBack));


}