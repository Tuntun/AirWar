/*
 * BulletLayer.h
 *
 *  Created on: Jul 26, 2014
 *      Author: chengq
 */

#ifndef BULLETLAYER_H_
#define BULLETLAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class BulletLayer : public Layer {
public:
	BulletLayer();
	virtual ~BulletLayer();

	virtual bool init();
	CREATE_FUNC(BulletLayer);

	void addBullet(float dt);
	void startShoot();
	void stopShoot();
	void removeBullet(Sprite*);
};

#endif /* BULLETLAYER_H_ */
