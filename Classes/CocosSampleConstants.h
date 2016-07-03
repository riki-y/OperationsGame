/*
 * CocosSampleConstants.h
 *
 * Copyright (c) 2016年 DWANGO Co., Ltd. All rights reserved.
 */

#ifndef CocosSampleConstants_h
#define CocosSampleConstants_h

static const int DEFAULT_AVAILABLE_SERVICE_TYPE = (1 << 0) | (1 << 1);

static const bool DEFAULT_SUPPORTS_OPENAL = true;
static const bool DEFAULT_SUPPORTS_AVAUDIOPLAYER = true;
static const bool DEFAULT_SUPPORTS_AUIDO_UNIT = true;
static const bool DEFAULT_SHOULD_CHANGE_AUDIO_SESSION_SETTINGS = true;
static const bool DEFAULT_SUPPORTS_AUXILIARY_AUDIO_INPUT = false;
static const bool DEFAULT_SHOULD_INTERRUPT_OTHER_AUDIO = true;

static const uint64_t DEFAULT_STORAGE_FREE_SPACE_LIMIT = (256LLU * 1024LLU * 1024LLU);
static const bool DEFAULT_ENABLE_BACKGROUND_UPLOAD = true;
static const bool DEFAULT_SHOULD_AUTO_RESUME_UPLOADING = true;

static const int DEFAULT_MAX_CAPACITY_FOR_LIVE_COMMENTS = 200;
static const bool DEFAULT_ENABLE_RENDERING_COMMENTS_FOR_PUBLISH = true;
static const bool DEFAULT_SHOULD_GENERATE_DUMMY_COMMENTS_FOR_PUBLISHING = false;
static const bool DEFAULT_PERMITTED_RECORDING_CAMERA_FOR_PUBLISHING = true;

static const bool DEFAULT_ENABLE_SHARE_TWITTER = true;
static const std::string DEFAULT_TWITTER_CLIENT_ID = "";
static const std::string DEFAULT_TWITTER_CLIENT_SECRET = "";

static const bool DEFAULT_ENABLE_SHARE_FACEBOOK = false;
static const std::string DEFAULT_FACEBOOK_CLIENT_ID = "";
static const std::string DEFAULT_FACEBOOK_CLIENT_SECRET = "";

static const bool DEFAULT_ENABLE_SHARE_YOUTUBE = false;
static const std::string DEFAULT_YOUTUBE_CLIENT_ID = "";
static const std::string DEFAULT_YOUTUBE_CLIENT_SECRET = "";

static const bool DEFAULT_SHOULD_SHOW_ACCOUNT_SIGNUP_BUTTION = false;
static const std::string DEFAULT_SUPPORT_VALIDATION_POLICY_IOS = "permissive";

static const std::string DEFAULT_SUPPORT_VALIDATION_POLICY_ANDROID = "strict";
static const bool DEFAULT_AUDIO_8BIT_ONLY = false;


#endif /* CocosSampleConstants_h */
