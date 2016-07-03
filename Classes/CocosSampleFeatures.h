//
//  CocosSampleFeatures.h
//  OperationsGame
//
//  Created by 吉田　理貴 on 2016/07/04.
//
//

#ifndef CocosSampleFeatures_h
#define CocosSampleFeatures_h

#include "niconico/NicoNicoCocos.h"
#include "CocosSampleConstants.h"

namespace niconico {
    
    class CocosSampleFeatures: public NicoNicoCocosFeatures {
    public:
        virtual int availableServiceType() {
            return DEFAULT_AVAILABLE_SERVICE_TYPE;
        }
        
        virtual bool shouldShowAccountSignupButton() {
            return DEFAULT_SHOULD_SHOW_ACCOUNT_SIGNUP_BUTTION;
        }
        
        virtual std::string supportValidationPolicy() {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            return DEFAULT_SUPPORT_VALIDATION_POLICY_IOS;
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
            return DEFAULT_SUPPORT_VALIDATION_POLICY_ANDROID;
#endif
        }
        
        virtual uint64_t storageFreeSpaceLimit() {
            return DEFAULT_STORAGE_FREE_SPACE_LIMIT;
        }
        
        virtual bool supportsOpenAL() {
            return DEFAULT_SUPPORTS_OPENAL;
        }
        
        virtual bool supportsAVAudioPlayer() {
            return DEFAULT_SUPPORTS_AVAUDIOPLAYER;
        }
        
        virtual bool supportsAudioUnit() {
            return DEFAULT_SUPPORTS_AUIDO_UNIT;
        }
        
        virtual bool supportsAuxiliaryAudioInput() {
            return DEFAULT_SUPPORTS_AUXILIARY_AUDIO_INPUT;
        }
        
        virtual bool shouldChangeAudioSessionSettings() {
            return DEFAULT_SHOULD_CHANGE_AUDIO_SESSION_SETTINGS;
        }
        
        virtual bool shouldInterruptOtherAudio() {
            return DEFAULT_SHOULD_INTERRUPT_OTHER_AUDIO;
        }
        
        virtual bool enableBackgroundUpload() {
            return DEFAULT_ENABLE_BACKGROUND_UPLOAD;
        }
        
        virtual bool shouldAutoResumeUploading() {
            return DEFAULT_SHOULD_AUTO_RESUME_UPLOADING;
        }
        
        virtual int maxCapacityForLiveComments() {
            return DEFAULT_MAX_CAPACITY_FOR_LIVE_COMMENTS;
        }
        
        virtual bool enableRenderingCommentsForPublish() {
            return DEFAULT_ENABLE_RENDERING_COMMENTS_FOR_PUBLISH;
        }
        
        virtual bool shouldGenerateDummyCommentsForPublishing() {
            return DEFAULT_SHOULD_GENERATE_DUMMY_COMMENTS_FOR_PUBLISHING;
        }
        
        virtual bool permittedRecordingCameraForPublishing() {
            return DEFAULT_PERMITTED_RECORDING_CAMERA_FOR_PUBLISHING;
        }
        
        virtual bool enableShareTwitter() {
            return DEFAULT_ENABLE_SHARE_TWITTER;
        }
        
        virtual std::string twitterClientId() {
            return DEFAULT_TWITTER_CLIENT_ID;
        }
        
        virtual std::string twitterClientSecret() {
            return DEFAULT_TWITTER_CLIENT_SECRET;
        }
        
        virtual bool enableShareFacebook() {
            return DEFAULT_ENABLE_SHARE_FACEBOOK;
        }
        
        virtual std::string facebookClientId() {
            return DEFAULT_FACEBOOK_CLIENT_ID;
        }
        
        virtual std::string facebookClientSecret() {
            return DEFAULT_FACEBOOK_CLIENT_SECRET;
        }
        
        virtual bool enableShareYouTube() {
            return DEFAULT_ENABLE_SHARE_YOUTUBE;
        }
        
        virtual std::string youTubeClientId() {
            return DEFAULT_YOUTUBE_CLIENT_ID;
        }
        
        virtual std::string youTubeClientSecret() {
            return DEFAULT_YOUTUBE_CLIENT_SECRET;
        }
        
        virtual bool audio8bitOnly() {
            return DEFAULT_AUDIO_8BIT_ONLY;
        }
    };
    
}  // namespace niconico

#endif /* CocosSampleFeatures_h */
