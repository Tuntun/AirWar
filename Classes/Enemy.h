/*
 * Enemy.h
 *
 *  Created on: Jul 26, 2014
 *      Author: chengq
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#include "cocos2d.h"

USING_NS_CC;

class Enemy : public Node {
public:
	Enemy();
	virtual ~Enemy();

	virtual bool init();
	CREATE_FUNC(Enemy);

	void loseLife();

	Sprite* getSprite() { return _sprite;}
	void setSprite(Sprite* sprite) {_sprite = sprite;}
	void bindSprite(Sprite* sprie, int life);

	int getLife(){return _life;}
	void setLife(int life){_life = life;}


	float _radius;
private:
	Sprite* _sprite;
	int _life;

};

#endif /* ENEMY_H_ */
