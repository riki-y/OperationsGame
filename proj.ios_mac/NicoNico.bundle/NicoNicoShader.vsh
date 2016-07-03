//
//  NicoNicoShader.vsh
//  NicoNicoSDK
//
//  Copyright (c) 2014年 Dwango. All rights reserved.
//

attribute vec4 position;
attribute vec4 inputTextureCoordinate;

varying vec2 textureCoordinate;

void main()
{
    gl_Position = position;
    textureCoordinate = inputTextureCoordinate.xy;
}
