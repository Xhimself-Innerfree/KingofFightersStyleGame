#include "Hero2.h"
using namespace std;
Hero2::Hero2() {
	theSprite = NULL;
	listenerKey = NULL;
}

Hero2::Hero2(const Hero2& p) {
	theSprite = p.theSprite;
	listenerKey = p.listenerKey;
}

Hero2::~Hero2() {
}

void Hero2::startMovie()
{
	Vector<SpriteFrame*> animFrames1;
	animFrames1.reserve(70);
	for (int i = 1; i <= 70; i++) {
		animFrames1.pushBack(SpriteFrame::create(("bigsnake start/bigsnake start-") + to_string(i) + ".png", Rect(0, 0, 150, 270)));
	}
	Animation* animation2 = Animation::createWithSpriteFrames(animFrames1, 0.05f);
	Animate* animate2 = Animate::create(animation2);
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(27);
	for (int i = 1; i <= 27; i++) {
		animFrames.pushBack(SpriteFrame::create(("bigsnake stand/bigsnake stand-") + to_string(i) + ".png", Rect(0, 0, 100, 160)));
	}

	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animateBack = Animate::create(animation);
	auto seqq = Sequence::create(Repeat::create(animate2, 1), RepeatForever::create(animateBack), nullptr);
	theSprite->runAction(seqq);
}

void Hero2::moveLeft()
{
	auto moveBy = MoveBy::create(18, Vec2(2000, 0));
	theSprite->runAction(moveBy);
}

void Hero2::moveRight()
{
	auto moveBy = MoveBy::create(18, Vec2(-2000, 0));
	theSprite->runAction(moveBy);
}



void Hero2::stopEveryAction()
{
	theSprite->stopAllActions();
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(27);
	theSprite->setPositionY(-30);
	for (int i = 1; i <= 27; i++) {
		animFrames.pushBack(SpriteFrame::create(("bigsnake stand/bigsnake stand-") + to_string(i) + ".png", Rect(0, 0, 100, 160)));
	}

	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animateBack = Animate::create(animation);
	theSprite->runAction(RepeatForever::create(animateBack));
}

void Hero2::aclench()
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
	for (int i = 1; i <= 20; i++) { animFramesClench.pushBack(SpriteFrame::create("bigsnake skill1/bigsnake skill1-" + to_string(i) + ".png", Rect(-12, -22, 160, 267))); }
	Animation* animation = Animation::createWithSpriteFrames(animFramesClench, 0.1f);//È­Í·¹¥»÷
	Animate* animateBack1 = Animate::create(animation);
	theSprite->stopAllActions();
	auto seq11 = Sequence::create(callBack1, Repeat::create(animateBack1, 1), callBack2, nullptr);
	theSprite->runAction(seq11);
}

void Hero2::standBy()
{
}

void Hero2::defence()
{


}