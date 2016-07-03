#include <NicoNico/NicoNico.h>
#include "NicoNicoCocosCapture.h"

using namespace niconico;

NicoNicoCocosCapture::NicoNicoCocosCapture() {
    
}

int NicoNicoCocosCapture::getFramesPerSecond() {
    return [NicoNico sharedInstance].capture.framesPerSecond;
}

void NicoNicoCocosCapture::setFramesPerSecond(int fps) {
    [NicoNico sharedInstance].capture.framesPerSecond = fps;
}

bool NicoNicoCocosCapture::isRecording() {
    return [NicoNico sharedInstance].capture.isRecording;
}

bool NicoNicoCocosCapture::startRecording() {
    return [[NicoNico sharedInstance].capture startRecording];
}

bool NicoNicoCocosCapture::stopRecording() {
    return [[NicoNico sharedInstance].capture stopRecordingWithCompletionHandler:nil];
}

bool NicoNicoCocosCapture::pauseRecording() {
    return [[NicoNico sharedInstance].capture pauseRecording];
}

bool NicoNicoCocosCapture::resumeRecording() {
    return [[NicoNico sharedInstance].capture resumeRecording];
}
