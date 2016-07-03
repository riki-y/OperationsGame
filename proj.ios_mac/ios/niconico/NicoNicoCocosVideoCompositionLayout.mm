#include <NicoNico/NicoNico.h>
#include "NicoNicoCocosVideoCompositionLayout.h"

using namespace niconico;

NicoNicoCocosVideoCompositionLayout::NicoNicoCocosVideoCompositionLayout(NicoNicoCocosVideoCompositionLayoutPattern layoutPattern, int32_t backgroundImageTexture)
: layoutPattern(layoutPattern),
backgroundImageTexture(backgroundImageTexture),
enableBackgroundImageAnimation(false),
flipY(true),
recordingBufferSize(NicoNicoCocosSize(0, 0)),
captureImageRect(NicoNicoCocosRect(0, 0, 0, 0)),
cameraPreviewRect(NicoNicoCocosRect(0, 0, 0, 0)){
    
}

NicoNicoCocosVideoCompositionLayout::NicoNicoCocosVideoCompositionLayout(NicoNicoCocosVideoCompositionLayoutPattern layoutPattern, int32_t backgroundImageTexture, bool enableBackgroundImageAnimation, bool flipY, NicoNicoCocosSize recordingBufferSize, NicoNicoCocosRect captureImageRect, NicoNicoCocosRect cameraPreviewRect)
: layoutPattern(layoutPattern),
backgroundImageTexture(backgroundImageTexture),
enableBackgroundImageAnimation(enableBackgroundImageAnimation),
flipY(flipY),
recordingBufferSize(recordingBufferSize),
captureImageRect(captureImageRect),
cameraPreviewRect(cameraPreviewRect) {
    
}

NicoNicoCocosVideoCompositionLayoutPattern NicoNicoCocosVideoCompositionLayout::getLayoutPattern() {
    return layoutPattern;
}

int32_t NicoNicoCocosVideoCompositionLayout::getBackgroundImageTexture() {
    return backgroundImageTexture;
}

bool NicoNicoCocosVideoCompositionLayout::checkEnableBackgroundImageAnimation() {
    return enableBackgroundImageAnimation;
}

void NicoNicoCocosVideoCompositionLayout::setEnableBackgroundImageAnimation(bool enableAnimation) {
    enableBackgroundImageAnimation = enableAnimation;
}

bool NicoNicoCocosVideoCompositionLayout::checkFlipY() {
    return flipY;
}

void NicoNicoCocosVideoCompositionLayout::setFlipY(bool flip) {
    flipY = flip;
}

NicoNicoCocosSize NicoNicoCocosVideoCompositionLayout::getRecordingBufferSize() {
    NicoNicoVideoCompositionLayoutPattern pattern = (NicoNicoVideoCompositionLayoutPattern)static_cast<int>(layoutPattern);
    GLuint imageTexture = getBackgroundImageTexture();
    NicoNicoVideoCompositionLayout *layout = [NicoNicoVideoCompositionLayout videoCompositionLayoutWithLayoutPattern:pattern
                                                                                              backgroundImageTexture:imageTexture];
    return NicoNicoCocosSize(layout.recordingBufferSize.width, layout.recordingBufferSize.height);
    
}

NicoNicoCocosRect NicoNicoCocosVideoCompositionLayout::getCaptureImageRect() {
    NicoNicoVideoCompositionLayoutPattern pattern = (NicoNicoVideoCompositionLayoutPattern)static_cast<int>(layoutPattern);
    GLuint imageTexture = getBackgroundImageTexture();
    NicoNicoVideoCompositionLayout *layout = [NicoNicoVideoCompositionLayout videoCompositionLayoutWithLayoutPattern:pattern
                                                                                              backgroundImageTexture:imageTexture];
    return NicoNicoCocosRect(layout.captureImageRect.origin.x,
                             layout.captureImageRect.origin.y,
                             layout.captureImageRect.size.width,
                             layout.captureImageRect.size.height);
}


NicoNicoCocosRect NicoNicoCocosVideoCompositionLayout::getCameraPreviewRect() {
    NicoNicoVideoCompositionLayoutPattern pattern = (NicoNicoVideoCompositionLayoutPattern)static_cast<int>(layoutPattern);
    GLuint imageTexture = getBackgroundImageTexture();
    NicoNicoVideoCompositionLayout *layout = [NicoNicoVideoCompositionLayout videoCompositionLayoutWithLayoutPattern:pattern
                                                                                              backgroundImageTexture:imageTexture];
    return NicoNicoCocosRect(layout.cameraPreviewRect.origin.x,
                             layout.cameraPreviewRect.origin.y,
                             layout.cameraPreviewRect.size.width,
                             layout.cameraPreviewRect.size.height);
}
