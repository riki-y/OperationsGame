#include "NicoNicoCocosUploadVideo.h"

using namespace niconico;

NicoNicoCocosUploadVideo::NicoNicoCocosUploadVideo(std::string videoId, std::string title, std::string videoDescription, NicoNicoCocosUser user, int64_t duration, std::vector<std::string> tags, std::vector<std::string> uneditableTags, std::vector<std::string> editableTags, NicoNicoCocosCategory category, std::string watchURL)
: videoId(videoId),
title(title),
videoDescription(videoDescription),
user(user),
duration(duration),
tags(tags),
uneditableTags(uneditableTags),
editableTags(editableTags),
category(category),
watchURL(watchURL) {
    
}

std::string NicoNicoCocosUploadVideo::getVideoId() {
    return videoId;
}

std::string NicoNicoCocosUploadVideo::getTitle() {
    return title;
}

std::string NicoNicoCocosUploadVideo::getVideoDescription() {
    return videoDescription;
}

NicoNicoCocosUser NicoNicoCocosUploadVideo::getUser() {
    return user;
}

int64_t NicoNicoCocosUploadVideo::getDuration() {
    return duration;
}

std::vector<std::string> NicoNicoCocosUploadVideo::getTags() {
    return tags;
}

std::vector<std::string> NicoNicoCocosUploadVideo::getUneditableTags() {
    return uneditableTags;
}

std::vector<std::string> NicoNicoCocosUploadVideo::getEditableTags() {
    return editableTags;
}

NicoNicoCocosCategory NicoNicoCocosUploadVideo::getCategory() {
    return category;
}

std::string NicoNicoCocosUploadVideo::getWatchURL() {
    return watchURL;
}
