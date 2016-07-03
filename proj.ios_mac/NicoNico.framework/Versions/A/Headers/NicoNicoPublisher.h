//
//  NicoNicoPublisher.h
//  NicoNicoSDK
//
//  Copyright (c) 2014 Dwango. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NicoNicoConstants.h"
#import "NicoNicoPublishProgram.h"
#import "NicoNicoProgramStatistics.h"
#import "NicoNicoCommunity.h"
#import "NicoNicoVideoCompositionLayout.h"

/**
 生放送配信時の品質設定
 */
typedef NS_ENUM(NSUInteger, NicoNicoPublisherQuality) {
    /// 最低品質
    NicoNicoPublisherQualityWorst = 0,
    /// 低品質
    NicoNicoPublisherQualityWorse,
    /// 中間品質
    NicoNicoPublisherQualityMidium,
    /// 高品質
    NicoNicoPublisherQualityBetter,
    /// 最高品質
    NicoNicoPublisherQualityBest,
};

/**
 生放送配信時のカメラ設定

 生放送配信におけるカメラおよびマイクの使用可否を設定する。
 */
typedef NS_ENUM(NSUInteger, NicoNicoPublisherCameraMode) {
    /// カメラおよびマイクを使用しない。
    NicoNicoPublisherCameraModeOff,
    /// カメラのみを使用し、マイクを使用しない
    NicoNicoPublisherCameraModeCameraOnly,
    /// マイクのみを使用し、カメラを使用しない
    NicoNicoPublisherCameraModeMicrophoneOnly,
    /// カメラおよびマイクを使用する
    NicoNicoPublisherCameraModeBoth
};


/**
 生放送の配信機能を提供する
 */
@interface NicoNicoPublisher : NSObject

/// -----------------------------------------------
/// @name 配信設定
/// -----------------------------------------------

/**
 品質設定

 配信時の品質の設定を行う。
 @warning qualityをセットしたあとに restartPublishing メソッドを呼ばないと実際の配信には反映されない。
 
 デフォルトは NicoNicoPublisherQualityBest
 */
@property (nonatomic, assign) NicoNicoPublisherQuality quality;

/**
 カメラ・マイク設定
 
 配信時のカメラおよびマイクの使用可否を設定する。
 
 デフォルト値は 番組作成画面でユーザにより指定された設定 に従う。
 @warning cameraModeのセットは処理に時間がかかるため、連続で実行すると動作が重くなることがある。
 cameraModeのセットの完了のコールバックを受け取る場合は setCameraMode:completionHandler: を使うこと
 */
@property (nonatomic, assign) NicoNicoPublisherCameraMode cameraMode;

/**
 配信時のカメラおよびマイクの使用可否を設定する。
 
 @param cameraMode カメラおよびマイクの使用可否設定。
 @param completionHandler カメラ・マイク設定完了のコールバック。
 @warning 本メソッドを連続実行する場合は、completionHandlerの内容が上書きされるため都度completionHandlerの完了まで待つ事。
 */
- (void)setCameraMode:(NicoNicoPublisherCameraMode)cameraMode completionHandler:(void (^)())completionHandler;


/**
 マイクのゲイン設定
 
 マイクのゲイン設定を行う。指定できる範囲は`0.0`〜`1.0`
 
 デフォルトは`0.5`
 */
@property (nonatomic, assign) Float32 microphoneGain;

/**
 生放送中のアプリ音声のボリューム設定
 
 生放送中のアプリ音声のボリューム設定を行う。指定できる範囲は`0.0`〜`1.0`
 
 デフォルトは`0.2`
 
 @warning この設定は生放送中に配信される音声にのみ反映され、端末本体からの音声出力には反映されない。
 */
@property (nonatomic, assign) Float32 liveAudioVolume;


/// -----------------------------------------------
/// @name 配信情報
/// -----------------------------------------------

/**
 配信番組情報
 
 現在配信している番組情報が格納される。
 */
@property (nonatomic, readonly) NicoNicoPublishProgram *program;

/**
 配信番組の経過時間
 
 現在配信している番組の配信開始からの経過時間
 */
@property (nonatomic, readonly) NSTimeInterval elapsedTime;

/**
 配信番組の残り時間
 
 現在配信している番組の配信開始からの残り時間。残り時間が0となると番組は自動的に終了する。
 
 @warning 現行バージョンのニコニコスマホSDKでは配信番組の延長は行えない。
 */
@property (nonatomic, readonly) NSTimeInterval remainingTime;

/// -----------------------------------------------
/// @name コメント
/// -----------------------------------------------

/**
 最新のコメント一覧
 
 配信中の番組に投稿された最新のコメント配列。各要素には NicoNicoComment が格納される。
 コメントが一定数に達すると古いコメントから順に削除される。
 */
@property (nonatomic, strong, readonly) NSArray *latestComments;

/**
 コメントのオーバレイ表示設定
 
 画面上に配信中の番組に投稿されたコメントをニコニコ風にオーバーレイ表示するかを設定する。
 このときコメントを描画する範囲は [commentStageRect] によって設定する。
 
 コメントのオーバーレイ表示を完全に停止させるには NicoNicoFeatures の enableRenderingCommentsForPublish を NO に設定する。
 
 デフォルトは YES
 */
@property (nonatomic, assign) BOOL commentVisible;

/**
 コメントのオーバーレイ表示範囲
 
 画面上に配信中の番組に投稿されたコメントをニコニコ風にオーバーレイ表示する際の表示範囲を指定する。
 
 デフォルトは CGRectNull
 */
@property (nonatomic, assign) CGRect commentStageRect;


/// -----------------------------------------------
/// @name 配信制御
/// -----------------------------------------------

/// 配信中かどうかを返す
@property (nonatomic, readonly, getter = isPublishing) BOOL publishing;

/// 配信処理が一時停止中かどうかを返す
@property (nonatomic, readonly, getter = isPaused) BOOL paused;

/**
 配信の開始
 
 配信処理を開始する。
 @return BOOL 配信開始処理が実行された場合にYESが返る。
 */
- (BOOL)startPublishing;

/**
 配信の再接続
 
 配信の再接続を行う。
 内部的にはpausePublishingのあとにstartPublishingを呼んでいる。
 
 @return BOOL 配信の再接続処理が実行された場合にYESが返る。
 */
- (BOOL)restartPublishing;

/**
 配信の終了

 配信処理を終了し、番組を終了させる。
 @return BOOL 配信終了処理が実行された場合にYESが返る。
 
 @warning 配信処理の終了処理は内部的に非同期で行われるためこのメソッドを実行直後、直ちに [publishing] が NO になることはない。
 配信処理の停止を正しく取得するには、 [NicoNicoDelegate niconicoDidFinishPublishing] を用いる。
 */
- (BOOL)stopPublishing;

/**
 配信の一時停止
 
 配信処理を一時停止し、画面のキャプチャおよび通信を停止する。
 @return BOOL 配信の一時停止処理が実行された場合にYESが返る。
 */
- (BOOL)pausePublishing;

/**
 配信者コメントの投稿。
 
 配信者コメントの投稿を行う。
 
 @param commentText 投稿するコメント文字列
 @param completionHandler 投稿結果を返すコールバック。投稿に成功した場合はerror引数にnilが入り、失敗した場合は失敗内容がerrorに入る。
 @warning 空文字列、1000文字より大きい、または「/」で始まる運営コメントは、エラーが返る
 */
- (void)postBroadcasterCommentText:(NSString*)commentText completionHandler:(void(^)(NSError *error))completionHandler;

/// -----------------------------------------------
/// @name 背景画像合成
/// -----------------------------------------------

/**
 背景画像合成レイアウト
 
 配信映像に合成する背景画像のテクスチャや各画像の配置位置などを設定する。
 nilの場合は映像合成されない。
 
 デフォルトは nil
 */
@property (nonatomic, strong) NicoNicoVideoCompositionLayout *videoCompositionLayout;

@end
