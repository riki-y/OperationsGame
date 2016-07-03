//
//  NicoNicoPublishProgram.h
//  NicoNicoSDK
//
//  Copyright (c) 2014年 Dwango. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NicoNicoModel.h"

@class NicoNicoProgramStatistics, NicoNicoUser, NicoNicoCommunity;

/**
 生放送番組の公開範囲
 */
typedef NS_OPTIONS(NSUInteger, NicoNicoProgramPermittedAudience) {
    /// なし
    NicoNicoProgramPermittedAudienceNone                = 0,
    /// コミュニティメンバーに限定して公開
    NicoNicoProgramPermittedAudienceCommunityMemberOnly = 1 << 0,
    /// チャンネルメンバーに限定して公開
    NicoNicoProgramPermittedAudienceChannelMemberOnly   = 1 << 1,
    /// 全てのニコニコユーザに公開
    NicoNicoProgramPermittedAudienceNicoNicoUsers       = 1 << 2,
    /// 非ログインユーザを含めた全てのユーザに公開
    NicoNicoProgramPermittedAudienceAll                 = 1 << 3
};

/**
 生放送番組情報
 */
@interface NicoNicoPublishProgram : NicoNicoModel <NSCopying>

/// -----------------------------------------------
/// @name 基本情報
/// -----------------------------------------------

/**
 生放送番組ID
 
 生放送番組を識別するためのID。接頭辞lvから始まる番組固有の文字列
 */
@property (nonatomic, readonly) NSString *programId;

/// 番組タイトル
@property (nonatomic, readonly) NSString *title;

/// 番組説明文
@property (nonatomic, readonly) NSString *programDescription;

/// サムネイルURL
@property (nonatomic, readonly) NSURL *thumbnailURL;

/// 統計情報
@property (nonatomic, readonly) NicoNicoProgramStatistics *statistics;

/// コミュニティ情報
@property (nonatomic, readonly) NicoNicoCommunity *community;

/// -----------------------------------------------
/// @name 時間情報
/// -----------------------------------------------

/**
 開演時間
 
 番組の開演時間。この時間から番組のコンテンツが始まる。
 SDKによって作成された番組の場合、作成された時間と同時間になる。
 */
@property (nonatomic, readonly) NSDate *beginDate;

/**
 終了時刻
 
 番組が終了時間。この時間で番組が終了する。
 SDKによって作成された番組の場合、番組を作成した時刻から30分後になる。
 */
@property (nonatomic, readonly) NSDate *endDate;

/**
 残り時間
 
 番組終了までの残り時間。この時間が0となると番組が終了する。
 */
@property (nonatomic, readonly) NSTimeInterval remainingTime;

/// -----------------------------------------------
/// @name 公開情報
/// -----------------------------------------------

/// 番組の公開範囲
@property (nonatomic, readonly) NicoNicoProgramPermittedAudience permittedAudience;

/**
 タイムシフトを公開するか
 
 番組がタイムシフトを公開するかを返す。
 */
@property (nonatomic, readonly, getter=isTimeshiftEnabled) BOOL timeshiftEnabled;

/// -----------------------------------------------
/// @name 番組属性情報
/// -----------------------------------------------

/// タグ一覧
@property (nonatomic, readonly) NSArray  *tags;

/**
 顔出しか
 
 この番組が顔出しを行っているかを返す
 */
@property (nonatomic, readonly, getter=isKaodashi) BOOL kaodashi;

/// 配信ユーザー
@property (nonatomic, readonly) NicoNicoUser *user;

@end

