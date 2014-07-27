/*
 * EnemyLayer.cpp
 *
 *  Created on: Jul 26, 2014
 *      Author: chengq
 */

#include "EnemyLayer.h"
#include "Enemy.h"

EnemyLayer::EnemyLayer()
{

}

EnemyLayer::~EnemyLayer() {
	_enemy1.clear();
	_enemy2.clear();
	_enemy3.clear();
}

bool EnemyLayer::init()
{
	bool bRet = false;
	do {
		CC_BREAK_IF(!Layer::init());
		this->schedule(schedule_selector(EnemyLayer::addEnemy), 0.2);
		bRet = true;
	} while (0);

	return bRet;
}

void EnemyLayer::addEnemy(float dt) {
	int actual = (rand() % 9) + 1;

	if (actual <= 6) {
		addEnemy1(dt);
	} else if (actual < 9 ) {
		addEnemy2(dt);
	} else {
		addEnemy3(dt);
	}
}

void EnemyLayer::addEnemy1(float dt) {
	auto enemy = Enemy::create();
	enemy->bindSprite(Sprite::createWithSpriteFrameName("enemy1.png"), 1);
	auto size = enemy->getSprite()->getContentSize();
	enemy->setContentSize(size);
	auto winSize = Director::getInstance()->getWinSize();

	int minX = size.width / 2;
	int maxX = winSize.width - size.width / 2;
	int rangeX = maxX - minX;
	int actualX = (rand() % rangeX) + minX;


	enemy->setPosition(actualX, winSize.height + size.height / 2);
	this->addChild(enemy);
	_enemy1.pushBack(enemy);
	enemy->retain();

	auto moveAction = MoveTo::create(2, Vect(actualX, -size.height / 2));
	auto moveDoneAction =  CallFuncN::create([this](Node* node) {
		this->removeChild(node, true);
		this->_enemy1.eraseObject((Enemy*)node);
	});

	enemy->runAction(Sequence::create(moveAction, moveDoneAction, nullptr));
}

void EnemyLayer::addEnemy2(float dt) {
	auto enemy = Enemy::create();
	enemy->bindSprite(Sprite::createWithSpriteFrameName("enemy2.png"), 2);
	auto size = enemy->getSprite()->getContentSize();
	enemy->setContentSize(size);
	auto winSize = Director::getInstance()->getWinSize();

	int minX = size.width / 2;
	int maxX = winSize.width - size.width / 2;
	int rangeX = maxX - minX;
	int actualX = (rand() % rangeX) + minX;


	enemy->setPosition(actualX, winSize.height + size.height / 2);
	this->addChild(enemy);
	_enemy2.pushBack(enemy);
	enemy->retain();

	auto moveAction = MoveTo::create(3, Vect(actualX, -size.height / 2));
	auto moveDoneAction =  CallFuncN::create([this](Node* node) {
		this->removeChild(node, true);
		this->_enemy2.eraseObject((Enemy*)node);
	});

	enemy->runAction(Sequence::create(moveAction, moveDoneAction, nullptr));
}

void EnemyLayer::addEnemy3(float dt) {
	auto enemy = Enemy::create();
	enemy->bindSprite(Sprite::createWithSpriteFrameName("enemy3_n1.png"), 3);
	auto size = enemy->getSprite()->getContentSize();
	enemy->setContentSize(size);
	auto winSize = Director::getInstance()->getWinSize();

	int minX = size.width / 2;
	int maxX = winSize.width - size.width / 2;
	int rangeX = maxX - minX;
	int actualX = (rand() % rangeX) + minX;


	enemy->setPosition(actualX, winSize.height + size.height / 2);
	this->addChild(enemy);
	_enemy3.pushBack(enemy);
	enemy->retain();

	auto moveAction = MoveTo::create(4, Vect(actualX, -size.height / 2));
	auto moveDoneAction =  CallFuncN::create([this](Node* node) {
		this->removeChild(node, true);
		this->_enemy3.eraseObject((Enemy*)node);
	});

	enemy->runAction(Sequence::create(moveAction, moveDoneAction, nullptr));

	// 帧动画
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.2f);
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_n1.png"));
	animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_n2.png"));
	auto animate = Animate::create(animation);
	enemy->getSprite()->runAction(RepeatForever::create(animate));
}


