#include "NicoNicoCocosSize.h"
#include "NicoNicoCocosRect.h"

#ifndef NICONICOCOCOSCAMERA_H_
#define NICONICOCOCOSCAMERA_H_

/**
 * セッション中のカメラプレビューの任意位置指定を無効化する為の定数
 * setPreviewPositionXとsetPreviewPositionYで指定する事ができる
 */
#define NicoNicoCameraPreviewPositionNegative -std::numeric_limits<float>::max()

namespace niconico {

/**
 * カメラプレビューの配置位置
 */
enum NicoNicoCocosPreviewGravity {
	/**
	 *画面左上
	 */
    TopLeft,
	/**
	 * 画面右上
	 */
    TopRight,
	/**
	 * 画面左下
	 */
    BottomLeft,
	/**
	 * 画面右下
	 */
    BottomRight
};

/**
 * カメラ機能
 */
class NicoNicoCocosCamera {
 public:
    NicoNicoCocosCamera();

    /**
     * カメラセッションが開始されているかどうか
     * @return 開始されている場合true。そうでなければfalse
     */
    bool isRunning();

    /**
     * カメラおよびマイクのセッションを開始する
     * @warning iOSのみ（Androidでは何も起きない)
     */
    void startSession();

    /**
     * カメラおよびマイクのセッションを停止する。
     * @warning iOSのみ（Androidでは何も起きない)
     */
    void stopSession();

    /**
     * 録画中かどうか否か
     * @warning iOSのみ（Androidでは常にfalse)
     * @return 録画中であればtrue。そうでなければfalse
     */
    bool isRecording();

    /**
     * 端末がカメラをサポートしているか
     * @return サポートしている場合true。そうでなければfalse
     */
    bool isVideoRecordingSupported();

    /**
     * カメラ映像のフレームレートを取得する
     * @return フレームレート
     */
    int getFramesPerSecond();

    /**
     * カメラ映像のフレームレートを設定する。範囲は`0`〜`60`
     * @warning Androidでは設定値通りになるとは限らない（可能な範囲で近い値になる）
     * @param fps フレームレート
     */
    void setFramesPerSecond(int fps);

    /**
     * 実行している端末がマイクをサポートしているかを返す。
     * @return サポートしている場合true。そうでなければfalse
     */
    bool isAudioRecordingSupported();

    /**
     * マイクのゲイン設定を取得
     * @return ゲイン
     */
    float getMicrophoneGain();

    /**
     * マイクのゲイン設定を行う。指定できる範囲は`0.0`〜`1.0`
     * @param gain ゲイン
     */
    void setMicrophoneGain(float gain);

    /**
     * マイクのミュート設定を取得
     * @warning iOSのみ（Androidでは常にfalse）
     * @return マイクミュートであればtrue。そうでなければfalse
     */
    bool isMicrophoneMute();
    
    /**
     * マイクのミュート設定
     * @warning iOSのみ (Androidで設定してもマイクのミュート設定はできない）
     */
    void setMicrophoneMute(bool mute);

    /**
     * マイクのみ有効であるかを取得する
     * @warning iOSのみ（Androidでは常にfalse）
     * @return マイクのみ有効である場合true。そうでなければfalse
     */
    bool isAudioOnly();

    /**
     * マイクのみ有効にするか
     * @warning iOSのみ（Androidでは設定不可能)
     * @param audioOnly マイクのみ有効にする場合true。そうでなければfalse
     */
    void setAudioOnly(bool audioOnly);

    /**
     * プレビューの表示をするかどうかを取得
     * @return カメラプレビューが表示されている場合true。そうでない場合false
     */
    bool isPreviewVisible();

    /**
     * セッション中、カメラプレビューを画面上に表示するかの設定を行う。
     * @param visible 表示する場合true。そうでない場合false
     */
    void setPreviewVisible(bool visible);

    /**
     * カメラプレビューの表示位置を取得
     * @return 表示位置
     */
    NicoNicoCocosPreviewGravity getPreviewGravity();

    /**
     * カメラプレビューの表示位置を設定
     * カメラプレビューを画面上のどの位置に配置するかを設定する。
     * previewPositionX かつ previewPositionY の値が NicoNicoCameraPreviewPositionNegative 以外の値のとき、
     * セッション中のカメラプレビュー時にはこの値は無視される。
     * デフォルトは NicoNicoCameraOverlapPreviewGravityTopLeft 。
     * @param gravity 表示位置
     */
    void setPreviewGravity(NicoNicoCocosPreviewGravity gravity);

    /**
     * カメラプレビューと画面端からのマージンを取得
     * @return マージン
     */
    float getPreviewMargin();

    /**
     * カメラプレビューと画面端からのマージンを設定
     * previewPositionX かつ previewPositionY の値が NicoNicoCameraPreviewPositionNegative 以外の値のとき、
     * セッション中のカメラプレビュー時にはこの値は無視される。
     * @param margin マージン
     */
    void setPreviewMargin(float margin);

    /**
     * セッション中のカメラプレビューのX座標を取得
     * @return X座標
     */
    float getPreviewPositionX();

    /**
     * セッション中のカメラプレビューのX座標を設定
     * @param x X座標
     */
    void setPreviewPositionX(float x);

    /**
     * セッション中のカメラプレビューのY座標を取得
     * @return Y座標
     */
    float getPreviewPositionY();

    /**
     * セッション中のカメラプレビューのY座標を設定
     * @param y Y座標
     */
    void setPreviewPositionY(float y);

    /**
     * カメラプレビューの幅を取得
     * @return プレビューの幅
     */
    float getPreviewWidth();

    /**
     * カメラプレビューの幅を設定
     * @param width プレビューの幅
     */
    void setPreviewWidth(float width);

    /**
     * カメラプレビューの高さを取得
     * @return プレビューの高さ
     */
    float getPreviewHeight();

    /**
     * カメラプレビューの高さを設定
     * @param height プレビューの高さ
     */
    void setPreviewHeight(float height);

    /**
     * カメラプレビューのボーダー幅を取得
     * @return ボーダー幅
     */
    float getPreviewBorderWidth();

    /**
     * カメラプレビューのボーダー幅を設定
     * @param width ボーダー幅
     */
    void setPreviewBorderWidth(float width);

    /**
     * カメラプレビューのボーダーカラーを取得
     * @return 色
     */
    int getPreviewBorderColor();

    /**
     * カメラプレビューで表示されるボーダーの色を設定する。
     * @param alpha アルファ値
     * @param red 赤
     * @param green 緑
     * @param blue 青
     */
    void setPreviewBorderColor(int alpha, int red, int green, int blue);

    /**
     * カメラプレビュー用のテクスチャIDを設定する
     * @warning iOSのみ（Androidでは何も起きない）
     * @param textureID テクスチャID
     */
    void setPreviewTextureID(int32_t textureID);

    /**
     * カメラプレビューのテクスチャサイズ
     * @warning iOSのみ（Androidでは幅✕高さ＝0✕0が返る）
     * @return テクスチャサイズ
     */
    NicoNicoCocosSize getPreviewTextureSize();

    /**
     * カメラの使用可否を取得する。
     * @return 使用可能であればtrue。そうでなければfalse
     */
    bool checkCameraRecordingPermission();

    /**
     * マイクの使用可否を取得する。
     * @return 使用可能であればtrue。そうでなければfalse
     */
    bool checkMicrophoneRecordingPermission();
};

}

#endif /* NICONICOCOCOSCAMERA_H_ */
