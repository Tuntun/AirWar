#include "GameLayer.h"
#include "Resources.h"


GameLayer::GameLayer() {
	_bg1 = nullptr;
	_bg2 = nullptr;
	_planeLayer = nullptr;
	_bulletLayer = nullptr;
	_enemyLayer = nullptr;
}

GameLayer::~GameLayer()
{
	this->unscheduleUpdate();
}

// on "init" you need to initialize your instance
bool GameLayer::init() {
	bool bRet = false;
	do {
		//////////////////////////////
		// 1. super init first
		CC_BREAK_IF(!Layer::init());

		// 载入精灵帧缓存(背景图片)
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui.plist");

		_bg1 = Sprite::createWithSpriteFrameName("background.png");
		_bg1->setAnchorPoint(Vect(0, 0));
		_bg1->setPosition(Vect(0, 0));
		this->addChild(_bg1);

		_bg2 = Sprite::createWithSpriteFrameName("background.png");
		_bg2->setAnchorPoint(Vect(0, 0));
		_bg2->setPosition(Vect(0, _bg1->getContentSize().height - 2));
		this->addChild(_bg2);

		this->schedule(schedule_selector(GameLayer::move), 0.01f);
		this->scheduleUpdate();

		// 创建飞机
		_planeLayer = PlaneLayer::getInstance();
		this->addChild(_planeLayer);

		// 加入子弹层
		_bulletLayer = BulletLayer::create();
		this->addChild(_bulletLayer);
		_bulletLayer->startShoot();

		// 加入敌机层
		_enemyLayer = EnemyLayer::create();
		this->addChild(_enemyLayer);

		// 添加触摸
		auto touchListener = EventListenerTouchOneByOne::create();
		touchListener->setSwallowTouches(true);
		touchListener->onTouchBegan = [](Touch* touch, Event* event) {
			return true;
		};
		touchListener->onTouchMoved = [this](Touch* touch, Event* event){
			if (PlaneLayer::getInstance()->isAlive()) {
				auto plane = PlaneLayer::getInstance()->getChildByTag(Resources::TAGS::AIRPLAN);
				auto newPosition = plane->getPosition() + touch->getLocation() - touch->getPreviousLocation();

				if (newPosition.y < plane->getContentSize().height / 2) {
					newPosition.y = plane->getContentSize().height / 2;
				} else if (newPosition.y > Director::getInstance()->getWinSize().height - plane->getContentSize().height / 2) {
					newPosition.y = Director::getInstance()->getWinSize().height -  plane->getContentSize().height / 2;
				}

				if (newPosition.x < plane->getContentSize().width / 2) {
					newPosition.x = plane->getContentSize().width / 2;
				} else if (newPosition.x > Director::getInstance()->getWinSize().width - plane->getContentSize().width / 2) {
					newPosition.x = Director::getInstance()->getWinSize().width -  plane->getContentSize().width / 2;
				}

				plane->setPosition(newPosition);
			}
		};
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

		bRet = true;
	} while (0);

	return bRet;
}

void GameLayer::move(float dt) {
	_bg1->setPositionY(_bg1->getPositionY() - 2);
	_bg2->setPositionY(_bg1->getPositionY() + _bg1->getContentSize().height - 2);
	if (_bg2->getPositionY() <= 0) {
		_bg1->setPositionY(0);
	}
}

/*
 * 在该函数中进行碰撞检测，该函数每帧都会被调用。
 */

void GameLayer::update(float dt) {
	// 临时存放要被删除的对象
	Vector<Enemy*> dealEnemies1;
	Vector<Enemy*> dealEnemies2;
	Vector<Enemy*> dealEnemies3;
	Vector<Node*> hitBullets;
	bool hited = false;
	for(Node* bullet : _bulletLayer->getChildren()) {
		hited = false;
		auto point = bullet->getPosition() + Vect(bullet->getContentSize().width / 2, bullet->getContentSize().height / 2);

		//log("bullet: x=%f,y=%f",point.x, point.y);
		// enemy1
		for (Enemy* enemy :_enemyLayer->getEnemy1()) {
			auto rect = enemy->getBoundingBox();
			//log("rect: x=%f,y=%f,w=%f,h%f",rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
			if (rect.containsPoint(point)) {
				hited = true;
				//log("hit hit!");
				enemy->loseLife();
				//hitBullets.pushBack(bullet);
				if (((Enemy*)enemy)->getLife() <= 0) {
					dealEnemies2.pushBack(enemy);
					PlaneLayer::getInstance()->setSorce(23);
					break;
				}
			}
		}
		if (hited) {
			bullet->setPositionY(bullet->getPositionY() + 2);
			if (bullet->getPositionY() > Director::getInstance()->getVisibleSize().height) {
				hitBullets.pushBack(bullet);
			}
			continue;
		}

		// enemy2
		for (Enemy* enemy :_enemyLayer->getEnemy2()) {
			auto rect = enemy->getBoundingBox();
			//log("rect: x=%f,y=%f,w=%f,h%f",rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
			if (rect.containsPoint(point)) {
				enemy->loseLife();
				//hitBullets.pushBack(bullet);
				if (((Enemy*)enemy)->getLife() <= 0) {
					dealEnemies2.pushBack(enemy);
					PlaneLayer::getInstance()->setSorce(47);
					break;
				}
			}
		}
		if (hited) {
			bullet->setPositionY(bullet->getPositionY() + 2);
			if (bullet->getPositionY() > Director::getInstance()->getVisibleSize().height) {
				hitBullets.pushBack(bullet);
			}
			continue;
		}

		// enemy3
		for (Enemy* enemy :_enemyLayer->getEnemy3()) {
			auto rect = enemy->getBoundingBox();
			//log("rect: x=%f,y=%f,w=%f,h%f",rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
			if (rect.containsPoint(point)) {
				enemy->loseLife();
				//hitBullets.pushBack(bullet);
				if (((Enemy*)enemy)->getLife() <= 0) {
					dealEnemies3.pushBack(enemy);
					PlaneLayer::getInstance()->setSorce(50);
					break;
				}
			}
		}

		if (hited) {
			bullet->setPositionY(bullet->getPositionY() + 2);
			if (bullet->getPositionY() > Director::getInstance()->getVisibleSize().height) {
				hitBullets.pushBack(bullet);
			}
			continue;
		}

		// 移动子弹
		bullet->setPositionY(bullet->getPositionY() + 2);
		if (bullet->getPositionY() > Director::getInstance()->getVisibleSize().height) {
			hitBullets.pushBack(bullet);
		}
	}

	// 敌机爆炸
	for (Enemy* enemy : dealEnemies1) {
		_enemyLayer->removeChild(enemy, true);
	}
	dealEnemies1.clear();
	for (Enemy* enemy : dealEnemies2) {
		_enemyLayer->removeChild(enemy, true);
	}
	dealEnemies2.clear();
	for (Enemy* enemy : dealEnemies3) {
		_enemyLayer->removeChild(enemy, true);
	}
	dealEnemies3.clear();

	// 子弹销毁(非贯穿子弹)
	for (Node* bullet : hitBullets) {
		_bulletLayer->removeChild(bullet, true);
	}
	hitBullets.clear();
//
//	//log("Sroce: %d", PlaneLayer::getInstance()->getSorce());
}

