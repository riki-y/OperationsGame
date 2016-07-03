//
//  MainGameScene.hpp
//  OperationsGame
//
//  Created by 理貴 on 2016/05/06.
//
//

#ifndef MainGameScene_hpp
#define MainGameScene_hpp

#include <stdio.h>
#include <string.h>
#include "cocos2d.h"
#include "ButtonSprite.hpp"
#include "InputCardSprite.hpp"
#include "CommentSprite.hpp"

using namespace cocos2d;
using namespace std;

#define WINSIZE Director::getInstance()->getWinSize() // 画面サイズ取得用マクロ

class MainGameScene : public cocos2d::Layer
{
protected:
    enum ZOrder
    {
        Z_Background,
        Z_InputBox,
        Z_Button,
        Z_Sprite,
        Z_Company,
        Z_Comment,
        Z_Scope,
    };
    
    enum Tag
    {
        T_Background,
        T_InputBox,
        T_Button,
        T_Sprite,
        T_Company,
        T_Comment,
        T_Scope,
    };
    
    void initGameState(); // ゲーム状態を初期化
    void initBackground(); // バックグラウンドの初期化
    void createGround();
    void createLeftWall();
    void createCeiling();
    void createComment(std::string operation, int ans); // コメント生成
    void createCompany();
    void createScope();
    
    ButtonSprite* createButton(ButtonSprite::ButtonType buttonType, ButtonSprite::PositionIndex positionIndex, std::string str); // ボタンを作る
    ButtonSprite* getTouchButton(cocos2d::Point touchPos, ButtonSprite::PositionIndex withoutPosIndex = ButtonSprite::PositionIndex());
    ButtonSprite* _currentTouchButton;
    
    CommentSprite* _commentSprite;
    
    InputCardSprite* createInputCardSprite(InputCardSprite::PositionIndex positionIndex);
    void changeInputCardSprites(InputCardSprite::CardType cardType, int num);
    void initInputCardSprite(); // 入力カードの初期化
    
    ButtonSprite* _zeroButton;
    ButtonSprite* _oneButton;
    ButtonSprite* _twoButton;
    ButtonSprite* _threeButton;
    ButtonSprite* _fourButton;
    ButtonSprite* _fiveButton;
    ButtonSprite* _sixButton;
    ButtonSprite* _sevenButton;
    ButtonSprite* _eightButton;
    ButtonSprite* _nineButton;
    ButtonSprite* _cancelButton;
    ButtonSprite* _okButton;
    
    InputCardSprite* _oneDigitSprite;
    InputCardSprite* _twoDigitSprite;
    InputCardSprite* _threeDigitSprite;
    InputCardSprite* _fourDigitSprite;
    InputCardSprite* _fiveDigitSprite;
    
    cocos2d::Sprite* _scope;
    
    CC_SYNTHESIZE(int, _num, Num); // ボタンの種類
    CC_SYNTHESIZE(float, _time, Time);
    
    vector<string> split(const string& s, string delim);
    
    int calculate(vector<string> v);
    
//    ButtonSprite::ButtonType getTouchButtonType(Point touchPos, ButtonSprite::PositionIndex withoutPosIndex = ButtonSprite::PositionIndex()); // タッチしたボタンのタイプを取得する
    
public:
    MainGameScene(); // コンストラクタ
    virtual bool init(); // 初期化
    CREATE_FUNC(MainGameScene); // create関数生成
    static cocos2d::Scene* createScene(); // シーン生成
    virtual void onEnter(); //レイヤー表示時処理
    virtual void update(float dt);// update関数 (毎フレーム処理)
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    
    bool onContactBegin(cocos2d::PhysicsContact& contact);
};

#endif /* MainGameScene_hpp */
