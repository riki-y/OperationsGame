//
//  InputCardSprite.cpp
//  OperationsGame
//
//  Created by 理貴 on 2016/06/29.
//
//

#include "InputCardSprite.hpp"
#include <stdio.h>
#define STR(var) #var

USING_NS_CC;

// コンストラクタ
InputCardSprite::InputCardSprite()
: _positionIndex(0, 0)
{
}

// インスタンス生成
InputCardSprite* InputCardSprite::create(PositionIndex positionIndex, CardType cardType, int num)
{
    InputCardSprite* pRet = new InputCardSprite();
    
    if (pRet && pRet->init(positionIndex, cardType, num)) {
        pRet->autorelease();
    } else {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
}

// 初期化
bool InputCardSprite::init(PositionIndex positionIndex, CardType cardType, int num)
{
    if (!Sprite::initWithFile(getCardImageFilePath(cardType))) {
        return false;
    }
    
    _cardType = cardType;
    _num = num;
    setPositionIndex(positionIndex);
    
    return true;
}

// カードの画像を変更
void InputCardSprite::changeCardImageTexture()
{
    setTexture(getCardImageFilePath(_cardType));
}

void InputCardSprite::changeCard(CardType cardType, int num)
{
    _cardType = cardType;
    _num = num;
    changeCardImageTexture();
    showNum();
}

void InputCardSprite::copyCard(InputCardSprite* sprite)
{
    changeCard(sprite->getCardType(), sprite->getNum());
}

void InputCardSprite::initCard()
{
    removeAllChildren();
    _cardType = CardType::Empty;
    changeCardImageTexture();
}

// 位置インデックスを返す
InputCardSprite::PositionIndex InputCardSprite::getPositionIndex()
{
    return _positionIndex;
}

// 位置インデックスとタグを変更する
void InputCardSprite::setPositionIndex(PositionIndex positionIndex)
{
    // 位置インデックスを保持する
    _positionIndex = positionIndex;
    // 位置を変更する
    setPosition(getPointForPositionIndex(_positionIndex));
    // タグをセットする
    setTag(getGenerateTag(_positionIndex));
}

// グリッド画像の取得
std::string InputCardSprite::getCardImageFilePath(CardType cardType)
{
    std::string s = STR(cardType);
    switch (cardType) {
        case CardType::Black:
            return "input_card/input_black.png";
        case CardType::Red:
            return "input_card/input_red.png";
        case CardType::Yellow:
            return "input_card/input_yellow.png";
        case CardType::Yellow_green:
            return "input_card/input_yellow_green.png";
        case CardType::Green:
            return "input_card/input_green.png";
        case CardType::Blue:
            return "input_card/input_blue.png";
        case CardType::Orange:
            return "input_card/input_orange.png";
        case CardType::Pink:
            return "input_card/input_pink.png";
        case CardType::Light_blue:
            return "input_card/input_light_blue.png";
        case CardType::Purple:
            return "input_card/input_purple.png";
        default:
            return "input_card/input_empty.png";
    }
}

void InputCardSprite::showNum()
{
    if (_cardType != CardType::Empty) {
        removeAllChildren();
        
        Color4B textColor = Color4B::BLACK;
    
        TTFConfig ttfConfig("fonts/PixelMplus12-Regular.ttf",
                            79,
                            GlyphCollection::DYNAMIC);
        
        auto number = Label::createWithTTF(ttfConfig, std::to_string(_num));
        
        number->setPosition(Point(getContentSize() / 2));
        number->setTextColor(textColor);
        addChild(number);
    }
}

// 位置インデックスからPointを取得
Point InputCardSprite::getPointForPositionIndex(PositionIndex positionIndex)
{
    return Point(positionIndex.x*SPRITE_SIZE+SPRITE_SIZE/2, positionIndex.y);
}

// 位置インデックスからタグを取得
int InputCardSprite::getGenerateTag(PositionIndex positionIndex)
{
    return SPRITE_TAG + positionIndex.x * 10 + positionIndex.y;
}
