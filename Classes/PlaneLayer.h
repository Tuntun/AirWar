/*
 * PlaneLayer.h
 *
 *  Created on: Jul 25, 2014
 *      Author: chengq
 */

#ifndef PLANELAYER_H_
#define PLANELAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class PlaneLayer: public cocos2d::Layer {
public:
	PlaneLayer();
	virtual ~PlaneLayer();

	virtual bool init();
	CREATE_FUNC(PlaneLayer);

	static PlaneLayer* getInstance();
	static PlaneLayer* _planeLayer;

	bool isAlive() {
		return _alive;
	}
	void setAlive(bool alive) {
		_alive = alive;
	}

	int getSorce() {
		return _sorce;
	}
	;
	void setSorce(int sorce) {
		_sorce += sorce;
	}


private:

	bool _alive;
	int _sorce;


};

#endif /* PLANELAYER_H_ */
