#include <NicoNico/NicoNico.h>
#include "NicoNicoCocosUser.h"

using namespace niconico;

NicoNicoCocosUser::NicoNicoCocosUser(std::string userId, std::string nickname, std::string thumbnailSmallURL, std::string thumbnailURL, bool premium)
: userId(userId),
nickname(nickname),
thumbnailSmallURL(thumbnailSmallURL),
thumbnailURL(thumbnailURL),
premium(premium) {
    
}

NicoNicoCocosUser::NicoNicoCocosUser() {
    NicoNicoUser *user = [NicoNico sharedInstance].currentUser;
    userId = user ? [user.userId UTF8String] : "";
    nickname = user ? [user.nickName UTF8String] : "";
    thumbnailSmallURL = user ? [[user.thumbnailSmallURL absoluteString] UTF8String] : "";
    thumbnailURL = user ? [[user.thumbnailURL absoluteString] UTF8String] : "";
    premium = user ? user.premium : false;
}

std::string NicoNicoCocosUser::getUserId() {
    return userId;
}

std::string NicoNicoCocosUser::getNickName() {
    return nickname;
}

std::string NicoNicoCocosUser::getThumbnailSmallURL() {
    return thumbnailSmallURL;
}

std::string NicoNicoCocosUser::getThumbnailURL() {
    return thumbnailURL;
}

bool NicoNicoCocosUser::isPremium() {
    return premium;
}
