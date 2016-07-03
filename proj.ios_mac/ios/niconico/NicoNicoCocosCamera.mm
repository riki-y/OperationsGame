#include <NicoNico/NicoNico.h>
#include "NicoNicoCocosCamera.h"
#include "UIColor+NicoNico.h"

using namespace niconico;

NicoNicoCocosCamera::NicoNicoCocosCamera() {
    
}

bool NicoNicoCocosCamera::isRunning() {
    return [NicoNico sharedInstance].camera.isRunning;
}

void NicoNicoCocosCamera::startSession() {
    [[NicoNico sharedInstance].camera startSession];
}

void NicoNicoCocosCamera::stopSession() {
    [[NicoNico sharedInstance].camera stopSession];
}

bool NicoNicoCocosCamera::isRecording() {
    return [NicoNico sharedInstance].camera.isRecording;
}

bool NicoNicoCocosCamera::isVideoRecordingSupported() {
    return [NicoNico sharedInstance].camera.isVideoRecordingSupported;
}

int NicoNicoCocosCamera::getFramesPerSecond() {
    return [NicoNico sharedInstance].camera.framesPerSecond;
}

void NicoNicoCocosCamera::setFramesPerSecond(int fps) {
    [NicoNico sharedInstance].camera.framesPerSecond = fps;
}

bool NicoNicoCocosCamera::isAudioRecordingSupported() {
    return [NicoNico sharedInstance].camera.isAudioRecordingSupported;
}

float NicoNicoCocosCamera::getMicrophoneGain() {
    return [NicoNico sharedInstance].camera.microphoneGain;
}

void NicoNicoCocosCamera::setMicrophoneGain(float gain) {
    [NicoNico sharedInstance].camera.microphoneGain = gain;
}

bool NicoNicoCocosCamera::isMicrophoneMute() {
    return [NicoNico sharedInstance].camera.microphoneMute;
}

void NicoNicoCocosCamera::setMicrophoneMute(bool mute) {
    [NicoNico sharedInstance].camera.microphoneMute = mute;
}

bool NicoNicoCocosCamera::isAudioOnly() {
    return [NicoNico sharedInstance].camera.audioOnly;
}

void NicoNicoCocosCamera::setAudioOnly(bool audioOnly) {
    [NicoNico sharedInstance].camera.audioOnly = audioOnly;
}

bool NicoNicoCocosCamera::isPreviewVisible() {
    return [NicoNico sharedInstance].camera.previewVisible;
}

void NicoNicoCocosCamera::setPreviewVisible(bool visible) {
    [NicoNico sharedInstance].camera.previewVisible = visible;
}

void NicoNicoCocosCamera::setPreviewGravity(NicoNicoCocosPreviewGravity gravity) {
    [NicoNico sharedInstance].camera.previewGravity = (NicoNicoCameraOverlapPreviewGravity)static_cast<int>(gravity);
}

NicoNicoCocosPreviewGravity NicoNicoCocosCamera::getPreviewGravity() {
    return static_cast<niconico::NicoNicoCocosPreviewGravity>([NicoNico sharedInstance].camera.previewGravity);
}

float NicoNicoCocosCamera::getPreviewMargin() {
    return [NicoNico sharedInstance].camera.previewMargin;
}

void NicoNicoCocosCamera::setPreviewMargin(float margin) {
    [NicoNico sharedInstance].camera.previewMargin = margin;
}

float NicoNicoCocosCamera::getPreviewPositionX() {
    return [NicoNico sharedInstance].camera.previewPositionX;
}

void NicoNicoCocosCamera::setPreviewPositionX(float x) {
    [NicoNico sharedInstance].camera.previewPositionX = x;
}

float NicoNicoCocosCamera::getPreviewPositionY() {
    return [NicoNico sharedInstance].camera.previewPositionY;
}

void NicoNicoCocosCamera::setPreviewPositionY(float y) {
    [NicoNico sharedInstance].camera.previewPositionY = y;
}

float NicoNicoCocosCamera::getPreviewWidth() {
    return [NicoNico sharedInstance].camera.previewWidth;
}

void NicoNicoCocosCamera::setPreviewWidth(float width) {
    [NicoNico sharedInstance].camera.previewWidth = width;
}

float NicoNicoCocosCamera::getPreviewHeight() {
    return [NicoNico sharedInstance].camera.previewHeight;
}

void NicoNicoCocosCamera::setPreviewHeight(float height) {
    [NicoNico sharedInstance].camera.previewHeight = height;
}

float NicoNicoCocosCamera::getPreviewBorderWidth() {
    return [NicoNico sharedInstance].camera.previewBorderWidth;
}

void NicoNicoCocosCamera::setPreviewBorderWidth(float width) {
    [NicoNico sharedInstance].camera.previewBorderWidth = width;
}

int NicoNicoCocosCamera::getPreviewBorderColor() {
    return [NicoNico sharedInstance].camera.previewBorderColor.intValue;
}

void NicoNicoCocosCamera::setPreviewBorderColor(int alpha, int red, int green, int blue) {
    [NicoNico sharedInstance].camera.previewBorderColor = [UIColor colorWithRed:(float)red/255.f
                                                                          green:(float)green/255.f
                                                                           blue:(float)blue/255.f
                                                                          alpha:(float)alpha/255.f];
}

void NicoNicoCocosCamera::setPreviewTextureID(int32_t textureID) {
    [[NicoNico sharedInstance].camera setPreviewTextureID:textureID];
}

NicoNicoCocosSize NicoNicoCocosCamera::getPreviewTextureSize() {
    NicoNicoCamera *camera = [NicoNico sharedInstance].camera;
    return NicoNicoCocosSize(camera.previewTextureSize.width, camera.previewTextureSize.height);
}

bool NicoNicoCocosCamera::checkCameraRecordingPermission() {
    return [[NicoNico sharedInstance].camera checkCameraRecordingPermission];
}

bool NicoNicoCocosCamera::checkMicrophoneRecordingPermission() {
    return [[NicoNico sharedInstance].camera checkMicrophoneRecordingPermission];
}
