#include "NicoNicoCocosError.h"
#include "NicoNicoCocosSize.h"
#include "NicoNicoCocosRect.h"

#ifndef NICONICOCOCOSVIDEOCOMPOSITIONLAYOUT_H_
#define NICONICOCOCOSVIDEOCOMPOSITIONLAYOUT_H_

namespace niconico {

/**
 * 背景画像合成レイアウトパターン
 */
enum NicoNicoCocosVideoCompositionLayoutPattern {
	/**
	 * 縦向き キャプチャ映像中央
	 */
    PortraitCenter, //!< PortraitCenter
	/**
	 * 横向き キャプチャ映像左上
	 */
    LandscapeTopLeft//!< LandscapeTopLeft
};

/**
 * 配信映像の背景画像合成を設定する
 */
class NicoNicoCocosVideoCompositionLayout {
 private:
    NicoNicoCocosVideoCompositionLayoutPattern layoutPattern;
    int32_t backgroundImageTexture;
    bool enableBackgroundImageAnimation;
    bool flipY;
    NicoNicoCocosSize recordingBufferSize;
    NicoNicoCocosRect captureImageRect;
    NicoNicoCocosRect cameraPreviewRect;
 public:
    /**
     * コンストラクタ
     * @param layoutPattern レイアウトパターン
     * @param backgroundImageTexture　背景画像のテクスチャ
     */
    NicoNicoCocosVideoCompositionLayout(NicoNicoCocosVideoCompositionLayoutPattern layoutPattern,
                                        int32_t backgroundImageTexture);
    /**
     * コンストラクタ
     * @param layoutPattern レイアウトパターン
     * @param backgroundImageTexture 背景画像のテクスチャ
     * @param enableBackgroundImageAnimation 背景のアニメーションを有効にする
     * @param flipY 背景画像を上下反転させるか否か
     * @param recordingBufferSize 録画バッファーサイズ
     * @param captureImageRect キャプチャー画像に対応する短形領域
     * @param cameraPreviewRect　カメラプレビューに対応する短形領域
     */
    NicoNicoCocosVideoCompositionLayout(NicoNicoCocosVideoCompositionLayoutPattern layoutPattern,
                                        int32_t backgroundImageTexture, bool enableBackgroundImageAnimation, bool flipY,
                                        NicoNicoCocosSize recordingBufferSize, NicoNicoCocosRect captureImageRect,
                                        NicoNicoCocosRect cameraPreviewRect);

    /**
     * レイアウトパターンを取得
     * @return レイアウトパターン
     */
    NicoNicoCocosVideoCompositionLayoutPattern getLayoutPattern();

    /**
     * 背景画像テクスチャのハンドルを取得
     * @return テクスチャのハンドル
     */
    int32_t getBackgroundImageTexture();

    /**
     * 背景画像のアニメーションができるか否か
     * @warning Androidでは常にtrue扱いされる
     * @return アニメーションされている場合はtrue
     */
    bool checkEnableBackgroundImageAnimation();

    /**
     * 背景画像のアニメーションができるか否かを設定
     * @warning Androidでは常にtrue扱いされる
     * @param enableAnimation アニメーションができる場合true。そうでなければfalse
     */
    void setEnableBackgroundImageAnimation(bool enableAnimation);

    /**
     * 画像を上下反転させて描画するか否か
     * デフォルトは true
     * @return 反転させる場合true。そうでなければfalse
     */
    bool checkFlipY();
    
    /**
     * 画像を上下反転させて描画するか否かを設定
     * @param flip 反転させる場合true。そうでなければfalse
     */
    void setFlipY(bool flip);

    /**
     * 録画バッファサイズの取得
     * @return サイズ
     */
    NicoNicoCocosSize getRecordingBufferSize();

    /**
     * キャプチャ画像のレンダリング範囲の取得
     * @return レンダリング範囲
     */
    NicoNicoCocosRect getCaptureImageRect();

    /**
     * カメラプレビューのレンダリング範囲の取得
     * @return レンダリング範囲
     */
    NicoNicoCocosRect getCameraPreviewRect();
};

}

#endif
