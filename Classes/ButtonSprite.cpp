//
//  ButtonSprite.cpp
//  OperationsGame
//
//  Created by 理貴 on 2016/05/06.
//
//

#include "ButtonSprite.hpp"

USING_NS_CC;

// コンストラクタ
ButtonSprite::ButtonSprite()
: _positionIndex(0, 0)
{
}

// インスタンス生成
ButtonSprite* ButtonSprite::create(PositionIndex positionIndex, ButtonType buttonType, std::string str)
{
    ButtonSprite* pRet = new ButtonSprite();
    if (pRet && pRet->init(positionIndex, buttonType, str)) {
        pRet->autorelease();
    } else {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
}

// 初期化
bool ButtonSprite::init(PositionIndex positionIndex, ButtonType buttonType, std::string str)
{
    if (!Sprite::initWithFile(getButtonImageFilePath(buttonType))) {
        return false;
    }
    
    _buttonType = buttonType;
    setPositionIndex(positionIndex);
    showStr(str);
    
    return true;
}

// ボタンの画像を変更
void ButtonSprite::changeButtonImageTexture()
{
    setTexture(getButtonImageFilePath(_buttonType));
}

void ButtonSprite::changePushButtonImageTexture()
{
    setTexture(getPushButtonImageFilePath());
}

// 位置インデックスを返す
ButtonSprite::PositionIndex ButtonSprite::getPositionIndex()
{
    return _positionIndex;
}

// 位置インデックスとタグを変更する
void ButtonSprite::setPositionIndex(PositionIndex positionIndex)
{
    // 位置インデックスを保持する
    _positionIndex = positionIndex;
    // 位置を変更する
    setPosition(getPointForPositionIndex(_positionIndex));
    // タグをセットする
    setTag(getGenerateTag(_positionIndex));
}

// グリッド画像の取得
std::string ButtonSprite::getButtonImageFilePath(ButtonType buttonType)
{
    switch (buttonType) {
        case ButtonType::Normal:
            return "button.png";
        default:
            return "";
    }
}

std::string ButtonSprite::getPushButtonImageFilePath()
{
    switch (_buttonType) {
        case ButtonType::Normal:
            return "button_push.png";
        default:
            return "";
    }
}

void ButtonSprite::showStr(std::string str)
{
    Color4B textColor = Color4B::BLACK;
    
    if (str.size() > 1) {
        TTFConfig ttfConfig("fonts/PixelMplus12-Regular.ttf",
                            74,
                            GlyphCollection::DYNAMIC);
        
        auto number = Label::createWithTTF(ttfConfig, str);
        
        number->setPosition(Point(getContentSize() / 2));
        number->setTextColor(textColor);
        addChild(number);
    } else {
        TTFConfig ttfConfig("fonts/PixelMplus12-Regular.ttf",
                            96,
                            GlyphCollection::DYNAMIC);
        
        auto number = Label::createWithTTF(ttfConfig, str);
        
        number->setPosition(Point(getContentSize() / 2));
        number->setTextColor(textColor);
        addChild(number);
    }
}

// 位置インデックスからPointを取得
Point ButtonSprite::getPointForPositionIndex(PositionIndex positionIndex)
{
    return Point(positionIndex.x, positionIndex.y);
}

// 位置インデックスからタグを取得
int ButtonSprite::getGenerateTag(PositionIndex positionIndex)
{
    return BUTTON_TAG + positionIndex.x * 10 + positionIndex.y;
}
