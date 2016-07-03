//
//  NicoNicoFeatures.h
//  NicoNicoSDK
//
//  Copyright (c) 2014年 Dwango. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NicoNicoConstants.h"

/**
 niconicoスマホSDKのサービスタイプ
 
 niconicoスマホSDKから利用できるサービスを指定する
 */
typedef NS_OPTIONS(NSUInteger, NicoNicoAvailableServiceType) {
    NicoNicoServiceTypeLive     = 1 << 0,   // 生放送配信機能を使用可能にする
    NicoNicoServiceTypeVideo    = 1 << 1,   // 動画投稿機能を使用可能にする
};

/**
  NicoNico に対する詳細な動作パラメータを提供する
 
  NicoNico では複雑な設定なくそのまま利用することができるが、
  アプリケーションで詳細に NicoNico の動作をカスタマイズしたい場合、アプリケーション側で NicoNicoFeatures のカテゴリを作成することで、
  NicoNico の動作を柔軟に変更することができる。
 
     @interface NicoNicoFeatures (MyAppSettings)
     @end
 
     @implementation NicoNicoFeatures (MyAppSettings)
 
     #pragma clang diagnostic push
     #pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"
 
     + (UInt64)storageFreeSpaceLimit {
         return 512 * 1024 * 1024          // 空き容量の最低サイズを512MBに変更
     }
 
     + (BOOL)enableShareFacebook {
         return YES;                       // Facebookシェアを有効化
     }

     + (BOOL)facebookClientId {
         return @"facebook_client_id";     // FacebookのClient Idを設定
     }

     + (BOOL)facebookClientSecret {
         return @"facebook_client_secret"; // FacebookのClient Secretを設定
     }
 
     #pragma clang diagnostic pop
 
     @end
  
  @warning NicoNicoFeaturesの値は初期に設定された値が反映される。
  録画や配信など、NicoNicoの機能が動作している最中に動的に変更された場合、動作は保証できない。
 
 */
@interface NicoNicoFeatures : NSObject

/// -----------------------------------------------
/// @name 利用サービス構成設定
/// -----------------------------------------------

/**
 niconicoスマホSDKのサービスタイプ
 
 niconicoスマホSDKから利用できるサービスを指定する。
 生放送配信機能と動画投稿機能のどちらかしか指定しない場合は指定したサービス以外の機能が使用できなくなる。
 また、どちらかしか指定しない場合、ポータルには指定されたサービスのコンテンツのみしか表示されない。
 
 デフォルトは NicoNicoServiceTypeLive。
 */
+ (NicoNicoAvailableServiceType)availableServiceType;

/**
 ログイン画面に新規アカウント作成用のボタンの表示を許可するかどうか。
 
 デフォルトはNO。
 
 @warning 新規アカウント作成ボタンを表示にしたい場合は弊社サポートまでご連絡ください。
 */
+ (BOOL)shouldShowAccountSignupButton;

/**
 使用フレームワークの種類

 niconicoスマホSDKを組み込んだアプリが使用するフレームワークの種類を指定する。
 デフォルトは NicoNicoFrameworkTypeUnspecified。

 @warning SDKの内部処理用につき、変更しないでください。
 */
+ (NSString*)frameworkType;

/**
 niconicoスマホSDKの動作可能端末の判定ポリシー
 
 niconicoスマホSDKの機能を利用可能な端末か否かを判定するためのポリシーを指定する。
 対応端末の判定はniconicoのサーバによって行われ、検証状況により異なる結果を返す場合がある。
 NicoNicoSupportValidationPolicyStrict を設定した場合、動作未検証の端末によるSDK機能の利用を禁止する。
 NicoNicoSupportValidationPolicyPermissive を設定した場合、動作未検証の端末によるSDK機能の利用を許可する。

 デフォルトは NicoNicoSupportValidationPolicyPermissive。
 
 @warning この設定を変更した場合、動作検証が済んでいない新しいOSバージョンや端末などについては、弊社で対応しない限りSDKの機能を利用することができなくなる。
 */
+ (NSString*)supportValidationPolicy;


/// -----------------------------------------------
/// @name 録画設定
/// -----------------------------------------------

/**
  ストレージ空き領域の下限バイト数
 
  NicoNico では録画時にストレージの空き容量が一定のサイズを下回った場合、録画を自動的に停止する。
  このメソッドをオーバーライドすることで、自動停止するサイズを変更することができる。
 
  デフォルトは`256 * 1024 * 1024`(256MB)。
 */
+ (UInt64)storageFreeSpaceLimit;

/// -----------------------------------------------
/// @name オーディオキャプチャ設定
/// -----------------------------------------------

/**
  OpenALのキャプチャ処理をサポートするか
 
  NicoNico を導入することで、OpenALによるオーディオ再生に問題が発生した場合、
  このメソッドをオーバーライドすることで、OpenALのオーディオ再生に対する NicoNico の割込を制御することできる。
  ただし、NOにするとNicoNicoで録画した映像データにOpenALの再生音が含まれなくなる。
 
  デフォルトはYES。

  @warning OpenALのキャプチャ処理を有効にした状態で alSourceQueueBuffers によるストリーム再生を行う際に、音声データをキューに積む処理が追いつかないと "warning: no queued buffers" のような警告ログが出力される。
           この場合、キューに積むバッファのサイズを大きくしたり、バッファの数を増やしたりする事で、この警告ログが出力されないように調整を行う必要がある。また、iOS9以降ではOpenAL自体が非対応となるため、OpenALによるオーディオ再生及びキャプチャ機能の動作は保証できない。(Unityでは非対応）

 */
+ (BOOL) supportsOpenAL;

/**
  AVAudioPlayerのキャプチャ処理をサポートするか
 
  NicoNico を導入することで、AVAudioPlayerによるオーディオ再生に問題が発生した場合、
  このメソッドをオーバーライドすることで、AVAudioPlayerのオーディオ再生に対する NicoNico の割込を制御することできる。
  ただし、NOにすると NicoNico で録画した映像データにAVAudioPlayerの再生音が含まれなくなる。
 
  @warning Unityでは非対応

  デフォルトはYES。
 */
+ (BOOL) supportsAVAudioPlayer;

/**
  AudioUnit(RemoteIO)のキャプチャ処理をサポートするか
 
  NicoNicoを導入することで、AudioUnitによるオーディオ再生に問題が発生した場合、
  このメソッドをオーバーライドすることで、AudioUnitのオーディオ再生に対するNicoNicoの割込を制御することできる。
  ただし、NOにするとNicoNicoで録画した映像データにAudioUnitの再生音が含まれなくなる。

  @warning Unityでは非対応
 
  デフォルトはYES。
 */
+ (BOOL) supportsAudioUnit;


/**
 外部音声の入力ををサポートするか
 
 外部音源（独自オーディオエンジン等）による音声をSDKに入力する場合は、この設定をYESにする。
 YESに設定した場合、supportsOpenAL、supportsAVAudioPlayer、supportsAudioUnitの設定に依らず、これらの音源に対するキャプチャ処理が行われなくなる。
 また、入力された外部音声はNicoNicoで録画した映像データに含まれるが、NicoNicoからスピーカー及びヘッドフォンへの出力は行われない。
 このため、スピーカー及びヘッドフォンへの音声出力は、外部音源側で対応する必要がある。
 
 デフォルトはNO。
 */
+ (BOOL) supportsAuxiliaryAudioInput;


/**
  SDK内部で行うAuduioSession関連の設定を行うか
 
  NicoNicoでは録画開始時にAudioSessionのcategoryを AVAudioSessionCategorySoloAmbient または AVAudioSessionCategoryPlayAndRecord に設定する。
  この処理を行うことで不具合が生じる場合、このメソッドをオーバーライドすることでAudioSessionのカテゴリの変更するかを設定することができる。

  @warning Unityでは非対応
 
  デフォルトはYES。
 
 */
+ (BOOL) shouldChangeAudioSessionSettings;

/**
 SDKを組み込んだアプリの起動時に、他のアプリで既に再生中のオーディオを中断するか
 
 デフォルトはYES。
 
 @warning この設定に依らず、動画投稿の録画開始時および生放送の配信開始時には、他のアプリで既に再生中のオーディオは中断される。
 */
+ (BOOL) shouldInterruptOtherAudio;

/// -----------------------------------------------
/// @name 動画アップロード設定
/// -----------------------------------------------

/**
  バックグラウンドでの動画アップロードを許可するか
 
  NicoNicoのアップロードモーダルビューを動画のアップロード処理中に閉じるか設定する。
 
  YESに設定した場合、アップロード処理の開始直後にモーダルビューが閉じられ、ゲーム再開後も非同期でアップロード処理が継続される。
 
  このときのアップロード処理の進捗や結果は [NicoNicoDelegate niconicoDidProgressUploading:] や [NicoNicoDelegate niconicoDidFinishUploading:] 、
  [NicoNicoDelegate niconicoDidFailWithError:] で取得することができる。
 
  デフォルト値はYES。
 
  @warning バックグラウンドアップロードを有効にすることで、処理を素早くアプリケーションに戻すことができるが、
           アプリケーションのバックグラウンドで巨大なファイルのアップロード処理が行われることになるため、
           性能の低い機種では有効にしない等の対策をとったほうが良い。
 */
+ (BOOL) enableBackgroundUpload;

/**
  バックグラウンドでのアップロードの自動再開を有効にするか
 
  enableBackgroundUpload を有効にした状態で、バックグラウンドでの動画アップロードの処理中にアプリが終了または投稿に失敗したとき、
  次のアプリがフォアグラウンドに入った時に自動でアップロード処理を再開するかを設定できる。
 
  デフォルト値はYES。
 */
+ (BOOL) shouldAutoResumeUploading;

/// -----------------------------------------------
/// @name 生放送配信設定
/// -----------------------------------------------

/**
 生放送配信時のコメント保持数

 生放送配信時に [NicoNicoPublisher latestComments]で参照できるコメント数の最大保持数を設定する。
 ここで指定した値を超えたコメントを取得した場合、古いコメントから順に削除される。
 生放送メニューのコメント一覧に一度に表示されるコメント数はこの値に依存する。
 
 デフォルトは 200。
 */
+ (NSUInteger) maxCapacityForLiveComments;

/**
 ニコニコ生放送配信時にアプリ画面上にコメント描画をするか
 
 YESにした場合、アプリ画面上に視聴者が投稿したコメントが描画される。
 
 デフォルト値はYES。
 */
+ (BOOL)enableRenderingCommentsForPublish;

/**
 ニコニコ生放送配信時にダミーのコメントを生成するか
 
 [NicoNico configurationMode] が NicoNicoConfigurationDebug の時に enableRenderingCommentsForPublish をYESにした場合、ダミーのコメントを生成してアプリ画面上に描画される。
 
 デフォルト値はNO。
 */
+ (BOOL)shouldGenerateDummyCommentsForPublishing;

/**
 ニコニコ生放送配信時にカメラ付きの実況を許可するか
 
 YESにした場合、カメラ付きの実況を行うとアプリ画面上にカメラ映像が表示される。
 カメラ付き実況の切り替えはユーザによって任意に変更することが可能。
 NOにした場合は必ずカメラ無しの実況となる。
 
 デフォルト値はYES。
 */
+ (BOOL)permittedRecordingCameraForPublishing;

/// -----------------------------------------------
/// @name Twitterシェア設定
/// -----------------------------------------------

/**
  Twitterでのシェア機能を許可するかどうか
 
  NicoNicoのアップロードモーダルビューでTwitterへのシェアアイコンを表示するか設定する。
 
  デフォルト値はYES。
 
  @see twitterClientId
  @see twitterClientSecret
  @warning Twitterのシェア機能はSocial.frameworkが存在すればSocial.frameworkを利用し、存在しなければTwitter.frameworkを利用する。
           ユーザがiOSのTwitterアカウント設定を行っておらず、 twitterClientId 、 twitterClientSecret を設定していた場合、
           WebViewと独自のOAuthクライアントを利用する。
 */
+ (BOOL) enableShareTwitter;

/**
 Twitterへのシェア時に使用するClient Id
 
 Twitterへのシェアを行う際に利用するアプリケーションのClient Idを設定する。
 
 通常はSocial.framework、Twitter.frameworkのクライアント機能を用いてTwitterへのシェアを行うが、iOSのTwitterアカウント設定を行っていない場合、
 NicoNico SDKではWebViewと独自のOAuthクライアントを用いて、認証、シェアを行う。
 
 このメソッドをオーバーライドして、アプリケーションがそれぞれ用意したClient Idを設定することで上記機能を利用できる。
 
 デフォルト値は空文字列。
 */
+ (NSString *)twitterClientId;

/**
 Twitterへのシェア時に使用するClient Secret
 
 Twitterへのシェアを行う際に利用するアプリケーションのClient Secretを設定する。
 
 通常はSocial.framework、Twitter.frameworkのクライアント機能を用いてTwitterへのシェアを行うが、iOSのTwitterアカウント設定を行っていない場合、
 NicoNico SDKではWebViewと独自のOAuthクライアントを用いて、認証、シェアを行う。
 
 このメソッドをオーバーライドして、アプリケーションがそれぞれ用意したClient Secretを設定することで上記機能を利用できる。
 
 デフォルト値は空文字列。
 */
+ (NSString *)twitterClientSecret;

/// -----------------------------------------------
/// @name Facebookシェア設定
/// -----------------------------------------------

/**
  Facebookでのシェア機能を許可するかどうか
 
  NicoNicoのアップロードモーダルビューでFacebookへのシェアアイコンを表示するか設定する。
  
  Facebookのシェア機能を有効にするためには、 このメソッドをオーバーライドしてYESを返すようにし、
  facebookClientId 及び facebookClientSecret にアプリケーションがそれぞれFacebookに登録したClient IdとClient Secretを設定する必要がある。
 
  デフォルト値はNO。
 
  @see facebookClientId 
  @see facebookClientSecret
  @warning Facebookのシェア機能はSocial.frameworkが存在すればSocial.frameworkを利用し、存在しなければWebViewと独自のOAuthクライアントを利用する。
 */
+ (BOOL) enableShareFacebook;

/**
  Facebookへのシェア時に使用するClient Id
 
  Facebookでのシェアを行う際はこのメソッドをオーバライドし、アプリケーションが用意したClient Idを設定する必要がある。
 
  デフォルト値は空文字列。
 */
+ (NSString *)facebookClientId;

/**
  Facebookへのシェア時に使用するClient Secret
 
  Facebookでのシェアを行う際はこのメソッドをオーバライドし、アプリケーションが用意したClient Secretを設定する必要がある。
 
  デフォルト値は空文字列。
 */
+ (NSString *)facebookClientSecret;

/// -----------------------------------------------
/// @name YouTube投稿設定
/// -----------------------------------------------

/**
 YouTubeへの投稿機能を許可するかどうか
 
 NicoNicoのアップロードモーダルビューでYouTubeへの投稿アイコンを表示するか設定する。
 
 YouTubeの投稿機能を有効にするためには、 このメソッドをオーバーライドしてYESを返すようにし、
 youTubeClientId 及び youTubeClientSecret にアプリケーションがそれぞれYouTubeに登録したClient IdとClient Secretを設定する必要がある。
 
 デフォルト値はNO。
 
 @see youTubeClientId
 @see youTubeClientSecret
 */
+ (BOOL) enableShareYouTube;

/**
 YouTubeへの投稿時に使用するClient Id
 
 YouTubeへ投稿を行う際に利用するアプリケーションのClient Idを設定できる。

 YouTubeへの投稿を行う際はこのメソッドをオーバライドし、アプリケーションが用意したClient Idを設定する必要がある。
 
 デフォルト値は空文字列。
 */
+ (NSString *)youTubeClientId;

/**
 YouTubeへの投稿時に使用するClient Secret
 
 YouTubeへ投稿を行う際に利用するアプリケーションのClient Secretを設定できる。
 
 YouTubeへの投稿を行う際はこのメソッドをオーバライドし、アプリケーションが用意したClient Secretを設定する必要がある。
 
 デフォルト値は空文字列。
 */
+ (NSString *)youTubeClientSecret;

/// -----------------------------------------------
/// @name マイクサンプル取得設定
/// -----------------------------------------------

/**
 マイク音声の取得に使用するコールバック関数のポインタ
 
 アプリケーション側でマイクで録音した音声データのサンプルを参照したい場合はメソッドをオーバライドし、アプリケーションが用意したコールバック関数のポインタを設定する必要がある。
 音声データの形式は符号付き16bit、モノラルのリニアPCMデータである。サンプリング周波数はハードウェア設定に依存する。
 
 デフォルト値はNULL。
 
 @warning コールバック関数内の処理に時間が掛かるとオーディオ周りの処理全体に影響が出る恐れがある。
 本機能は動画投稿の録画時のみ有効であり、生放送の配信時には動作しない。(UnityとCocos2d-xでは非対応）

 */

+ (NicoNicoMicrophoneCaptureCallback)microphoneCaptureCallback;

@end
