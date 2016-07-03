#include <string>

#ifndef NICONICOCOCOSRECT_H_
#define NICONICOCOCOSRECT_H_

namespace niconico {

/**
 * 短形領域
 */
class NicoNicoCocosRect {
 private:
    int x;
    int y;
    int width;
    int height;
 public:
    /**
     * コンストラクタ
     * @param x 左上端X座標
     * @param y 左上端Y座標
     * @param width 幅
     * @param height 高さ
     */
    NicoNicoCocosRect(int x, int y, int width, int height)
            : x(x),
              y(y),
              width(width),
              height(height) {
    }
    /**
     * 短形領域左上端のy座標を取得
     * @return X座標
     */
    int getTop() {
        return y;
    }
    /**
     * 短形領域左上端のx座標を取得
     * @return Y座標
     */
    int getLeft() {
        return x;
    }
    /**
     * 幅を取得
     * @return 幅
     */
    int getWidth() {
        return width;
    }
    /**
     * 高さを取得
     * @return 高さ
     */
    int getHeight() {
        return height;
    }
    /**
     * 短形領域右下端のY座標を取得
     * @return Y座標
     */
    int getBottom() {
        return y + height;
    }
    /**
     * 短形領域右下端のX座標を取得
     * @return X座標
     */
    int getRight() {
        return x + width;
    }
};

}

#endif
