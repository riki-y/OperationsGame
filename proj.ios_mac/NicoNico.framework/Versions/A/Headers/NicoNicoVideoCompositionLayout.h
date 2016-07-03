//
//  NicoNicoVideoCompositionLayout.h
//  NicoNicoSDK
//
//  Copyright (c) 2015年 Dwango. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

/**
 背景画像合成レイアウトパターン
 */
typedef NS_ENUM(NSUInteger, NicoNicoVideoCompositionLayoutPattern) {
    /// 縦向き キャプチャ映像中央
    NicoNicoVideoCompositionLayoutPatternPortraitCenter,
    /// 横向き キャプチャ映像左上
    NicoNicoVideoCompositionLayoutPatternLandscapeTopLeft
};

/**
 配信映像の背景画像合成を設定する
 */
@interface NicoNicoVideoCompositionLayout : NSObject

/// レイアウトパターン
@property (nonatomic, assign, readonly) NicoNicoVideoCompositionLayoutPattern layoutPattern;

/// 背景画像テクスチャのハンドル
@property (nonatomic, assign, readonly) GLuint backgroundImageTexture;

/// 背景画像のMetalテクスチャ
@property (nonatomic, strong, readonly) id<MTLTexture> backgroundImageMetalTexture;

/**
 背景画像のアニメーションができるか
 
 YESの場合、毎フレーム録画バッファに背景画像テクスチャをレンダリングする
 
 デフォルトは NO
 */
@property (nonatomic, readwrite) BOOL enableBackgroundImageAnimation;

/// 画像を上下反転させる
@property (nonatomic, readwrite) BOOL flipY;

/// 録画バッファサイズ
@property (nonatomic, assign, readonly) CGSize recordingBufferSize;

/// キャプチャ画像のレンダリング範囲
@property (nonatomic, assign, readonly) CGRect captureImageRect;

/// カメラプレビューのレンダリング範囲
@property (nonatomic, assign, readonly) CGRect cameraPreviewRect;

- (instancetype)initWithLayoutPattern:(NicoNicoVideoCompositionLayoutPattern)layoutPattern
               backgroundImageTexture:(GLuint)backgroundImageTexture;

+ (instancetype)videoCompositionLayoutWithLayoutPattern:(NicoNicoVideoCompositionLayoutPattern)layoutPattern
                                 backgroundImageTexture:(GLuint)backgroundImageTexture;

- (instancetype)initWithLayoutPattern:(NicoNicoVideoCompositionLayoutPattern)layoutPattern
               backgroundImageMetalTexture:(id<MTLTexture>)backgroundImageMetalTexture;

+ (instancetype)videoCompositionLayoutWithLayoutPattern:(NicoNicoVideoCompositionLayoutPattern)layoutPattern
                                 backgroundImageMetalTexture:(id<MTLTexture>)backgroundImageMetalTexture;


@end
