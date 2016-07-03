//
//  CommentSprite.hpp
//  OperationsGame
//
//  Created by 理貴 on 2016/07/02.
//
//

#ifndef CommentSprite_hpp
#define CommentSprite_hpp

#include "cocos2d.h"

using namespace cocos2d;

#define WINSIZE Director::getInstance()->getWinSize() // 画面サイズ取得用マクロ

class CommentSprite : public cocos2d::Sprite
{
public:
    CommentSprite();
    static CommentSprite* create(std::string operation, int ans);
    virtual bool init(std::string operation, int ans); // 初期化
    bool equal(int ans);
    
    CC_SYNTHESIZE(int, _ans, Ans);
    CC_SYNTHESIZE(std::string, _operation, Operation);
    
protected:
    void showOperation();
};


#endif /* CommentSprite_hpp */
