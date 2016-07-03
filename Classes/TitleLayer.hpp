//
//  TitleLayer.hpp
//  OperationsGame
//
//  Created by 吉田　理貴 on 2016/07/04.
//
//

#ifndef TitleLayer_hpp
#define TitleLayer_hpp

#include "cocos2d.h"

#define WINSIZE Director::getInstance()->getWinSize() // 画面サイズ取得用マクロ

#define NICONICO_SIZE 100

class TitleLayer : public cocos2d::Layer
{
protected:
    enum ZOrder
    {
        Z_Background,
        Z_NicoNicoButton,
    };
    
    enum Tag
    {
        T_Background,
        T_NicoNicoButton,
    };
    
    void initBackground(); // 背景の初期化
    void createAndMoveGameScene(); // ゲームシーンを作成し、移動
    void createNicoNicoButton();
    cocos2d::Sprite* _niconicoButton;
    void showPublisher();
    
public:
    TitleLayer(); // コンストラクタ
    virtual bool init(); // 初期化
    CREATE_FUNC(TitleLayer); // create関数生成
    static cocos2d::Scene* createScene(); // シーン生成
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* unused_event);
};


#endif /* TitleLayer_hpp */
