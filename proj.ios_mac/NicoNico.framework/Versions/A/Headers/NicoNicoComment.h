//
//  NicoNicoComment.h
//  NicoNicoSDK
//
//  Copyright (c) 2014 Dwango. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 コメントの描画サイズ
 
 コメントを描画する際のフォントサイズ
 */
typedef NS_ENUM(NSUInteger, NicoNicoCommentSize) {
    /// 中サイズ
    NicoNicoCommentSizeMedium,
    /// 大サイズ
    NicoNicoCommentSizeBig,
    /// 小サイズ
    NicoNicoCommentSizeSmall
};

/*
 コメントの描画位置
 
 コメントを描画する際の描画処理位置
 */
typedef NS_ENUM(NSUInteger, NicoNicoCommentPosition) {
    /// 通常コメント。画面端から画面端へコメントが流れて表示される
    NicoNicoCommentPositionCenter,
    /// 上コメント。画面上部に固定して表示される
    NicoNicoCommentPositionTop,
    /// 下コメント。画面下部に固定して表示される
    NicoNicoCommentPositionBottom
};

/**
 ニコニコ動画、ニコニコ生放送に投稿されるコメント
 */
@interface NicoNicoComment : NSObject
/// コメント番号
@property (nonatomic, readonly) NSInteger number;
/// コメントカラー
@property (nonatomic, copy, readonly) UIColor *color;
/// コメント本文
@property (nonatomic, copy, readonly) NSString *text;
/// コメント描画位置
@property (nonatomic, readonly) NicoNicoCommentPosition position;
/// コメントの描画サイズ
@property (nonatomic, readonly) NicoNicoCommentSize size;
/// コメントの映像に対する投稿位置。10ms単位
@property (nonatomic, readonly) NSInteger vpos;
/// 自分自身の投稿か
@property (nonatomic, readonly, getter = isMine) BOOL mine;

@end
