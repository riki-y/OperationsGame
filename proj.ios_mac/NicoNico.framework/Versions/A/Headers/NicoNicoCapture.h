//
//  NicoNicoCapture.h
//  NicoNicoSDK
//
//  Copyright (c) 2014 Dwango. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <Metal/Metal.h>

/**
  スクリーン、オーディオの録画を行う
 */
@interface NicoNicoCapture : NSObject

/// -----------------------------------------------
/// @name 録画設定
/// -----------------------------------------------

/**
 録画映像のフレームレート
 
 録画する映像データのフレームレートを設定する。
 
 指定できるフレームレートは`1`から録画映像のフレームレートはアプリケーションのフレームレートまでとなる。
 それ以上の値を設定しても録画映像のフレームレートがアプリケーションのフレームレートを上回ることはない。
 
 デフォルトは`30`。
 */
@property (nonatomic, readwrite, assign) UInt32 framesPerSecond;

/// -----------------------------------------------
/// @name 録画制御
/// -----------------------------------------------

/// 録画中かどうかを返す
@property (nonatomic, readonly, getter = isRecording) BOOL recording;

/**
  録画の開始

  録画を開始する。
 
  @warning 本メソッドを実行すると、それまでに保存済みの録画内容が全て破棄される。
 */
- (BOOL)startRecording;

/**
  録画の停止
 
  録画を停止する。
 
  @deprecated in version 1.03

  @warning 録画の停止処理は内部的に非同期で行われるため、このメソッドを実行直後、直ちに recording が NO になることはない。
  録画の停止を正しく取得するには、 [NicoNicoCaptureDelegate niconicoCaptureDidFinishRecording] または、 [NicoNico niconicoDidFinishRecording] を用いる。
 */
- (BOOL)stopRecording __attribute((deprecated("use method stopRecordingWithCompletionHandler: instead")));

/**
 録画の停止
 
 録画を停止する。
 
 @param completionHandler 録画が完了した際に実行される処理
 
 @warning 録画の停止処理は内部的に非同期で行われるため、このメソッドを実行直後、直ちに recording が NO になることはない。
 録画の停止を正しく取得するには、 [NicoNicoCaptureDelegate niconicoCaptureDidFinishRecording] 、 [NicoNico niconicoDidFinishRecording] または、 completionHandler を用いる。
 */
- (BOOL)stopRecordingWithCompletionHandler:(void (^)())completionHandler;

/**
  録画の一時停止
 
  録画を一時停止する。
  録画の一時停止を再開させるには resumeRecording を実行する。
 */
- (BOOL)pauseRecording;

/**
  録画の再開
 
  録画処理を再開する。
 */
- (BOOL)resumeRecording;

/**
 画面キャプチャのコマンド追加

 対象のコマンドバッファに画面キャプチャのコマンドを追加する。
 
 @param commandBuffer 追加対象のコマンドバッファ
 */
- (void)addMetalCommands:(id<MTLCommandBuffer>)commandBuffer;

@end
