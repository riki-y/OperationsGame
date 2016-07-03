//
//  NicoNicoShader.fsh
//  NicoNicoSDK
//
//  Copyright (c) 2014年 Dwango. All rights reserved.
//

varying highp vec2 textureCoordinate;

uniform sampler2D inputImageTexture;

void main()
{
    gl_FragColor = texture2D(inputImageTexture, textureCoordinate);
}
