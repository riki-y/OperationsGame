//
//  NicoNicoCamera.h
//  NicoNicoSDK
//
//  Copyright (c) 2014 Dwango. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AVFoundation/AVFoundation.h"

/**
 * NicoNicoCamera からのイベントを受け取る
 */
@protocol NicoNicoCameraDelegate <NSObject>
@optional

/// カメラの接続が開始された
- (void)niconicoCameraDidStartSession;

/// カメラの接続が停止された
- (void)niconicoCameraDidStopSession;

@end

/**
 カメラプレビューの配置位置
 
 実況を追加する際、カメラ映像は画面映像の四隅のいずれかに寄せて配置される。
 
 アプリケーションはこの配置の初期値を任意の場所に設定することができる。
 */
typedef NS_ENUM(NSUInteger, NicoNicoCameraOverlapPreviewGravity) {
    /// 画面左上
    NicoNicoCameraOverlapPreviewGravityTopLeft,
    /// 画面右上
    NicoNicoCameraOverlapPreviewGravityTopRight,
    /// 画面左下
    NicoNicoCameraOverlapPreviewGravityBottomLeft,
    /// 画面右下
    NicoNicoCameraOverlapPreviewGravityBottomRight
};

/**
 セッション中のカメラプレビューの任意位置指定の無効化
 
 [NicoNicoCamera previewPositionX] 、 [NicoNicoCamera previewPositionY] に設定できる。
 
 この値を指定した場合、セッション中のカメラプレビューに任意位置への配置が無効化され、
 座標は [NiconicoCamera previewGravity] の設定が適応される
 */
extern CGFloat const NicoNicoCameraPreviewPositionNegative;

/**
  フロントカメラおよびマイクの制御を行う
 */
@interface NicoNicoCamera : NSObject

/// -----------------------------------------------
/// @name delegate
/// -----------------------------------------------

/**
 NicoNicoCamera からのイベントを通知するオブジェクトを指定
 */
@property (nonatomic, weak) id<NicoNicoCameraDelegate> delegate;

/// -----------------------------------------------
/// @name セッション制御
/// -----------------------------------------------

/// セッションが開始されているか
@property (nonatomic, readonly, getter = isRunning) BOOL running;

/**
 セッションを開始する
 
 カメラおよびマイクのセッションを開始する。
 @warning 生放送配信中はアプリケーション側からカメラおよびマイクのセッションを開始することはできない。
 */
- (void)startSession;

/**
 セッションを停止する
 
 カメラおよびマイクのセッションを停止する。
 @warning 生放送配信中はアプリケーション側からカメラおよびマイクのセッションを停止することはできない。
 */
- (void)stopSession;

/// -----------------------------------------------
/// @name 録画制御
/// -----------------------------------------------

/// 録画中かどうか
@property (nonatomic, readonly, getter = isRecording) BOOL recording;

/// -----------------------------------------------
/// @name カメラ
/// -----------------------------------------------

/**
 カメラをサポートしているか
 
 実行している端末がカメラをサポートしているかを返す。
 */
@property (nonatomic, readonly, getter = isVideoRecordingSupported) BOOL videoRecordingSupported;

/**
 カメラ映像のFPS

 カメラ映像のフレームレートを設定する。範囲は`0`〜`60`
 
 デフォルトは 10。
 */
@property (nonatomic, readwrite, assign) UInt32 framesPerSecond;

/// -----------------------------------------------
/// @name マイク
/// -----------------------------------------------

/**
 マイクをサポートしているか
 
 実行している端末がマイクをサポートしているかを返す。
 */
@property (nonatomic, readonly, getter = isAudioRecordingSupported) BOOL audioRecordingSupported;

/**
  マイクのゲイン設定
 
  マイクのゲイン設定を行う。指定できる範囲は`0.0`〜`1.0`
 
  デフォルトは`0.5`
 
  @warning 投稿動画の録画において、iPad 2、iPad mini等の一部デバイスでは本設定が無視される。
  生放送においては、このような制限はない。
 */
@property (nonatomic, readwrite, assign) Float32 microphoneGain;


/**
 マイクのミュート設定
 
 このプロパティをYESに設定した場合、マイク音声が録音されない。
 
 デフォルトはNO。
 */
@property (nonatomic, readwrite, assign) BOOL microphoneMute;


/**
  マイクのみ有効にするか

  このプロパティをYESに設定した場合、カメラの録画を行わず、マイク音声のみ録音を行う。
 
  デフォルトはNO。
 */
@property (nonatomic, readwrite) BOOL audioOnly;

/// -----------------------------------------------
/// @name カメラプレビュー設定
/// -----------------------------------------------

/**
  カメラプレビューの表示するか
 
  セッション中、カメラプレビューを画面上に表示するかの設定を行う。
 
  デフォルトはYES。
 */
@property (nonatomic, readwrite) BOOL previewVisible;

/**
 カメラプレビューの表示位置
 
 カメラプレビューを画面上のどの位置に配置するかを設定する。
 
 previewPositionX かつ previewPositionY の値が NicoNicoCameraPreviewPositionNegative 以外の値のとき、
 セッション中のカメラプレビュー時にはこの値は無視される。
 
 デフォルトは NicoNicoCameraOverlapPreviewGravityTopLeft 。
 */
@property (nonatomic, readwrite) NicoNicoCameraOverlapPreviewGravity previewGravity;

/**
 カメラプレビューと画面端からのマージン

 カメラプレビューを画面端からどの程度マージンを空けるかを設定する。
 
 previewPositionX かつ previewPositionY の値が NicoNicoCameraPreviewPositionNegative 以外の値のとき、
 セッション中のカメラプレビュー時にはこの値は無視される。ボーダー幅は考慮されない。
 
 デフォルトは `16.0`。
 */
@property (nonatomic, readwrite) CGFloat previewMargin;

/**
  セッション中のカメラプレビューのX座標
 
  セッション中のアプリの画面上に表示されるカメラプレビューを描画する際にのみ有効。ボーダー幅は考慮されない。
 
  デフォルトは NicoNicoCameraPreviewPositionNegative 。
 */
@property (nonatomic, readwrite) CGFloat previewPositionX;

/**
  セッション中のカメラプレビューのY座標
 
  セッション中のアプリの画面上に表示されるカメラプレビューを描画する際にのみ有効。ボーダー幅は考慮されない。
 
  デフォルトは NicoNicoCameraPreviewPositionNegative 。
 */
@property (nonatomic, readwrite) CGFloat previewPositionY;

/**
  カメラプレビューの幅
 
  デフォルトは`72.0`
 */
@property (nonatomic, readwrite) CGFloat previewWidth;

/**
  カメラプレビューの高さ
 
  デフォルトは`72.0`
 */
@property (nonatomic, readwrite) CGFloat previewHeight;

/**
 カメラプレビューのボーダー幅
 
 カメラプレビューで表示されるボーダーの幅を設定する。
 
 デフォルトは`3.0`
 */
@property (nonatomic, readwrite) CGFloat previewBorderWidth;

/**
 カメラプレビューのボーダーカラー
 
 カメラプレビューで表示されるボーダーの色を設定する。
 
 デフォルトは [UIColor colorWithRed:1.0f green:1.0f blue:1.0f alpha:1.0f]
 */
@property (nonatomic, strong) UIColor *previewBorderColor;


/**
 カメラプレビュー用のテクスチャIDを設定する
 
 設定したテクスチャにカメラプレビュー画像が書き込まれる
 */
- (void)setPreviewTextureID:(GLuint)textureID;

/**
 カメラプレビューのテクスチャサイズ
 
 カメラプレビューのテクスチャが生成されていない場合 (0, 0) を返す
 */
- (CGSize)previewTextureSize;

/// -----------------------------------------------
/// @name パーミッション
/// -----------------------------------------------

/**
 カメラの使用可否を取得する。
 
 @warning iOS8以降、このメソッドをアプリ初回起動時にはじめて実行した場合、スレッドをブロックする。
 この動作に問題がある場合は、AVCaptureDeviceのrequestAccessForMediaTypeを明示的に実行すること。
 @return BOOL カメラの使用可否
 */
- (BOOL)checkCameraRecordingPermission;

/**
 マイクの使用可否を取得する。
 
 @deprecated in version 1.04

 @warning iOS7以降、このメソッドをアプリ初回起動時にはじめて実行した場合、スレッドをブロックする。
 この動作に問題がある場合は、AVAudioSessionのrequestRecordingPermissionを明示的に実行すること。
 @return BOOL マイクの使用可否
 */
- (BOOL)checkRecordingPermission __attribute((deprecated("use method checkMicrophoneRecordingPermission: instead")));

/**
  マイクの使用可否を取得する。
 
  @warning iOS7以降、このメソッドをアプリ初回起動時にはじめて実行した場合、スレッドをブロックする。
           この動作に問題がある場合は、AVAudioSessionのrequestRecordingPermissionを明示的に実行すること。
  @return BOOL マイクの使用可否
 */
- (BOOL)checkMicrophoneRecordingPermission;

@end
