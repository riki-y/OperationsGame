#include <string>

#ifndef NICONICOCOCOSSIZE_H_
#define NICONICOCOCOSSIZE_H_

namespace niconico {

/**
 * カメラのプレビューサイズ
 */
class NicoNicoCocosSize {
 private:
    int width;
    int height;
 public:
    /**
     * コンストラクタ
     * @param width 幅
     * @param height 高さ
     */
    NicoNicoCocosSize(int width, int height)
            : width(width),
              height(height) {
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
};

}

#endif
