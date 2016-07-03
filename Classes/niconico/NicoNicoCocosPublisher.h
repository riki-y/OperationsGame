#include <string>
#include "NicoNicoCocosPublishProgram.h"
#include "NicoNicoCocosComment.h"
#include "NicoNicoCocosError.h"
#include "NicoNicoCocosVideoCompositionLayout.h"

#ifndef NICONICOCOCOSPUBLISHER_H_
#define NICONICOCOCOSPUBLISHER_H_

namespace niconico {

/**
 * 生放送配信品質
 */
enum NicoNicoCocosPublisherQuality {
    /**
     * 最低
     */
	Worst,
    /**
     * 低
     */
	Worse,
    /**
     * 中間
     */
	Medium,
    /**
     * 良
     */
	Better,
    /**
     * 最高
     */
	Best
};

/**
 * 生放送配信時のカメラ設定
 */
enum NicoNicoCocosPublisherCameraMode {
    /**
     * カメラおよびマイクを使用しない。
     */
    Off,
    /**
     * カメラのみを使用し、マイクを使用しない
     */
    CameraOnly,
    /**
     * マイクのみを使用し、カメラを使用しない
     */
    MicrophoneOnly,
    /**
     * カメラおよびマイクを使用する
     */
    Both
};

/**
 * 生放送の配信機能
 */
class NicoNicoCocosPublisher {
 public:
    NicoNicoCocosPublisher();

    /**
     * 画質・音質設定の取得
     * @return 品質設定
     */
    NicoNicoCocosPublisherQuality getQuality();

    /**
     * 画質・音質設定の設定
     * @param quality 品質設定
     */
    void setQuality(NicoNicoCocosPublisherQuality quality);

    /**
     * カメラ・マイク設定の取得
     * @return カメラ・マイク設定
     */
    NicoNicoCocosPublisherCameraMode getCameraMode();

    /**
     * カメラ・マイク設定の設定
     * @param cameraMode カメラ・マイク設定
     */
    void setCameraMode(NicoNicoCocosPublisherCameraMode cameraMode);

    /**
     * マイクゲインを取得
     * @return ゲイン
     */
    float getMicrophoneGain();

    /**
     * マイクゲインの設定 (`0.0`-`1.0`)
     * @param gain ゲイン
     */
    void setMicrophoneGain(float gain);

    /**
     * 生放送中のアプリ音声のボリュームの取得
     * @return ボリューム
     */
    float getLiveAudioVolume();
    
    /**
     * 生放送中のアプリ音声のボリュームの設定 (`0.0`-`1.0`)
     * @param volume ボリューム
     */
    void setLiveAudioVolume(float volume);
    
    /**
     * 配信番組情報の取得
     * @return 番組情報
     */
    NicoNicoCocosPublishProgram getProgram();

    /**
     * 配信番組の経過時間（ミリ秒）取得
     * @return 経過時間
     */
    int64_t getElapsedTime();

    /**
     * 配信番組の残り時間（ミリ秒）取得
     * @return 残り時間
     */
    int64_t getRemainingTime();

    /**
     * 最新のコメント一覧取得
     * （NicoNicoFeaturesのmaxCapacityForLiveCommentsの値を最大件数とする）
     * @return コメント一覧
     */
    std::vector<NicoNicoCocosComment> getLatestComments();

    /**
     * コメントのオーバーレイ表示の設定を取得
     * @return 表示されている場合true。そうでなければfalse
     */
    bool isCommentVisible();

    /**
     * コメントのオーバーレイ表示を設定
     * @param visible 表示する場合true。そうでなければfalse
     */
    void setCommentVisibility(bool visible);

    /**
     * コメントのオーバーレイ表示範囲を取得
     * @return 表示領域
     */
    NicoNicoCocosRect getCommentStageRect();

    /**
     * コメントのオーバーレイ表示範囲
     * @param x 領域左上端X座標
     * @param y 領域左上端Y座標
     * @param renderSpaceWidth 領域幅
     * @param renderSpaceHeight 領域高さ
     */
    void setCommentStageRect(int x, int y, int renderSpaceWidth, int renderSpaceHeight);

    /**
     * 配信を開始したかどうかを取得
     * @return 開始している場合true。そうでなければfalse
     */
    bool isPublishing();

    /**
     * 配信が一時停止中かどうかを取得
     * @return 一時停止中の場合true。そうでなければfalse
     */
    bool isPaused();

    /**
     * 配信の開始
     * @return 開始された場合true。そうでなければfalse
     */
    bool startPublishing();

    /**
     * 配信の再開
     * @return 再開された場合true。そうでなければfalse
     */
    bool restartPublishing();

    /**
     * 配信の一時停止
     * @return 一時停止がされた場合true。そうでなければfalse
     */
    bool pausePublishing();

    /**
     * 配信の終了
     * @return 終了された場合true。そうでなければfalse
     */
    bool stopPublishing();

    /**
     * 配信者コメントの投稿
     * @param comment コメント
     */
    void postBroadcasterComment(std::string comment);

    /**
     * 背景画像合成レイアウトの取得
     * @return 背景画像合成レイアウト
     */
    NicoNicoCocosVideoCompositionLayout getVideoCompositionLayout();

    /**
     * 背景画像合成レイアウトを設定
     * @param videoCompositionLayout 背景画像合成レイアウト
     */
    void setVideoCompositionLayout(NicoNicoCocosVideoCompositionLayout videoCompositionLayout);
};

}

#endif /* NICONICOCOCOSPUBLISHER_H_ */
