//
//  NicoNicoShader.vsh
//  NicoNicoSDK
//
//  Copyright (c) 2014年 Dwango. All rights reserved.
//

attribute vec4 position;
attribute vec4 inputTextureCoordinate;
attribute float inputVertexAlpha;
varying vec2 textureCoordinate;
varying float vertexAlpha;

void main()
{
    gl_Position = position;
    textureCoordinate = inputTextureCoordinate.xy;
    vertexAlpha = inputVertexAlpha;
}
