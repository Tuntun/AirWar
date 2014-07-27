#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameLayer.h"

class GameScene : public cocos2d::Scene
{
public:
	GameScene();
	~GameScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

    GameLayer*_gameLayer;
};

#endif // __GAME_SCENE_H__
