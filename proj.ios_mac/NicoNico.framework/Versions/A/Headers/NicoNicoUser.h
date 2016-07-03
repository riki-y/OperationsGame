//
//  NicoNicoUser.h
//  NicoNicoSDK
//
//  Copyright (c) 2014 Dwango. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NicoNicoModel.h"

/**
 ユーザ情報
 
 niconicoのユーザ情報
 */
@interface NicoNicoUser : NicoNicoModel <NSCoding, NSCopying>

/// -----------------------------------------------
/// @name 基本情報
/// -----------------------------------------------

/// ユーザのniconico ID
@property (nonatomic, readonly) NSString *userId;

/// ユーザに設定されたニックネーム
@property (nonatomic, readonly) NSString *nickName;

/// ユーザに設定されたプロフィール小画像URL
@property (nonatomic, readonly) NSURL *thumbnailSmallURL;

/// ユーザに設定されたプロフィール画像URL
@property (nonatomic, readonly) NSURL *thumbnailURL;

/// -----------------------------------------------
/// @name プレミアム会員情報
/// -----------------------------------------------

/// このユーザがプレミアム会員であるか
@property (nonatomic, readonly, getter = isPremium) BOOL premium;

@end
