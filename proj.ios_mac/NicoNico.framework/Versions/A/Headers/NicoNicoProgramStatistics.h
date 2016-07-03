//
//  NicoNicoProgramStatistics.h
//  NicoNicoSDK
//
//  Copyright (c) 2014 Dwango. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NicoNicoModel.h"

/**
 番組統計情報
 
 配信中の番組の各種統計情報を管理する
 */
@interface NicoNicoProgramStatistics : NicoNicoModel <NSCopying>

/// 来場者数
@property (nonatomic, assign, readonly) NSUInteger watchCount;

/// コメント数
@property (nonatomic, assign, readonly) NSUInteger commentCount;

/// タイムシフト予約数
@property (nonatomic, assign, readonly) NSUInteger timeshiftReservationCount;

@end
