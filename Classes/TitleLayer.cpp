//
//  TitleLayer.cpp
//  OperationsGame
//
//  Created by 吉田　理貴 on 2016/07/04.
//
//

#include "TitleLayer.hpp"
#include "MainGameScene.hpp"
#include "niconico/NicoNicoCocos.h"
#include "CocosSampleEventListener.h"
#include "CocosSampleFeatures.h"
#include <stdio.h>
#include <string.h>

using namespace cocos2d;
using namespace niconico;
using namespace std;

USING_NS_CC;

// コンストラクタ
TitleLayer::TitleLayer()
{
}

// シーンの生成
Scene* TitleLayer::createScene()
{
    auto scene = Scene::create();
    auto layer = TitleLayer::create();
    scene->addChild(layer);
    
    string id = "aaa";
    string secret = "aaa";
    
    niconico::NicoNicoCocos::getInstance().initialize(
                                                      id.c_str(),
                                                      secret.c_str(),
                                                      new niconico::CocosSampleFeatures(),
                                                      new niconico::CocosSampleEventListener()
                                                      );
    
    return scene;
}

// 初期化
bool TitleLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    // シングルタップイベントの取得
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(_swallowsTouches);
    touchListener->onTouchBegan = CC_CALLBACK_2(TitleLayer::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(TitleLayer::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(TitleLayer::onTouchEnded, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(TitleLayer::onTouchCancelled, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    initBackground(); // 背景の初期化
    
    return true;
}

// 背景の初期化
void TitleLayer::initBackground()
{
    auto background = Sprite::create("background.png");
    background->setAnchorPoint(Point::ZERO);
    background->setPosition(Point::ZERO);
    addChild(background, Z_Background, T_Background);
}

bool TitleLayer::onTouchBegan(Touch* touch, Event* unused_event)
{
    return true;
}

void TitleLayer::onTouchMoved(Touch* touch, Event* unused_event)
{
}

void TitleLayer::onTouchEnded(Touch* touch, Event* unused_event)
{
    createAndMoveGameScene();
}

void TitleLayer::onTouchCancelled(Touch* touch, Event* unused_event)
{
    onTouchEnded(touch, unused_event);
}

// ゲームシーンを作成し、移動
void TitleLayer::createAndMoveGameScene()
{
    auto scene = MainGameScene::createScene();
    Director::getInstance()->replaceScene(scene);
}
