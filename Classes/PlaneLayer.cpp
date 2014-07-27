/*
 * PlaneLayer.cpp
 *
 *  Created on: Jul 25, 2014
 *      Author: chengq
 */

#include "PlaneLayer.h"
#include "Resources.h"

PlaneLayer* PlaneLayer::_planeLayer = nullptr;

PlaneLayer* PlaneLayer::getInstance()
{
	if (nullptr == _planeLayer) {
		_planeLayer = PlaneLayer::create();
	}

	return _planeLayer;
}

PlaneLayer::PlaneLayer() {
	// TODO Auto-generated constructor stub
	_alive = false;
	_sorce = 0;
}

PlaneLayer::~PlaneLayer() {
	// TODO Auto-generated destructor stub
}

bool PlaneLayer::init() {
	bool bRet = false;

	do {
		CC_BREAK_IF(!Layer::init());

		auto winSize = Director::getInstance()->getWinSize();

		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot.plist");

		auto plane = Sprite::createWithSpriteFrameName("hero1.png");
		plane->setPosition(winSize.width / 2, plane->getContentSize().height / 2);
		this->addChild(plane, 0, Resources::TAGS::AIRPLAN);
		setAlive(true);

		auto blink = Blink::create(1.5, 4);

		auto animation = Animation::create();
		animation->setDelayPerUnit(0.1f);
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero1.png"));
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero2.png"));
		auto animate = Animate::create(animation);

		plane->runAction(blink);
		plane->runAction(RepeatForever::create(animate));

		bRet = true;
	} while (0);

	return bRet;
}
