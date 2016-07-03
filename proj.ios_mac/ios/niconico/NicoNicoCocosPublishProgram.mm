#include <NicoNico/NicoNico.h>
#include "NicoNicoCocosPublishProgram.h"

using namespace niconico;

NicoNicoCocosPublishProgram::NicoNicoCocosPublishProgram() {
    
}

std::string NicoNicoCocosPublishProgram::getProgramId() {
    return [[NicoNico sharedInstance].publisher.program.programId UTF8String] ? : "";
}

std::string NicoNicoCocosPublishProgram::getTitle() {
    return [[NicoNico sharedInstance].publisher.program.title UTF8String] ? : "";
}

std::string NicoNicoCocosPublishProgram::getProgramDescription() {
    return [[NicoNico sharedInstance].publisher.program.programDescription UTF8String] ? : "";
}

std::string NicoNicoCocosPublishProgram::getThumbnailURL() {
    return [[[NicoNico sharedInstance].publisher.program.thumbnailURL absoluteString] UTF8String] ? : "";
}

NicoNicoCocosProgramStatistics NicoNicoCocosPublishProgram::getStatistics() {
    return NicoNicoCocosProgramStatistics();
}

NicoNicoCocosCommunity NicoNicoCocosPublishProgram::getCommunity() {
    return NicoNicoCocosCommunity();
}

int64_t NicoNicoCocosPublishProgram::getBeginDate() {
    return [[NicoNico sharedInstance].publisher.program.beginDate timeIntervalSince1970]*1000;
}

int64_t NicoNicoCocosPublishProgram::getEndDate() {
    return [[NicoNico sharedInstance].publisher.program.endDate timeIntervalSince1970]*1000;
}

int64_t NicoNicoCocosPublishProgram::getRemainingTime() {
    return [NicoNico sharedInstance].publisher.program.remainingTime*1000;
}

NicoNicoCocosPermittedAudience NicoNicoCocosPublishProgram::getPermittedAudience() {
    NicoNicoProgramPermittedAudience audience = [NicoNico sharedInstance].publisher.program.permittedAudience;
    NicoNicoCocosPermittedAudience cocosPermittedAudience;
    if (audience & NicoNicoProgramPermittedAudienceNone) {
        cocosPermittedAudience = AudienceNone;
    } else if (audience & NicoNicoProgramPermittedAudienceCommunityMemberOnly) {
        cocosPermittedAudience = CommunityMemberOnly;
    } else if (audience & NicoNicoProgramPermittedAudienceNicoNicoUsers) {
        cocosPermittedAudience = NicoNicoUsers;
    } else {
        cocosPermittedAudience = All;
    }
    return cocosPermittedAudience;
}

bool NicoNicoCocosPublishProgram::isTimeshiftEnabled() {
    return [NicoNico sharedInstance].publisher.program.timeshiftEnabled;
}

std::vector<std::string> NicoNicoCocosPublishProgram::getTags() {
    std::vector<std::string> tmpTags;
    for (NSString *tag in [NicoNico sharedInstance].publisher.program.tags) {
        tmpTags.push_back([tag UTF8String]);
    }
    return tmpTags;
}

bool NicoNicoCocosPublishProgram::isKaodashi() {
    return [NicoNico sharedInstance].publisher.program.kaodashi;
}

NicoNicoCocosUser NicoNicoCocosPublishProgram::getUser() {
    return NicoNicoCocosUser();
}
