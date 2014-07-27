/*
 * EnemyLayer.h
 *
 *  Created on: Jul 26, 2014
 *      Author: chengq
 */

#ifndef ENEMYLAYER_H_
#define ENEMYLAYER_H_

#include "cocos2d.h"
#include "Enemy.h"

USING_NS_CC;

class EnemyLayer : public Layer {
public:
	EnemyLayer();
	virtual ~EnemyLayer();
	virtual bool init();
	CREATE_FUNC(EnemyLayer);

	void addEnemy(float dt);

	const Vector<Enemy*>& getEnemy1() const {
		return _enemy1;
	}

	const Vector<Enemy*>& getEnemy2() const {
		return _enemy2;
	}

	const Vector<Enemy*>& getEnemy3() const {
		return _enemy3;
	}

private:
	void addEnemy1(float dt);
	void addEnemy2(float dt);
	void addEnemy3(float dt);

	Vector<Enemy*> _enemy1;
	Vector<Enemy*> _enemy2;
	Vector<Enemy*> _enemy3;
};

#endif /* ENEMYLAYER_H_ */
