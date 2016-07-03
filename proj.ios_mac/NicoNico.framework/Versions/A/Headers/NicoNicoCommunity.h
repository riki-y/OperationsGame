//
//  NicoNicoCommunity.h
//  NicoNicoSDK
//
//  Copyright (c) 2014 Dwango. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NicoNicoModel.h"

/**
 * コミュニティ情報
 */
@interface NicoNicoCommunity : NicoNicoModel <NSCopying>
/// コミュニティID
@property (nonatomic, readonly) NSString *communityId;
/// コミュニティ名
@property (nonatomic, readonly) NSString *name;
/// コミュニティのサムネイルURL
@property (nonatomic, readonly) NSURL *thumbnailURL;
@end
