//
//  NicoNicoUploadVideo.h
//  NicoNicoSDK
//
//  Copyright (c) 2014 Dwango. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NicoNicoConstants.h"

@class NicoNicoUser;

/**
 動画情報
 
 ニコニコ動画に投稿された動画情報
 */
@interface NicoNicoUploadVideo : NSObject <NSCoding>

/// 動画ID
@property (nonatomic, readonly) NSString *videoId;

/// 動画タイトル
@property (nonatomic, readonly) NSString *title;

/// 動画説明文
@property (nonatomic, readonly) NSString *videoDescription;

/// 動画投稿ユーザ
@property (nonatomic, readonly) NicoNicoUser *user;

/// 動画の長さ(秒)
@property (nonatomic, readonly) NSTimeInterval duration;

/// 動画に付与された全てのタグ
@property (nonatomic, readonly) NSArray *tags;

/// 動画に付与された編集不可タグ
@property (nonatomic, readonly) NSArray *uneditableTags;

/// 動画に付与された編集可能タグ
@property (nonatomic, readonly) NSArray *editableTags;

/// カテゴリ
@property (nonatomic, readonly) NicoNicoCategory category;

/// 動画視聴のURL
@property (nonatomic, readonly) NSURL *watchURL;

@end
