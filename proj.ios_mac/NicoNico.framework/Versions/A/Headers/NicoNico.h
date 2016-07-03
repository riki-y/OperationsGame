//
//  NicoNico.h
//  NicoNicoSDK
//
//  Copyright (c) 2014 Dwango. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NicoNicoConstants.h"
#import "NicoNicoUser.h"
#import "NicoNicoUploadVideo.h"
#import "NicoNicoCamera.h"
#import "NicoNicoCapture.h"
#import "NicoNicoPublisher.h"
#import "NicoNicoComment.h"

/**
  NicoNicoオブジェクトにより実行される録画、アップロード等の状態を受けとるためのプロトコル
 
  [NicoNico setDelegate:] または [NicoNico setDelegate:parentRootViewController:] で通知を受け取るオブジェクトを指定する。
 */
@protocol NicoNicoDelegate <NSObject>
@optional

/// -----------------------------------------------
/// @name ダイアログ表示通知
/// -----------------------------------------------

/// niconico関連ダイアログが表示される直前に実行
- (void)niconicoWillShowView;
/// niconico関連ダイアログが表示された直後に実行
- (void)niconicoDidShowView;
/// niconico関連ダイアログが非表示になる直前に実行
- (void)niconicoWillHideView;
/// niconico関連ダイアログが非表示になった直後に実行
- (void)niconicoDidHideView;

/// -----------------------------------------------
/// @name チャイルドビュー表示通知
/// -----------------------------------------------

/**
 * niconico関連のチャイルドビューが表示される直前に実行
 * @param UIView チャイルドビューを返す
 */
- (void)niconicoWillShowChildView:(UIView*)view;
/**
 * niconico関連のチャイルドビューが表示された直後に実行
 * @param UIView チャイルドビューを返す
 */
- (void)niconicoDidShowChildView:(UIView*)view;
/**
 * niconico関連のチャイルドビューのframeが変更される直前に実行
 * @param UIView チャイルドビューを返す
 * @param CGRect 変更後のチャイルドビューのフレームを返す
 */
- (void)niconicoWillChangeChildView:(UIView*)view toFrame:(CGRect)frame;
/**
 * niconico関連のチャイルドビューのframeが変更された直後に実行
 * @param UIView チャイルドビューを返す
 * @param CGRect 変更前のチャイルドビューのフレームを返す
 */
- (void)niconicoDidChangeChildView:(UIView*)view fromFrame:(CGRect)frame;
/**
 * niconico関連のチャイルドビューが非表示になる直前に実行
 */
- (void)niconicoWillHideChildView;
/**
 * niconico関連のチャイルドビューが非表示になった直後に実行
 */
- (void)niconicoDidHideChildView;

/// -----------------------------------------------
/// @name キャプチャ通知
/// -----------------------------------------------

/// 録画が開始された際に実行
- (void)niconicoDidStartRecording;
/// 録画が停止された際に実行
- (void)niconicoDidFinishRecording;
/// 録画が一時停止された際に実行
- (void)niconicoDidPauseRecording;
/// 録画が再開された際に実行
- (void)niconicoDidResumeRecording;

/// -----------------------------------------------
/// @name 動画投稿系通知
/// -----------------------------------------------

/// アップロードを開始した際に実行
- (void)niconicoDidStartUploading;
/// アップロードが完了した際に実行
- (void)niconicoDidFinishUploading:(NicoNicoUploadVideo*)video;
/// アップロードの進捗際に実行
- (void)niconicoDidProgressUploading:(CGFloat)progress;

/// -----------------------------------------------
/// @name 生放送配信系通知
/// -----------------------------------------------

/// 配信準備ができた際に実行
- (void)niconicoReadyForPublishing:(NicoNicoPublisher *)publisher;
/// 配信を開始した際に実行
- (void)niconicoDidStartPublishing;
/// 配信を停止した際に実行
- (void)niconicoDidFinishPublishing;
/// 配信を一時停止した際に実行
- (void)niconicoDidPausePublishing;
/// 配信中に通信環境の悪化により送信待ちの状態になった時に実行
- (void)niconicoDidBeginWaitingForPublishing;
/// 番組統計情報が更新された際に実行
- (void)niconicoDidUpdateProgramStatistics:(NicoNicoProgramStatistics *)statistics;
/// 番組経過時間が更新された際に実行
- (void)niconicoDidUpdateElapsedTime:(NSTimeInterval)elapsedTime remainingTime:(NSTimeInterval)remainingTime;
/// 新しく投稿されたコメントを受信した際に実行
- (void)niconicoDidReceiveComment:(NicoNicoComment *)comment;
/// 配信再開以前に投稿されたコメントを受信した際に実行
- (void)niconicoDidReceiveCommentWhileDisconnected:(NicoNicoComment *)comment;

/// -----------------------------------------------
/// @name エラー通知
/// -----------------------------------------------

/**
  NicoNico内でエラーが発生した際に実行
 
  NicoNicoでは録画やアップロード等の遂行が困難になった際、このメソッドを通じてアプリケーションにエラー内容を渡す。
  アプリケーションはこのメソッドを実装してエラーを受取り、ユーザに適切にエラー内容を通知する必要がある。
 
  @warning `NSError`の`localizedDescription`は日本語メッセージのみ。
  生放送配信中にこのメソッドが呼ばれた場合は自動的に配信が一時停止される。
 
  @param error NSErrorオブジェクト。
 */
- (void)niconicoDidFailWithError:(NSError*)error;

@end

/**
  NicoNico動作モード
 
  [NicoNico configurationMode] によって開発モードかリリースモードのどちらかへ切り替えを行う。
 
  開発モード、リリースモードではそれぞれ以下の動作に切り替わる。
 
  |              |ニコニコ動画への投稿  |YouTubeへの投稿       |Twtterへのシェア|Facebookへのシェア|
  |--------------|----------------------|----------------------|----------------|------------------|
  |開発モード    |非公開(自分のみ閲覧可)|非公開(自分のみ閲覧可)|公開            |自分のみ          |
  |リリースモード|公開                  |公開                  |公開            |全員              |
 
  @warning NicoNicoConfigurationRelease での投稿は開発中のアプリ映像が一般に公開されてしまうため、
  開発中は NicoNicoConfigurationRelease での動画投稿は極力行わず、 NicoNicoConfigurationDebug での確認を行うこと。
 
  Twitterへの投稿はツイートの公開設定を非公開にしたアカウントを使い、テスト用動画が公開されてしまわないよう注意すること。
  
  また、Appleによるアプリの審査中にテスト用動画が公開されてしまわない様、注意すること。
 
　 NicoNicoConfigurationDebugの時のみ投稿画面に「非公開で投稿されます」と表示される。
 */
typedef NS_ENUM (NSUInteger, NicoNicoConfigurationMode) {
    /// 開発モード
    NicoNicoConfigurationDebug,
    /// リリースモード
    NicoNicoConfigurationRelease
};

/**
  ニコニコ動画、ニコニコ生放送共通の処理を提供
 */
@interface NicoNico : NSObject 

/// -----------------------------------------------
/// @name SDK情報
/// -----------------------------------------------

/// SDKのバージョン
+ (NSString *)version;

/// -----------------------------------------------
/// @name シングルトンオブジェクトの取得
/// -----------------------------------------------

/// 共通のNicoNicoオブジェクトを取得
+ (instancetype)sharedInstance;

/// -----------------------------------------------
/// @name NicoNicoオブジェクトの設定
/// -----------------------------------------------

/// NicoNicoの各種イベントが通知される NicoNicoDelegate を実装したオブジェクトを設定
@property (nonatomic, weak) id<NicoNicoDelegate> delegate;

/// 各モーダルビューを表示する親となるViewControllerを設定
@property (nonatomic, weak) UIViewController *parentRootViewController;

/**
  NicoNicoDelegateおよび各ダイアログを表示するRootViewControllerを指定
 
  @warning このメソッドは録画処理等を行う前に実行されている必要がある
  @param delegate 通知を受け取るインスタンス
  @param parentRootViewController ダイアログの親となるViewController
 */
- (void)setDelegate:(id<NicoNicoDelegate>)delegate parentRootViewController:(UIViewController*)parentRootViewController;

/**
 動作モードを切り替える
 
 デフォルトは NicoNicoConfigurationDebug 。
 
 @warning 動作モードにより開発中のアプリからの動画投稿やSNS投稿の公開範囲が切り替わる。
 それぞれのモードでの公開範囲については NicoNicoConfigurationMode を参照。
 */
@property (nonatomic, assign) NicoNicoConfigurationMode configurationMode;

/// -----------------------------------------------
/// @name クライアント設定
/// -----------------------------------------------

/**
 * ニコニコOAuthから発行されたClient Id
 */
@property (nonatomic, readonly) NSString *clientId;

/**
 * ニコニコOAuthから発行されたClient Secret
 */
@property (nonatomic, readonly) NSString *clientSecret;

/**
  ニコニコOAuthのClient Id, Client Secretを設定
 
  @param clientId ニコニコOAuthから発行されたClient Id
  @param clientSecret ニコニコOAuthから発行されたClient Secret
 */
- (void)setClientId:(NSString *)clientId clientSecret:(NSString*)clientSecret;

/// -----------------------------------------------
/// @name アカウント認証
/// -----------------------------------------------

/**
 現在ログイン中のユーザー
 
 ログインしていれば NicoNicoUser を返す。ログインしていない場合はnilを返す。
 */
@property (nonatomic, readonly) NicoNicoUser *currentUser;

/**
  未ログイン状態であれば、ログインモーダルビューを立ち上げる
 
  ログインモーダルビューが閉じられた時、もしくは既にログイン済みの場合、completionBlock が実行される。
  ログインに成功した場合はuserに NicoNicoUser がユーザ情報として渡され、
  ログインに失敗もしくはログインが拒否された場合はnilが渡される。
 
  @param completionBlock 処理完了後に実行されるblock
 
  @return ログイン済みの場合、または未ログインの状態でログインモーダルビューが表示された場合はYESを返す。
  @warning 以下のケースではNOが返り、completionBlockでnilが渡される。
  - NicoNicoFeatures で availableServiceType が指定されていない
  - ログイン画面など、他のSDKのモーダルビューが立ち上がっている
  - 配信メニューなど、チャイルドビューが表示されている
 */
- (void)authenticateWithCompletionHandler:(void (^)(NicoNicoUser *user))completionBlock;

/**
  ログアウトを行う
 
  ログアウト処理を実行し、セッションを破棄する。
  
  @return ログアウトが完了した場合はYESを返す
  @warning 以下のケースではNOが返り、ログアウトすることはできない。
  - NicoNicoFeatures で NicoNicoServiceTypeVideo が指定されていない
  - 生放送を配信中
  - 動画を録画中
  - 動画を投稿中
  - ログイン画面など、他のSDKのモーダルビューが立ち上がっている
  - 配信メニューなど、チャイルドビューが表示されている
 */
- (BOOL)destroySession;

/// -----------------------------------------------
/// @name キャプチャ
/// -----------------------------------------------

/**
  NicoNicoCapture オブジェクト。録画処理の制御に用いる
 */
@property (nonatomic, readonly) NicoNicoCapture *capture;

/// -----------------------------------------------
/// @name 生放送配信
/// -----------------------------------------------

@property (nonatomic, readonly) NicoNicoPublisher *publisher;

/// -----------------------------------------------
/// @name カメラ&マイク
/// -----------------------------------------------

/**
  NicoNicoCamera オブジェクト。カメラ制御に用いる
 */
@property (nonatomic, readonly) NicoNicoCamera *camera;

/// -----------------------------------------------
/// @name モーダルビュー
/// -----------------------------------------------

/// niconicoがモーダルビューを表示しているかどうかを返す
@property (nonatomic, readonly, getter = isViewVisible) BOOL viewVisible;

/// -----------------------------------------------
/// @name チャイルドビュー
/// -----------------------------------------------

/// niconicoがチャイルドビューを表示しているかどうかを返す
@property (nonatomic, readonly, getter = isChildViewVisible) BOOL childViewVisible;

/// -----------------------------------------------
/// @name 動画アップロード
/// -----------------------------------------------

/**
 アップロード処理中か
 
 現在、動画のアップロード処理を行っているかどうかを返す。（アップロード準備処理を含む）
 この値がYESの場合、 showUploadView で新たに動画を投稿することはできない。
 
 @warning このフラグはTwitter, Facebookへのシェア、YouTubeへの動画投稿は考慮されない。
 */
@property (nonatomic, assign, readonly, getter = isUploading) BOOL uploading;

/*
 録画した動画が存在するか
 
 既に録画済みの動画が存在するかどうかを返す。
 この値はYESでない場合、 showUploadView で動画を投稿することはできない。
 */
@property (nonatomic, readonly) BOOL recordedMovieExists;

/**
  動画アップロードモーダルビューを表示
 
  このメソッドは以下のコードと同義である。
 
      [niconico showUploadViewWithCategory:NicoNicoCategoryGame
                                     title:@""
                               description:@""
                              editableTags:@[]
                            uneditableTags:@[]];
 
  @return 動画アップロードモーダルビューが表示された場合はYESを返す。
  @warning 以下のケースではNOが返り、動画アップロードモーダルビューを開くことはできない。
  - NicoNicoFeatures で NicoNicoServiceTypeVideo が指定されていない
  - 生放送を配信中
  - 動画を投稿中
  - 録画した映像ファイルがない
  - ログイン画面など、他のSDKのモーダルビューが立ち上がっている
  - 配信メニューなど、チャイルドビューが表示されている
 */
- (BOOL)showUploadView;

/**
  動画アップロードモーダルビューを表示

  録画中、または録画が完了していれば動画アップロードモーダルビューを表示する。
  録画中であれば、自動的に録画を停止する。
 
  @param caterogy       動画の投稿カテゴリ。
                        ユーザが任意に変更することはできない。
  @param title          デフォルト動画タイトル。
                        任意のタイトルを設定できるが動画アップロードモーダルビュー内でユーザが任意に書き換えることが可能。
  @param description    デフォルト動画説明文。
                        任意の説明文を設定できるが動画アップロードモーダルビュー内でユーザが任意に書き換えることが可能。
  @param editableTags   編集可能なデフォルトタグ配列。
                        ここで指定したタグは動画アップロードモーダルビュー内でユーザが任意で編集可能となる。
  @param uneditableTags 編集不可能な固定タグ配列。
                        ここで指定したタグは動画アップロードモーダルビュー内でユーザが編集することはできない。
 
  @return 動画アップロードモーダルビューが表示された場合はYESを返す。
  @warning 以下のケースではNOが返り、動画アップロードモーダルビューを開くことはできない。
  - NicoNicoFeatures で NicoNicoServiceTypeVideo が指定されていない
  - 生放送を配信中
  - 動画を投稿中
  - 指定されたカテゴリが不正
  - 録画した映像ファイルがない
  - ログイン画面など、他のSDKのモーダルビューが立ち上がっている
  - 配信メニューなど、チャイルドビューが表示されている
 */
- (BOOL)showUploadViewWithCategory:(NicoNicoCategory)category
                             title:(NSString *)title
                       description:(NSString*)description
                      editableTags:(NSArray*)editableTags
                    uneditableTags:(NSArray*)uneditableTags;


/// -----------------------------------------------
/// @name 生放送番組作成
/// -----------------------------------------------

/**
 生放送番組作成モーダルビューを表示
 
 このメソッドは以下のコードと同義である。
 
 [niconico showPublishViewWithTitle:@""
                        description:@"" 
                     uneditableTags:@[]];
 
 @return 生放送番組作成モーダルビューが表示された場合はYESを返す。
 @warning 以下のケースではNOが返り、生放送番組作成モーダルビューを開くことはできない。
 - NicoNicoFeatures で NicoNicoServiceTypeLive が指定されていない
 - 生放送を配信中
 - 動画を録画中
 - 動画を投稿中
 - ログイン画面など、他のSDKのモーダルビューが立ち上がっている
 - 配信メニューなど、チャイルドビューが表示されている
 */
- (BOOL)showPublishView;

/**
 生放送番組作成モーダルビューを表示
 
 生放送番組作成モーダルビューを表示する。
 録画中であれば、自動的に録画を停止する。
 
 @param title           デフォルト番組タイトル。
 番組作成画面でのデフォルトの番組タイトルを指定する。番組タイトルは生放送番組作成モーダルビュー内でユーザが任意に書き換えることができる。
 ユーザが任意の番組タイトルに変更した場合、以降この指定は無視される。
 @param description     デフォルト番組説明文。
 番組作成画面でのデフォルトの番組説明文を指定する。番組説明文は生放送番組作成モーダルビュー内でユーザが任意に書き換えることができる。
 ユーザが任意の番組説明文に変更した場合、以降この指定は無視される。
 @param uneditableTags  編集不可能な固定タグ配列。
 生放送番組に付与するタグを指定する。ここで指定したタグはユーザが任意に編集することはできない。
 
 @return 生放送番組作成モーダルビューが表示された場合はYESを返す。
 @warning 以下のケースではNOが返り、生放送番組作成モーダルビューを開くことはできない。
 - NicoNicoFeatures で NicoNicoServiceTypeLive が指定されていない
 - 生放送を配信中
 - 動画を録画中
 - 動画を投稿中
 - ログイン画面など、他のSDKのモーダルビューが立ち上がっている
 - 配信メニューなど、チャイルドビューが表示されている
 */
- (BOOL)showPublishViewWithTitle:(NSString*)title
                     description:(NSString*)description
                  uneditableTags:(NSArray *)uneditableTags;

/**
 配信メニューの表示
 
 生放送配信中に配信メニューを表示する。
 
 @return 配信メニューが表示された場合はYESを返す。
 @warning 以下のケースではNOが返り、配信メニューを開くことはできない。
 - NicoNicoFeatures で NicoNicoServiceTypeLive が指定されていない
 - 生放送を配信中ではない
 - parentRootViewController が設定されていない
 - すでに配信メニューが立ち上がっている
 - ログイン画面など、他のSDKのモーダルビューが立ち上がっている
 - 配信メニューなど、チャイルドビューが表示されている
 */
- (BOOL)showPublishMenu;

/**
 niconicoのポータル画面を表示
 
 niconicoのポータル画面をモーダルビューとして表示する。
 このメソッドは以下のコードと同義である。
 
 [niconico showPortalViewWithPickUpContents:pickUpContents
 programTitle:@""
 description:@""
 uneditableTags:@[]];
 
 @param pickUpContents  ピックアップコンテンツとして表示する動画または番組のIDの配列。
 動画の場合は動画IDまたはスレッドID、生放送の場合は生放送IDを指定することができる。
 ここで指定した動画及び番組が、ポータルのトップ画面でピックアップコンテンツとして表示される。
 
 @return ポータル画面が表示された場合はYESを返す。
 @warning 以下のケースではNOが返り、配信メニューを開くことはできない。
 - NicoNicoFeatures で availableServiceType が指定されていない
 - 生放送を配信中
 - 動画を録画中
 - ログイン画面など、他のSDKのモーダルビューが立ち上がっている
 - 配信メニューなど、チャイルドビューが表示されている
 */
- (BOOL)showPortalViewWithPickUpContents:(NSArray*)pickUpContents;

/**
 niconicoのポータル画面を表示
 
 niconicoのポータル画面をモーダルビューとして表示する。
 ポータル画面内には生放送開始ボタンがあり、ポータル画面から生放送番組作成モーダルビューを表示することもできる
 
 @param pickUpContents  ピックアップコンテンツとして表示する動画または番組のIDの配列。
 動画の場合は動画IDまたはスレッドID、生放送の場合は生放送IDを指定することができる。
 ここで指定した動画及び番組が、ポータルのトップ画面のピックアップエリアに表示される。
 @param title           デフォルト番組タイトル。
 番組作成画面でのデフォルトの番組タイトルを指定する。番組タイトルは生放送番組作成モーダルビュー内でユーザが任意に書き換えることができる。
 ユーザが任意の番組タイトルに変更した場合、以降この指定は無視される。
 @param description     デフォルト番組説明文。
 番組作成画面でのデフォルトの番組説明文を指定する。番組説明文は生放送番組作成モーダルビュー内でユーザが任意に書き換えることができる。
 ユーザが任意の番組説明文に変更した場合、以降この指定は無視される。
 @param uneditableTags  編集不可能な固定タグ配列
 生放送番組に付与するタグを指定する。ここで指定したタグはユーザが任意に編集することはできない。
 
 @return ポータル画面が表示された場合はYESを返す。
 
 @warning 以下のケースではNOが返り、配信メニューを開くことはできない。
 - NicoNicoFeatures で availableServiceType が指定されていない
 - 生放送を配信中
 - 動画を録画中
 - ログイン画面など、他のSDKのモーダルビューが立ち上がっている
 - 配信メニューなど、チャイルドビューが表示されている
 */
- (BOOL)showPortalViewWithPickUpContents:(NSArray*)pickUpContents
                            programTitle:(NSString*)title
                             description:(NSString*)description
                          uneditableTags:(NSArray *)uneditableTags;

@end

#if defined __cplusplus
extern "C" {
#endif

/**
 外部音声入力の開始
 
 動画や生放送の音声にミキシングする、外部音声データの入力を開始する。
 
 @param sampleRate  音声データのサンプリング周波数（Hz単位）
 @param channels  音声データのチャンネル数（1=モノラル、2=ステレオ）
 @return 成功時には0、失敗時には非0を返す。
 */
int NicoNicoStartAuxiliaryAudioInput(int sampleRate, int channels);

/**
 外部音声入力の音声データ追加
 
 動画や生放送の音声にミキシングする、外部音声データを追加する。
 
 @param data  音声データ先頭のポインタ。音声データは符号付16bit長、かつステレオデータの場合はインターリーブ形式であること。
 @param count  音声データの個数。例として、44100Hzのステレオデータで1秒間の場合、88200となる。
 @return 成功時には0、失敗時には非0を返す。
 */
int NicoNicoAddAuxiliaryAudioInputData(const short* data, unsigned int count);

/**
 外部音声入力の停止
 
 動画や生放送の音声にミキシングする、外部音声データの入力を停止する。
 
 @return 成功時には0、失敗時には非0を返す。
 */
int NicoNicoStopAuxiliaryAudioInput();

#if defined __cplusplus
}; // extern "C"
#endif

