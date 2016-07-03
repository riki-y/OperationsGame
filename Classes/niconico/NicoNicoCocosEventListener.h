#include "NicoNicoCocosProgramStatistics.h"
#include "NicoNicoCocosComment.h"
#include "NicoNicoCocosUploadVideo.h"
#include "NicoNicoCocosError.h"
#include "NicoNicoCocosRect.h"
#include "NicoNicoCocosSize.h"
#include "NicoNicoCocosProgramStatistics.h"

#ifndef NICONICOCOCOSEVENTLISTENER_H_
#define NICONICOCOCOSEVENTLISTENER_H_

namespace niconico {

/**
 * NicoNico関連のイベントを受け取るためのイベントリスナ
 */
class NicoNicoCocosEventListener {
 public:
    virtual ~NicoNicoCocosEventListener() {
    };
    /**
     * niconico関連ダイアログが表示される直前に実行
     */
    virtual void niconicoWillShowView() {
        
    };

    /**
     * niconico関連ダイアログが表示された直後に実行
     */
    virtual void niconicoDidShowView() {
        
    };

    /**
     * niconico関連ダイアログが非表示になる直前に実行
     */
    virtual void niconicoWillHideView() {
        
    };

    /**
     * niconico関連ダイアログが非表示になった直後に実行
     */
    virtual void niconicoDidHideView() {
        
    };

    /**
     * niconico関連のチャイルドビューが表示される直前に実行
     */
    virtual void niconicoWillShowChildView() {
        
    };

    /**
     * niconico関連のチャイルドビューが表示された直後に実行
     */
    virtual void niconicoDidShowChildView() {
        
    };

    /**
     * niconico関連のチャイルドビューのframeが変更される直前に実行
     * @warning iOSのみ（Androidでは呼ばれない）
     * @param to 変更される予定のチャイルドビューの占める短形領域
     * @param from 現在のチャイルドビューの占める短形領域
     */
    virtual void niconicoWillChangeChildViewFrame(NicoNicoCocosRect to, NicoNicoCocosRect from) {
        
    };

    /**
     * niconico関連のチャイルドビューのframeが変更された直後に実行
     * @warning iOSのみ（Androidでは呼ばれない）
     * @param to 変更された後のチャイルドビューの占める短形領域
     * @param from 変更される前のチャイルドビューの占める短形領域
     */
    virtual void niconicoDidChangeChildViewFrame(NicoNicoCocosRect to, NicoNicoCocosRect from) {
        
    };

    /**
     * niconico関連のチャイルドビューが非表示になる直前に実行
     */
    virtual void niconicoWillHideChildView() {
        
    };

    /**
     * niconico関連のチャイルドビューが非表示になった直後に実行
     */
    virtual void niconicoDidHideChildView() {
        
    };

    /**
     * 録画が開始された際に実行
     * @warning iOSのみ（Androidでは呼ばれない）
     */
    virtual void niconicoDidStartRecording() {
        
    };

    /**
     * 録画が停止された際に実行
     * @warning iOSのみ（Androidでは呼ばれない）
     */
    virtual void niconicoDidFinishRecording() {
        
    };

    /**
     * 録画が一時停止された際に実行
     * @warning iOSのみ（Androidでは呼ばれない）
     */
    virtual void niconicoDidPauseRecording() {
        
    };

    /**
     * 録画が再開された際に実行
     * @warning iOSのみ（Androidでは呼ばれない）
     */
    virtual void niconicoDidResumeRecording() {
        
    };

    /**
     * アップロードを開始した際に実行
     * @warning iOSのみ（Androidでは呼ばれない）
     */
    virtual void niconicoDidStartUploading() {
        
    };

    /**
     * アップロードが完了した際に実行
     * @warning iOSのみ（Androidでは呼ばれない）
     * @param video 投稿動画
     */
    virtual void niconicoDidFinishUploading(NicoNicoCocosUploadVideo video) {
        
    };

    /**
     * アップロードの進捗際に実行
     * @warning iOSのみ（Androidでは呼ばれない）
     * @param progress 進捗(`0.0`-`1.0`)
     */
    virtual void niconicoDidProgressUploading(float progress) {
        
    };

    /**
     * 配信準備ができた際に実行
     */
    virtual void niconicoReadyForPublishing() {
        
    };

    /**
     * 配信を開始した際に実行
     */
    virtual void niconicoDidStartPublishing() {
        
    };

    /**
     * 配信を停止した際に実行
     */
    virtual void niconicoDidFinishPublishing() {
        
    };

    /**
     * 配信を一時停止した際に実行
     */
    virtual void niconicoDidPausePublishing() {
        
    };

    /**
     * 配信中に通信環境の悪化により送信待ちの状態になった時に実行
     */
    virtual void niconicoDidBeginWaitingForPublishing() {
        
    };

    /**
     * 番組統計情報が更新された際に実行
     * @param statistics 番組統計情報
     */
    virtual void niconicoDidUpdateProgramStatistics(NicoNicoCocosProgramStatistics statistics) {
        
    };

    /**
     * 番組経過時間が更新された際に実行
     * @param elapsedtime 経過時間（ミリ秒）
     * @param remainingTime 残り時間（ミリ秒）
     */
    virtual void niconicoDidUpdateElapsedTime(int64_t elapsedtime, int64_t remainingTime) {
        
    };
    
    /**
     * 配信者コメントの投稿が完了した際に実行
     */
    virtual void niconicoDidPostBroadcasterComment() {
        
    };

    /**
     * 配信者コメントの投稿に失敗した際に実行
     * @param error エラー
     */
    virtual void niconicoDidFailPostingBroadcasterComment(NicoNicoCocosError error) {
        
    };

    /**
     * 新しく投稿されたコメントを受信した際に実行
     * @param comment コメント
     */
    virtual void niconicoDidReceiveComment(NicoNicoCocosComment comment) {
        
    };

    /**
     * 配信再開以前に投稿されたコメントを受信した際に実行
     * @param comment コメント
     */
    virtual void niconicoDidReceiveCommentWhileDisconnected(NicoNicoCocosComment comment) {
        
    };

    /**
     * NicoNico内でエラーが発生した際に実行
     * @param error エラー
     */
    virtual void niconicoDidFailWithError(NicoNicoCocosError error) {
        
    };

    /**
     * カメラの接続が開始された際に実行
     * @warning iOSのみ（Androidでは呼ばれない）
     */
    virtual void niconicoCameraDidStartSession() {
        
    };

    /**
     * カメラの接続が停止された際に実行
     * @warning iOSのみ（Androidでは呼ばれない）
     */
    virtual void niconicoCameraDidStopSession() {
        
    };

    /**
     * ログイン処理が完了した時に実行
     * @param user ユーザー
     */
    virtual void niconicoDidFinishAuthenticate(NicoNicoCocosUser user) {
        
    };
};

}

#endif
