#include <NicoNico/NicoNico.h>
#include "NicoNicoCocosPublisher.h"
#include "NicoNicoCocosEventListener.h"
#include "UIColor+NicoNico.h"

using namespace niconico;

NicoNicoCocosPublisher::NicoNicoCocosPublisher() {
    
}

NicoNicoCocosPublisherQuality NicoNicoCocosPublisher::getQuality() {
    return static_cast<NicoNicoCocosPublisherQuality>([NicoNico sharedInstance].publisher.quality);
}

void NicoNicoCocosPublisher::setQuality(NicoNicoCocosPublisherQuality quality) {
    [NicoNico sharedInstance].publisher.quality = (NicoNicoPublisherQuality)static_cast<int>(quality);
}

NicoNicoCocosPublisherCameraMode NicoNicoCocosPublisher::getCameraMode() {
    return static_cast<NicoNicoCocosPublisherCameraMode>([NicoNico sharedInstance].publisher.cameraMode);
}

void NicoNicoCocosPublisher::setCameraMode(NicoNicoCocosPublisherCameraMode cameraMode) {
    [NicoNico sharedInstance].publisher.cameraMode = (NicoNicoPublisherCameraMode)static_cast<int>(cameraMode);
}

float NicoNicoCocosPublisher::getMicrophoneGain() {
    return [NicoNico sharedInstance].publisher.microphoneGain;
}

void NicoNicoCocosPublisher::setMicrophoneGain(float gain) {
    [NicoNico sharedInstance].publisher.microphoneGain = gain;
}

float NicoNicoCocosPublisher::getLiveAudioVolume() {
    return [NicoNico sharedInstance].publisher.liveAudioVolume;
}

void NicoNicoCocosPublisher::setLiveAudioVolume(float volume) {
    [NicoNico sharedInstance].publisher.liveAudioVolume = volume;
}

NicoNicoCocosPublishProgram NicoNicoCocosPublisher::getProgram() {
    return NicoNicoCocosPublishProgram();
}

int64_t NicoNicoCocosPublisher::getElapsedTime() {
    return [NicoNico sharedInstance].publisher.elapsedTime*1000;
}

int64_t NicoNicoCocosPublisher::getRemainingTime() {
    return [NicoNico sharedInstance].publisher.remainingTime*1000;
}

std::vector<NicoNicoCocosComment> NicoNicoCocosPublisher::getLatestComments() {
    NSArray *latestComments = [NicoNico sharedInstance].publisher.latestComments;
    
    std::vector<NicoNicoCocosComment> tmpLatestComments;
    for (NicoNicoComment *comment in latestComments) {
        NicoNicoCocosCommentPosition position = static_cast<NicoNicoCocosCommentPosition>(comment.position);
        NicoNicoCocosCommentSize size = static_cast<NicoNicoCocosCommentSize>(comment.size);
        
        NicoNicoCocosComment tmpComment((int)comment.number,
                                      [comment.text UTF8String],
                                      position,
                                      size,
                                      comment.color.intValue,
                                      (int)comment.vpos,
                                      comment.mine);
        tmpLatestComments.push_back(tmpComment);
    }
    return tmpLatestComments;
}

bool NicoNicoCocosPublisher::isCommentVisible() {
    return [NicoNico sharedInstance].publisher.commentVisible;
}

void NicoNicoCocosPublisher::setCommentVisibility(bool visible) {
    [NicoNico sharedInstance].publisher.commentVisible = visible;
}

NicoNicoCocosRect NicoNicoCocosPublisher::getCommentStageRect() {
    CGRect commentStageRect = [NicoNico sharedInstance].publisher.commentStageRect;
    return NicoNicoCocosRect((int)commentStageRect.origin.x, (int)commentStageRect.origin.y, (int)commentStageRect.size.width, (int)commentStageRect.size.height);
}

void NicoNicoCocosPublisher::setCommentStageRect(int x, int y, int renderSpaceWidth, int renderSpaceHeight) {
    [NicoNico sharedInstance].publisher.commentStageRect = CGRectMake(x, y, renderSpaceWidth, renderSpaceHeight);
}

bool NicoNicoCocosPublisher::isPublishing() {
    return [NicoNico sharedInstance].publisher.isPublishing;
}

bool NicoNicoCocosPublisher::isPaused() {
    return [NicoNico sharedInstance].publisher.isPaused;
}

bool NicoNicoCocosPublisher::startPublishing() {
    return [[NicoNico sharedInstance].publisher startPublishing];
}

bool NicoNicoCocosPublisher::restartPublishing() {
    return [[NicoNico sharedInstance].publisher restartPublishing];
}

bool NicoNicoCocosPublisher::pausePublishing() {
    return [[NicoNico sharedInstance].publisher pausePublishing];
}

bool NicoNicoCocosPublisher::stopPublishing() {
    return [[NicoNico sharedInstance].publisher stopPublishing];
}

NicoNicoCocosVideoCompositionLayout NicoNicoCocosPublisher::getVideoCompositionLayout() {
    NicoNicoVideoCompositionLayout *layout = [NicoNico sharedInstance].publisher.videoCompositionLayout;
    
    NicoNicoCocosVideoCompositionLayoutPattern pattern = static_cast<NicoNicoCocosVideoCompositionLayoutPattern>(layout.layoutPattern);
    return NicoNicoCocosVideoCompositionLayout(pattern,
                                               layout.backgroundImageTexture,
                                               layout.enableBackgroundImageAnimation,
                                               layout.flipY,
                                               NicoNicoCocosSize(layout.recordingBufferSize.width, layout.recordingBufferSize.width),
                                               NicoNicoCocosRect(layout.captureImageRect.origin.x, layout.captureImageRect.origin.y, layout.captureImageRect.size.width, layout.captureImageRect.size.height),
                                               NicoNicoCocosRect(layout.cameraPreviewRect.origin.x, layout.cameraPreviewRect.origin.y, layout.cameraPreviewRect.size.width, layout.cameraPreviewRect.size.height));
}

void NicoNicoCocosPublisher::setVideoCompositionLayout(NicoNicoCocosVideoCompositionLayout videoCompositionLayout) {
    
    NicoNicoVideoCompositionLayoutPattern pattern = (NicoNicoVideoCompositionLayoutPattern)static_cast<int>(videoCompositionLayout.getLayoutPattern());
    GLuint imageTexture = videoCompositionLayout.getBackgroundImageTexture();
    
    NicoNicoVideoCompositionLayout *layout = [NicoNicoVideoCompositionLayout videoCompositionLayoutWithLayoutPattern:pattern
                                                                                              backgroundImageTexture:imageTexture];
    layout.enableBackgroundImageAnimation = videoCompositionLayout.checkEnableBackgroundImageAnimation();
    layout.flipY = videoCompositionLayout.checkFlipY();
    [NicoNico sharedInstance].publisher.videoCompositionLayout = layout;
    
}
