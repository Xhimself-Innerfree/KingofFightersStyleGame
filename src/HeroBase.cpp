#include"HeroBase.h"
using namespace std;


HeroBase::HeroBase() {
	theSprite = NULL;
	listenerKey = NULL;
}

HeroBase::HeroBase(const HeroBase& p) {
	theSprite = p.theSprite;
	listenerKey = p.listenerKey;
}

HeroBase::~HeroBase() {
}

Sprite* HeroBase::getSprite() {
	return this->theSprite;
}

void HeroBase::bindSprite(Sprite* sprite) {
	theSprite = sprite;
	return this->addChild(theSprite, 3);
}

EventListener* HeroBase::getEventListener()
{
	return this->listenerKey;
}

void HeroBase::bindListener(EventListener* ggg)
{
	listenerKey = ggg;
}

Rect HeroBase::getBounding()
{
	return theSprite->getBoundingBox();
}

Point HeroBase::getSpritePosition()
{
	return theSprite->getPosition();
}