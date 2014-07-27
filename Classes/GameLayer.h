#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"

#include "PlaneLayer.h"
#include "BulletLayer.h"
#include "EnemyLayer.h"

USING_NS_CC;

class GameLayer : public cocos2d::Layer
{
public:

	GameLayer();
	~GameLayer();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void move(float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameLayer);

    virtual void update(float dt) override;

private:
    Sprite* _bg1;
    Sprite* _bg2;

    PlaneLayer* _planeLayer;
    BulletLayer* _bulletLayer;
    EnemyLayer* _enemyLayer;
};

#endif // __GAME_LAYER_H__
