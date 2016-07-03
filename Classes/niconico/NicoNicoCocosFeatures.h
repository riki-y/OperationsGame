#include <string>
#include <cocos2d.h>

#ifndef NICONICOCOCOSFEATURES_H_
#define NICONICOCOCOSFEATURES_H_

namespace niconico {

// 生放送配信対応判定ポリシー
/**
 * 動作未検証の端末によるSDK機能の利用を禁止する
 */
#define NICONICOCOCOS_SUPPORT_VALIDATION_POLICY_STRICT "strict"

/**
 * 動作未検証の端末によるSDK機能の利用を許可する
 */
#define  NICONICOCOCOS_SUPPORT_VALIDATION_POLICY_PERMISSIVE "permissive"

/**
 * niconicoスマホSDKのサービスタイプ
 */
enum NicoNicoCocosAvailableServiceType {
    /**
     * 生放送配信機能
     */
    Live = 1 << 0,
    /**
     * 動画投稿機能
     */
    Video = 1 << 1,
};

class NicoNicoCocosFeatures {
 public:
    virtual ~NicoNicoCocosFeatures() {
    }

    /**
     * niconicoスマホSDKのサービスタイプ
     * @return サービスタイプ
     */
    virtual int availableServiceType() {
        return Live;
    }

    /**
     * ログイン画面に新規アカウント作成用のボタンの表示を許可するかどうか。
     * @warning iOSのみ（Androidでは設定値は用いられない）
     * @return 表示を許可する場合true。そうでなければfalse
     */
    virtual bool shouldShowAccountSignupButton() {
        return false;
    }
    
    /**
     * niconicoスマホSDKを組み込んだアプリが使用するフレームワークの種類
     * @warning SDKの内部処理用につき、変更しないでください。
     * @return フレームワークの種類
     */
    virtual std::string frameworkType() {
        std::string frameworkType("cocos2d-x ");
        frameworkType.append(cocos2d::cocos2dVersion());
        return frameworkType;
    }
    
    /**
     * niconicoスマホSDKの動作可能端末の判定ポリシー
     * @return 判定ポリシー
     */
    virtual std::string supportValidationPolicy() {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        return NICONICOCOCOS_SUPPORT_VALIDATION_POLICY_PERMISSIVE;
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        return NICONICOCOCOS_SUPPORT_VALIDATION_POLICY_STRICT;
#endif
    }

    /**
     * ストレージ空き領域の下限バイト数
     * @warning iOSのみ（Androidでは設定値は用いられない）
     * @return バイト数
     */
    virtual uint64_t storageFreeSpaceLimit() {
        return (256LLU * 1024LLU * 1024LLU);
    }

    /**
     * OpenALのキャプチャ処理をサポートするか
     * @warning iOSのみ（Androidでは設定値は用いられない）
     * @return サポートする場合true。そうでなければfalse
     */
    virtual bool supportsOpenAL() {
        return true;
    }

    /**
     * AVAudioPlayerのキャプチャ処理をサポートするか
     * @warning iOSのみ（Androidでは設定値は用いられない）
     * @return サポートする場合true。そうでなければfalse
     */
    virtual bool supportsAVAudioPlayer() {
        return true;
    }

    /**
     * AudioUnit(RemoteIO)のキャプチャ処理をサポートするか
     * @warning iOSのみ（Androidでは設定値は用いられない）
     * @return サポートする場合true。そうでなければfalse
     */
    virtual bool supportsAudioUnit() {
        return true;
    }

    /**
     * 外部音声入力をサポートするか デフォルトはfalse
     * trueに設定した場合、supportsOpenAL、supportsAVAudioPlayer、supportsAudioUnitの設定に依らず、これらの音源に対するキャプチャ処理が行われなくなる。
     * また、入力された外部音声はNicoNicoで録画した映像データに含まれるが、NicoNicoからスピーカー及びヘッドフォンへの出力は行われない。
     * このため、スピーカー及びヘッドフォンへの音声出力は、外部音源側で対応する必要がある。
     * @warning iOSのみ（Androidでは常にサポートされる）
     * @return サポートする場合true。そうでなければfalse
     */
    virtual bool supportsAuxiliaryAudioInput() {
        return false;
    }

    /**
     * SDK内部で行うAuduioSession関連の設定を行うか
     * @warning iOSのみ（Androidでは設定値は用いられない）
     * @return 設定を行う場合true。そうでなければfalse
     */
    virtual bool shouldChangeAudioSessionSettings() {
        return true;
    }

    /**
     * SDKを組み込んだアプリの起動時に、他のアプリで既に再生中のオーディオを中断するか デフォルトはtrue
     * @warning iOSのみ対応。この設定に依らず、動画投稿の録画開始時および生放送の配信開始時には、他のアプリで既に再生中のオーディオは中断される。
     * Cocos2d-xのバージョンによっては、この設定をfalseにして他のオーディオの再生中にアプリを起動した場合に、アプリのBGMが出力されなくなる（アプリの効果音は出力される。これらの挙動はCocos側の設計に依るものである）。
     * 
     * @return 他アプリのオーディオを中断する場合true。そうでなければfalse
     */
    virtual bool shouldInterruptOtherAudio(){
    	return true;
    }

    /**
     * バックグラウンドでの動画アップロードを許可するか
     * @warning iOSのみ（Androidでは設定値は用いられない）
     * @return 許可する場合true。そうでなければfalse
     */
    virtual bool enableBackgroundUpload() {
        return true;
    }

    /**
     * バックグラウンドでのアップロードの自動再開を有効にするか
     * @warning iOSのみ（Androidでは設定値は用いられない）
     * @return 有効にする場合true。そうでなければfalse
     */
    virtual bool shouldAutoResumeUploading() {
        return true;
    }

    /**
     * 生放送配信時のコメント保持数
     * @return コメント保持数
     */
    virtual int maxCapacityForLiveComments() {
        return 200;
    }

    /**
     * ニコニコ生放送配信時にアプリ画面上にコメント描画をするか
     * @return 描画する場合true。そうでなければfalse
     */
    virtual bool enableRenderingCommentsForPublish() {
        return true;
    }

    /**
     * ニコニコ生放送配信時にダミーのコメントを生成するか
     * @return 生成する場合true。そうでなければfalse
     */
    virtual bool shouldGenerateDummyCommentsForPublishing() {
        return false;
    }

    /**
     * ニコニコ生放送配信時にカメラ付きの実況を許可するか
     * @return　許可する場合true。そうでなければfalse
     */
    virtual bool permittedRecordingCameraForPublishing() {
        return true;
    }

    /**
     * Twitterでのシェア機能を許可するかどうか
     * @return　許可する場合true。そうでなければfalse
     */
    virtual bool enableShareTwitter() {
        return true;
    }

    /**
     * Twitterへのシェア時に使用するクライアントID
     * @return クライアントID
     */
    virtual std::string twitterClientId() {
        return "";
    }

    /**
     * Twitterへのシェア時に使用するクライアントシークレット
     * @return クライアントシークレット
     */
    virtual std::string twitterClientSecret() {
        return "";
    }

    /**
     * Facebookでのシェア機能を許可するかどうか
     * @warning iOSのみ（Androidでは設定値は用いられない）
     * @return　許可する場合true。そうでなければfalse
     */
    virtual bool enableShareFacebook() {
        return false;
    }

    /**
     * Facebookへのシェア時に使用するクライアントID
     * @warning iOSのみ（Androidでは設定値は用いられない）
     * @return クライアントID
     */
    virtual std::string facebookClientId() {
        return "";
    }

    /**
     * Facebookへのシェア時に使用するクライアントシークレット
     * @warning iOSのみ（Androidでは設定値は用いられない）
     * @return クライアントシークレット
     */
    virtual std::string facebookClientSecret() {
        return "";
    }

    /**
     * YouTubeへの投稿機能を許可するかどうか
     * @warning iOSのみ（Androidでは設定値は用いられない）
     * @return　許可する場合true。そうでなければfalse
     */
    virtual bool enableShareYouTube() {
        return false;
    }

    /**
     * YouTubeへの投稿時に使用するクライアントID
     * @warning iOSのみ（Androidでは設定値は用いられない）
     * @return クライアントID
     */
    virtual std::string youTubeClientId() {
        return "";
    }

    /**
     * YouTubeへの投稿時に使用するクライアントシークレット
     * @warning iOSのみ（Androidでは設定値は用いられない）
     * @return クライアントシークレット
     */
    virtual std::string youTubeClientSecret() {
        return "";
    }

    /**
     * 再生される音源が全て8bitであるか
     * @warning Androidのみ（iOSでは設定値は用いられない）
     * @return 音源が全て8bitである場合true。そうでなければfalse
     */
    virtual bool audio8bitOnly() {
        return false;
    }
};
}

#endif
