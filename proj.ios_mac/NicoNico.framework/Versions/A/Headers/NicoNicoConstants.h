//
//  NicoNicoConstants.h
//  NicoNicoSDK
//
//  Copyright (c) 2014 Dwango. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>

/// -----------------------------------------------
/// @name blocks
/// -----------------------------------------------

/// 進捗通知ハンドラ
typedef void (^NicoNicoProgressHandler)(float progress);

/// アプリ側へのマイク音声の引き渡しに使用するコールバック関数
typedef void (* NicoNicoMicrophoneCaptureCallback)(UInt32 numberFrames, AudioBufferList* audioBufferList, AudioStreamBasicDescription* audioFormat);

/// -----------------------------------------------
/// @name ニコニコ動画に関する定数
/// -----------------------------------------------

/**
  ニコニコ動画カテゴリ
 
  動画投稿時に設定する動画のカテゴリ
 */
typedef NS_ENUM(NSUInteger, NicoNicoCategory) {
    /// 音楽
    NicoNicoCategoryMusic,
    /// エンターテイメント
    NicoNicoCategoryEntertainment,
    /// アニメ
    NicoNicoCategoryAnime,
    /// ゲーム
    NicoNicoCategoryGame,
    /// ラジオ
    NicoNicoCategoryRadio,
    /// スポーツ
    NicoNicoCategorySport,
    /// 科学
    NicoNicoCategoryScience,
    /// 料理
    NicoNicoCategoryCooking,
    /// 政治
    NicoNicoCategoryPolitics,
    /// 動物
    NicoNicoCategoryAnimal,
    /// 歴史
    NicoNicoCategoryHistory,
    /// 自然
    NicoNicoCategoryNature,
    /// ニコニコ動画講座
    NicoNicoCategoryLecture,
    /// 演奏してみた
    NicoNicoCategoryPlay,
    /// 歌ってみた
    NicoNicoCategorySing,
    /// 踊ってみた
    NicoNicoCategoryDance,
    /// 描いてみた
    NicoNicoCategoryDraw,
    /// ニコニコ技術部
    NicoNicoCategoryNicoTech,
    /// アイドルマスター
    NicoNicoCategoryIdolMaster,
    /// 東方
    NicoNicoCategoryToho,
    /// VOCALOID
    NicoNicoCategoryVocaloid,
    /// 例のアレ
    NicoNicoCategoryAre,
    /// 日記
    NicoNicoCategoryDiary,
    /// その他
    NicoNicoCategoryOther,
    /// ニコニコインディーズ
    NicoNicoCategoryNicoNicoIndies,
    /// 旅行
    NicoNicoCategoryTravel,
    /// 車載動画
    NicoNicoCategoryDrive,
    /// ニコニコ手芸部
    NicoNicoCategoryHandcraft,
    /// 作ってみた
    NicoNicoCategoryMake,
    /// R-18（※このカテゴリでの投稿はできません）
    NicoNicoCategoryR18
};

/// -----------------------------------------------
/// @name エラードメイン
/// -----------------------------------------------

/// 録画に関するエラードメイン
extern NSString *const NicoNicoCaptureErrorDomain;
/// カメラ・マイクに関するエラードメイン
extern NSString *const NicoNicoCameraErrorDomain;
/// オーディオに関するエラードメイン
extern NSString *const NicoNicoAudioErrorDomain;
/// 動画アップロードに関するエラードメイン
extern NSString *const NicoNicoUploadErrorDomain;
/// 生放送の配信に関するエラードメイン
extern NSString *const NicoNicoPublisherErrorDomain;

/// -----------------------------------------------
/// @name エラーコード
/// -----------------------------------------------

/**
 録画に関するエラーコード
 */
typedef NS_ENUM(NSUInteger, NicoNicoCaptureErrorCode) {
    /// ストレージ空き容量が不足している
    NicoNicoCaptureErrorCodeNotEnoughStorageFreeSpace = 1000,
    /// 映像キャプチャの初期化に失敗した
    NicoNicoCaptureErrorCodeScreenCaptureInitializeFailed,
    /// 映像キャプチャを中止した
    NicoNicoCaptureErrorCodeScreenCaptureSuspension
};

/**
 カメラ・マイクに関するエラーコード
 */
typedef NS_ENUM(NSUInteger, NicoNicoCameraErrorCode) {
    /// 録音・録画に対応したデバイスが搭載されていない
    NicoNicoCameraErrorCodeNoAvailableDevice = 1000,
    /// プライバシー設定によりカメラの利用が許可されていない
    NicoNicoCameraErrorCodeCameraRecordingNotPermitted,
    /// プライバシー設定によりマイクの利用が許可されていない
    NicoNicoCameraErrorCodeMicrophoneRecordingNotPermitted,
    /// カメラの初期化に失敗した
    NicoNicoCameraErrorCodeStartCameraSessionFail,
    /// マイクの初期化に失敗した
    NicoNicoCameraErrorCodeStartMicrophoneSessionFail,
    /// マイクの終了に失敗した
    NicoNicoCameraErrorCodeStopMicrophoneSessionFail,
    /// カメラ映像のレンダリングに失敗した
    NicoNicoCameraErrorCodeCameraRenderingFail,
    /// マイク音声のレンダリングに失敗した
    NicoNicoCameraErrorCodeMicrophoneRenderingFail
};

/**
 オーディオに関するエラーコード
 */
typedef NS_ENUM(NSUInteger, NicoNicoAudioErrorCode) {
    /// ミキサーの初期化に失敗
    NicoNicoAudioErrorCodeMixerInitializeFailed = 1000,
    /// ミキサー接続状況が更新されない
    NicoNicoAudioErrorCodeAUGraphNodeInteractionFail,
    /// AUGraph音源の開始に失敗
    NicoNicoAudioErrorCodeStartAudioSourceFail,
    /// AUdioUnit,AUGraphのコールバックの設定に失敗
    NicoNicoAudioErrorCodeSetCallbackForAudioUnitAndAUGraphFail,
    /// ミキサー出力のレンダリングに失敗
    NicoNicoAudioErrorCodeMixerRenderingFail,
    /// ミキサーの始動に失敗
    NicoNicoAudioErrorCodeStartMixerFail,
    /// ミキサーの停止に失敗
    NicoNicoAudioErrorCodeStopMixerFail,
    /// ミキサーの接続状態の更新に失敗
    NicoNicoAudioErrorCodeUpdateMixerFail,
    /// 復帰時のリスタートに失敗
    NicoNicoAudioErrorCodeRestartFail,
    /// ソースとバッファが紐付けられていない
    NicoNicoAudioErrorCodeAudioBufferIsNotAssigned,
    /// ミキサから音源を切り離せない
    NicoNicoAudioErrorCodeAUGraphRemoveNodeFail,
    /// 音源のつなぎ込みに失敗
    NicoNicoAudioErrorCodeAudioSourceConnectionFail,
    /// 静的な音声データを読み出せない
    NicoNicoAudioErrorCodeReadStaticAudioDataFail,
    /// AUGraph音源の初期化に失敗
    NicoNicoAudioErrorCodeAUGraphInitializeFailed,
    /// AUGraph音源のレンダリングに失敗
    NicoNicoAudioErrorCodeAUGraphRenderingFail,
    /// オーディオセッションの活性化に失敗
    NicoNicoAudioErrorCodeSetActiveAudioSessionFailed,
    /// オーディオカテゴリの設定に失敗
    NicoNicoAudioErrorCodeSetAudioCategoryFailed,
    /// AAC変換の初期化に失敗
    NicoNicoAudioErrorCodeAudioConverterInitializeFailed,
    /// AAC変換の途中で失敗
    NicoNicoAudioErrorCodeAudioConversionFailed,
};

/**
 動画アップロードに関するエラーコード
 */
typedef NS_ENUM(NSUInteger, NicoNicoUploadErrorCode) {
    /// アップロード処理中の内部エラーが発生した
    NicoNicoUploadErrorCodeInternalError = 1000,
    /// アップロード認証処理に失敗した
    NicoNicoUploadErrorCodeAuthFailed,
    /// アップロード処理がキャンセルされた
    NicoNicoUploadErrorCodeCancelled,
    /// 動画の変換処理にエラーが発生した
    NicoNicoUploadErrorCodeExportSessionError,
    /// 変換状況を確認中にエラーが発生した
    NicoNicoUploadErrorCodeUploadStatusInternalError,
    /// 他の動画のアップロードを既に行っている
    NicoNicoUploadErrorCodeUploadStatusEncodingOtherError,
    /// Twitterへのシェア中にエラーが発生した
    NicoNicoUploadErrorCodeShareTwitterError,
    /// Fecebookへのシェア中にエラーが発生した
    NicoNicoUploadErrorCodeShareFacebookError,
    /// YouTubeへの投稿中にエラーが発生した
    NicoNicoUploadErrorCodeShareYouTubeError
};

/**
 生放送の配信に関するエラーコード
 */
typedef NS_ENUM(NSUInteger, NicoNicoPublisherErrorCode) {
    /// 配信の開始に失敗した
    NicoNicoPublisherErrorCodeStartPublishingError = 1000,
    /// 配信中に通信エラーにより配信が中断された
    NicoNicoPublisherErrorCodeDisconnectedError,
    /// 番組の終了に失敗した
    NicoNicoPublisherErrorCodeStopPublishingError,
    /// 投稿者コメントに失敗した
    NicoNicoPublisherErrorCodeBroadcasterCommentFailed
};


/// -----------------------------------------------
/// @name NSError.userInfoキー
/// -----------------------------------------------

/// OSStatusコード
extern NSString *const NicoNicoOSStatusKey;


/// -----------------------------------------------
/// 使用フレームワークの種類
/// -----------------------------------------------

/// フレームワーク未指定
extern NSString* const NicoNicoFrameworkTypeUnspecified;


/// -----------------------------------------------
/// niconicoスマホSDKの動作可能端末の判定ポリシー
/// -----------------------------------------------

/// 動作未検証の端末によるSDK機能の利用を禁止する
extern NSString* const NicoNicoSupportValidationPolicyStrict;

/// 動作未検証の端末によるSDK機能の利用を許可する
extern NSString* const NicoNicoSupportValidationPolicyPermissive;

