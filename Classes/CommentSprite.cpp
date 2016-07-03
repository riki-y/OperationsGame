//
//  CommentSprite.cpp
//  OperationsGame
//
//  Created by 理貴 on 2016/07/02.
//
//

#include "CommentSprite.hpp"

USING_NS_CC;

CommentSprite::CommentSprite()
{
}

CommentSprite* CommentSprite::create(std::string operation, int ans)
{
    CommentSprite* pRet = new CommentSprite();
    
    if (pRet && pRet->init(operation, ans)) {
        pRet->autorelease();
    } else {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
}

bool CommentSprite::init(std::string operation, int ans)
{
    if (!Sprite::initWithFile("transparent.png")) {
        return false;
    }
    
    setOperation(operation);
    setPosition(Point(WINSIZE.width-20, WINSIZE.height-20));
    showOperation();
    _ans = ans;
    
    return true;
}

void CommentSprite::showOperation()
{
    Color4B textColor = Color4B::BLACK;
        
    TTFConfig ttfConfig("fonts/nicomoji-plus.ttf",
                        50,
                        GlyphCollection::DYNAMIC);
    
    auto operation = Label::createWithTTF(ttfConfig, getOperation());
    
    operation->setPosition(Point(getContentSize() / 2));
    operation->setTextColor(textColor);
    addChild(operation);
    
    PhysicsMaterial material;
    material.density = 0.5;
    material.restitution = 0.5;
    material.friction = 0.3;
    
    auto body = PhysicsBody::createCircle(operation->getContentSize().height * 0.45);
    body->setDynamic(true);
    body->setContactTestBitmask(1);
    setPhysicsBody(body);
}

bool CommentSprite::equal(int ans) {
    if (_ans == ans) {
        return true;
    }
    
    return false;
}
