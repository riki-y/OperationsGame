#include <NicoNico/NicoNico.h>
#include "NicoNicoCocosCommunity.h"

using namespace niconico;

NicoNicoCocosCommunity::NicoNicoCocosCommunity() {
    
}

std::string NicoNicoCocosCommunity::getCommunityId() {
    return [[NicoNico sharedInstance].publisher.program.community.communityId UTF8String] ? : "";
}

std::string NicoNicoCocosCommunity::getName() {
    return [[NicoNico sharedInstance].publisher.program.community.name UTF8String] ? : "";
}

std::string NicoNicoCocosCommunity::getThumbnailURL() {
    return [[[NicoNico sharedInstance].publisher.program.community.thumbnailURL absoluteString] UTF8String] ? : "";
}
