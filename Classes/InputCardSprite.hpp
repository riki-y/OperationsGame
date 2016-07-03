//
//  InputCardSprite.hpp
//  OperationsGame
//
//  Created by 理貴 on 2016/06/29.
//
//

#ifndef InputCardSprite_hpp
#define InputCardSprite_hpp

#include "cocos2d.h"

#define SPRITE_SIZE 128
#define SPRITE_TAG 200

using namespace cocos2d;

class InputCardSprite : public cocos2d::Sprite
{
public:
    enum class CardType
    {
        Black,
        Red,
        Yellow,
        Yellow_green,
        Green,
        Blue,
        Orange,
        Pink,
        Light_blue,
        Purple,
        Empty,
    };
    
    // 位置インデックス
    struct PositionIndex {
        // コンストラクタ
        PositionIndex() {
            x = 0;
            y = 0;
        }
        
        PositionIndex(int _x, int _y) {
            x = _x;
            y = _y;
        }
        
        int x; // x方向のインデックス
        int y; // y方向のインデックス
        
    };
    
    InputCardSprite(); // コンストラクタ
    static InputCardSprite* create(PositionIndex positionIndex, CardType cardType, int num);
    virtual bool init(PositionIndex positionIndex, CardType cardType, int num); // 初期化
    void changeCardImageTexture(); // カード画像を変更
    void changeCard(CardType cardType, int num); // カード変更
    void copyCard(InputCardSprite* sprite);
    void initCard();
    std::string getCardImageFilePath(CardType cardType); // カード画像取得
    static cocos2d::Point getPointForPositionIndex(PositionIndex positionIndex); // 位置インデックスからポイントを取得
    static int getGenerateTag(PositionIndex positionIndex); // 位置インデックスからタグを取得
    
    CC_PROPERTY(PositionIndex, _positionIndex, PositionIndex); // 位置インデックス
    CC_SYNTHESIZE(CardType, _cardType, CardType); // ボタンの種類
    CC_SYNTHESIZE(int, _num, Num);
protected:
    void showNum();
};


#endif /* InputCardSprite_hpp */
