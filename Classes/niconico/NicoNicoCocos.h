#include <string>
#include <vector>
#include "NicoNicoCocosPublisher.h"
#include "NicoNicoCocosCapture.h"
#include "NicoNicoCocosCamera.h"
#include "NicoNicoCocosUser.h"
#include "NicoNicoCocosComment.h"
#include "NicoNicoCocosUploadVideo.h"
#include "NicoNicoCocosFeatures.h"
#include "NicoNicoCocosEventListener.h"

#ifndef NICONICOCOCOS_H_
#define NICONICOCOCOS_H_

namespace niconico {

/**
 * NicoNicoの動作モード
 */
enum NicoNicoCocosConfigurationMode {
	/**
	 * 開発モード
	 */
    Debug,
	/**
	 * リリースモード
	 */
    Release
};

/**
 * NicoNicoの基本機能を使うためのオブジェクト
 */
class NicoNicoCocos {
 private:
    NicoNicoCocos(const NicoNicoCocos& niconico){};
    void operator =(const NicoNicoCocos& niconico){};
 protected:
    NicoNicoCocos();
    ~NicoNicoCocos();
 public:
    /**
     * NicoNicoCocosの初期化
     * @param clientId クライアントID
     * @param clientSecret クライアントシークレット
     * @param features フィーチャー
     * @param eventListener イベント通知をするリスナー
     */
    void initialize(std::string clientId, std::string clientSecret, NicoNicoCocosFeatures *features,
                    NicoNicoCocosEventListener *eventListener);

    /**
     * シングルトンの取得
     * @return シングルトン
     */
    static NicoNicoCocos& getInstance() {
        static NicoNicoCocos singleton;
        return singleton;
    }

    /**
     * SDKバージョンを取得
     * @return SDKバージョンの文字列
     */
    static std::string getVersion();

    /**
     * SDKが有効な状態か否か
     * @warning Androidのみ（iOSでは常にtrue）
     * @return AndroidのAPIレベルが規定のレベルより大きい場合はtrue。そうでなければfalse
     */
    static bool isEnabled();

    /**
     * NicoNicoの動作モードを設定
     * @param configurationMode 動作モード
     */
    void setNicoNicoCocosConfigurationMode(NicoNicoCocosConfigurationMode configurationMode);

    /**
     * 未ログイン状態であれば、ログインビューを立ち上げる
     */
    void authenthicate();

    /**
     * ログアウトを行う
     */
    void destroySession();

    /**
     * 動画投稿用のNicoNicoCocosCaptureインスタンスを取得
     * @warning iOSのみ（Androidでは機能しないインスタンスが返される）
     * @return NicoNicoCaptureのインスタンス
     */
    NicoNicoCocosCapture getNicoNicoCocosCapture();

    /**
     * 生放送配信用のNicoNicoCocosPublisherインスタンスを取得
     * @return NicoNicoCocosPublisherインスタンス
     */
    NicoNicoCocosPublisher getNicoNicoCocosPublisher();

    /**
     * カメラ制御用のNicoNicoCocosCameraインスタンスを取得
     * @return NicoNicoCocosCameraインスタンス
     */
    NicoNicoCocosCamera getNicoNicoCocosCamera();

    /**
     * 現在ログイン中のユーザーを取得
     * @return ユーザー
     */
    NicoNicoCocosUser getCurrentUser();

    /**
     * niconicoのビューが表示されているか否か
     * @return 表示されている場合はtrue。そうでなければfalse
     */
    bool isViewVisible();

    /**
     * niconicoのチャイルドビューが表示されているかを取得
     * @return 表示されている場合はtrue。そうでなければfalse
     */
    bool isChildViewVisible();

    /**
     * アップロード処理中かどうかを取得
     * @warning iOSのみ（Androidでは常にfalse）
     * @return アップロード中であればtrue。そうでなければfalse
     */
    bool isUploading();

    /**
     * 録画した動画が存在するかを取得
     * @warning iOSのみ（Androidでは常にfalse）
     * @return 録画された動画が存在する場合true。そうでなければfalse
     */
    bool recordedMovieExists();

    /**
     * 動画アップロード用のビューを立ち上げる
     * @warning iOSのみ（Androidでは何も起きない）
     * @return アップロードする動画がある場合true。そうでなければfalseでビューは立ち上がらない
     */
    bool showUploadView();

    /**
     * タイトルなどを指定して動画アップロード用のビューを立ち上げる
     * @warning iOSのみ（Androidでは何も起きない）
     * @param category 動画カテゴリー
     * @param title タイトル
     * @param description 詳細
     * @param editableTags 編集可能なタグのリスト
     * @param uneditableTags 編集不可能なタグのリスト
     * @return アップロードする動画がある場合true。そうでなければfalseでビューは立ち上がらない
     */
    bool showUploadView(NicoNicoCocosCategory category, std::string title, std::string description,
                        std::vector<std::string> editableTags, std::vector<std::string> uneditableTags);

    /**
     * 生放送番組作成用のビューを立ち上げる
     * @return 番組作成画面が立ち上げられた場合はtrue。そうでなければfalse
     */
    bool showPublishView();

    /**
     * タイトルなどを指定して生放送番組作成用のビューを立ち上げる
     * @param title タイトル
     * @param description 詳細
     * @param tags 編集不可能なタグのリスト
     * @return 番組作成画面が立ち上げられた場合はtrue。そうでなければfalse
     */
    bool showPublishView(std::string title, std::string description, std::vector<std::string> tags);

    /**
     * 配信メニューを表示する
     * @return 配信メニューが表示された場合true。そうでなければfalse
     */
    bool showPublishMenu();

    /**
     * niconicoのポータル画面を立ち上げる
     * @param pickUpContents ピックアップコンテンツ
     * @return ポータルのビューが表示された場合true。そうでなければfalse
     */
    bool showPortalViewWithPickUpContents(std::vector<std::string> pickUpContents);

    /**
     * タイトルなどを指定してniconicoのポータル画面を立ち上げる
     * @param pickUpContents ピックアップコンテンツ
     * @param title タイトル
     * @param description 詳細
     * @param tags 編集不可能なタグのリスト
     * @return ポータルのビューが表示された場合true。そうでなければfalse
     */
    bool showPortalViewWithPickUpContents(std::vector<std::string> pickUpContents, std::string title,
                                          std::string description, std::vector<std::string> tags);
};

}

#endif /* NICONICO_H_ */
