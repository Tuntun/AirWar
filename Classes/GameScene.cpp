#include "GameScene.h"

USING_NS_CC;

GameScene::GameScene()
{
	_gameLayer = nullptr;
}

GameScene::~GameScene()
{

}

// on "init" you need to initialize your instance
bool GameScene::init() {
	bool bRet = false;
	do {
		//////////////////////////////
		// 1. super init first
		CC_BREAK_IF(!Scene::init());
		_gameLayer = GameLayer::create();
		CC_BREAK_IF(!_gameLayer);
		this->addChild (_gameLayer);
		bRet = true;
	} while (0);

	return bRet;
}
