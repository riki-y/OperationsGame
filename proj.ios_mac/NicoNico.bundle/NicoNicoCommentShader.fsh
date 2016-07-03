//
//  NicoNicoShader.fsh
//  NicoNicoSDK
//
//  Copyright (c) 2014年 Dwango. All rights reserved.
//

precision mediump float;

varying highp vec2 textureCoordinate;
varying float vertexAlpha;
uniform sampler2D inputImageTexture;

void main()
{
    vec4 baseColor;
    
    baseColor = texture2D(inputImageTexture, textureCoordinate);
    gl_FragColor = vec4(baseColor.rgb, baseColor.a * vertexAlpha);
}
