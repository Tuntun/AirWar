/*
 * Enemy.cpp
 *
 *  Created on: Jul 26, 2014
 *      Author: chengq
 */

#include "Enemy.h"

Enemy::Enemy() {
	_sprite = nullptr;
	_life = 0;
	_radius = 0.0f;
	// TODO Auto-generated constructor stub

}

Enemy::~Enemy() {
	_sprite->release();
	// TODO Auto-generated destructor stub
}

bool Enemy::init()
{
	bool bRet = false;
	do {
		CC_BREAK_IF(!Node::init());

		bRet = true;
	} while (0);

	return bRet;
}

void Enemy::loseLife()
{
	_life--;
	_life--;
}

void Enemy::bindSprite(Sprite* sprie, int life) {
		_sprite = sprie;
		_life = life;
		this->addChild(_sprite);
}

