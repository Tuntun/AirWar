/*
 * BulletLayer.cpp
 *
 *  Created on: Jul 26, 2014
 *      Author: chengq
 */

#include "BulletLayer.h"
#include "Resources.h"
#include "PlaneLayer.h"

BulletLayer::BulletLayer() {

}

BulletLayer::~BulletLayer() {

}

bool BulletLayer::init()
{
	bool bRet = false;
	do {
		CC_BREAK_IF(!Layer::init());
		bRet = true;
	} while (0);

	return bRet;
}

void BulletLayer::addBullet(float dt)
{
	// 计算发射子弹的位置
	auto plane = PlaneLayer::getInstance()->getChildByTag(Resources::TAGS::AIRPLAN);
	auto bulletPosition = Vect(plane->getPositionX(), plane->getPositionY() + plane->getContentSize().height / 2);

	auto bullet = Sprite::createWithSpriteFrameName("bullet1.png");
	bullet->setPosition(bulletPosition);
	this->addChild(bullet);
}

void BulletLayer::startShoot()
{
	// 开始发射子弹
	this->schedule(schedule_selector(BulletLayer::addBullet), 0.2f);
}

void BulletLayer::stopShoot()
{
	this->unschedule(schedule_selector(BulletLayer::addBullet));
}




