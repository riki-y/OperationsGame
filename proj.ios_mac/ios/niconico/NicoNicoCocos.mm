#include <NicoNico/NicoNico.h>
#include <NicoNico/NicoNicoFeatures.h>
#include "UIColor+NicoNico.h"
#include "NicoNicoCocos.h"
#include "NicoNicoCocosFeatures.h"
#include "NicoNicoCocosEventListener.h"

@interface NicoNicoCocosEvent : NSObject <NicoNicoDelegate, NicoNicoCameraDelegate>

@end

static NicoNicoCocosEvent *niconicoCocosEvent = nil;

using namespace niconico;

NicoNicoCocosFeatures *niconicoCocosFeatures;
NicoNicoCocosFeatures *defaultNicoNicoCocosFeatures = new NicoNicoCocosFeatures();
NicoNicoCocosEventListener *niconicoCocosEventListener;


#pragma mark - NicoNicoCocos

NicoNicoCocos::NicoNicoCocos() {
}

NicoNicoCocos::~NicoNicoCocos() {
    delete defaultNicoNicoCocosFeatures;
}

void NicoNicoCocos::initialize(std::string clientId, std::string clientSecret, NicoNicoCocosFeatures *features, NicoNicoCocosEventListener *eventListener) {
    if (features) {
        niconicoCocosFeatures = features;
    }
    
    if (eventListener) {
        niconicoCocosEventListener = eventListener;
        
        if (!niconicoCocosEvent) {
            niconicoCocosEvent = [[NicoNicoCocosEvent alloc] init];
        }
    }
    
    [[NicoNico sharedInstance] setClientId:[NSString stringWithUTF8String:clientId.c_str()]
                              clientSecret:[NSString stringWithUTF8String:clientSecret.c_str()]];
    [NicoNico sharedInstance].parentRootViewController = [UIApplication sharedApplication].keyWindow.rootViewController;
}

std::string NicoNicoCocos::getVersion() {
    NSString *version = [NicoNico version];
    return [version UTF8String];
}

bool NicoNicoCocos::isEnabled() {
    return true;
}

void NicoNicoCocos::setNicoNicoCocosConfigurationMode(NicoNicoCocosConfigurationMode configurationMode) {
    [NicoNico sharedInstance].configurationMode = (NicoNicoConfigurationMode)static_cast<int>(configurationMode);
}

void NicoNicoCocos::authenthicate() {
    [[NicoNico sharedInstance] authenticateWithCompletionHandler:^(NicoNicoUser *user) {
        if (niconicoCocosEventListener) {
            niconicoCocosEventListener->niconicoDidFinishAuthenticate(NicoNicoCocosUser());
        }
    }];
}

void NicoNicoCocos::destroySession() {
    [[NicoNico sharedInstance] destroySession];
}

NicoNicoCocosCapture NicoNicoCocos::getNicoNicoCocosCapture() {
    return NicoNicoCocosCapture();
}

NicoNicoCocosPublisher NicoNicoCocos::getNicoNicoCocosPublisher() {
    
    return NicoNicoCocosPublisher();
}

NicoNicoCocosCamera NicoNicoCocos::getNicoNicoCocosCamera() {
    return NicoNicoCocosCamera();
}

NicoNicoCocosUser NicoNicoCocos::getCurrentUser() {
    return NicoNicoCocosUser();
}

bool NicoNicoCocos::isViewVisible() {
    return [NicoNico sharedInstance].isViewVisible;
}

bool NicoNicoCocos::isChildViewVisible() {
    return [NicoNico sharedInstance].isChildViewVisible;
}

bool NicoNicoCocos::isUploading() {
    return [NicoNico sharedInstance].isUploading;
}

bool NicoNicoCocos::recordedMovieExists() {
    return [NicoNico sharedInstance].recordedMovieExists;
}

bool NicoNicoCocos::showUploadView() {
    return [[NicoNico sharedInstance] showUploadView];
}

bool NicoNicoCocos::showUploadView(niconico::NicoNicoCocosCategory category, std::string title, std::string description, std::vector<std::string> editableTags, std::vector<std::string> uneditableTags) {
    
    NSString *titleString = [NSString stringWithUTF8String:title.c_str()];
    NSString *descriptionString = [NSString stringWithUTF8String:description.c_str()];
    NSMutableArray *editableTagsArray = [NSMutableArray array];
    for(std::string & editableTag : editableTags) {
        [editableTagsArray addObject:[NSString stringWithUTF8String:editableTag.c_str()]];
    }
    
    NSMutableArray *uneditableTagsArray = [NSMutableArray array];
    for(std::string & uneditableTag : uneditableTags) {
        [uneditableTagsArray addObject:[NSString stringWithUTF8String:uneditableTag.c_str()]];
    }
    
    return [[NicoNico sharedInstance] showUploadViewWithCategory:(NicoNicoCategory)static_cast<int>(category) title:titleString description:descriptionString editableTags:editableTagsArray uneditableTags:uneditableTagsArray];
}

bool NicoNicoCocos::showPublishView() {
    return [[NicoNico sharedInstance] showPublishView];
}

bool NicoNicoCocos::showPublishView(std::string title, std::string description, std::vector<std::string> tags) {
    NSString *titleString = [NSString stringWithUTF8String:title.c_str()];
    NSString *descriptionString = [NSString stringWithUTF8String:description.c_str()];
    NSMutableArray *tagsArray = [NSMutableArray array];
    for(std::string & tag : tags) {
        [tagsArray addObject:[NSString stringWithUTF8String:tag.c_str()]];
    }
    
    return [[NicoNico sharedInstance] showPublishViewWithTitle:titleString description:descriptionString uneditableTags:tagsArray];
}

bool NicoNicoCocos::showPublishMenu() {
    return [[NicoNico sharedInstance] showPublishMenu];
}

bool NicoNicoCocos::showPortalViewWithPickUpContents(std::vector<std::string> pickUpContents) {
    std::vector<std::string> tags;
    return showPortalViewWithPickUpContents(pickUpContents, "", "", tags);
}

bool NicoNicoCocos::showPortalViewWithPickUpContents(std::vector<std::string> pickUpContents, std::string title, std::string description, std::vector<std::string> tags) {
    
    NSMutableArray *contentsArray = [NSMutableArray array];
    for(std::string & pickUpContent : pickUpContents) {
        [contentsArray addObject:[NSString stringWithUTF8String:pickUpContent.c_str()]];
    }
    
    NSString *titleString = [NSString stringWithUTF8String:title.c_str()];
    NSString *descriptionString = [NSString stringWithUTF8String:description.c_str()];
    NSMutableArray *tagsArray = [NSMutableArray array];
    for(std::string & tag : tags) {
        [tagsArray addObject:[NSString stringWithUTF8String:tag.c_str()]];
    }
    
    return [[NicoNico sharedInstance] showPortalViewWithPickUpContents:contentsArray
                                                          programTitle:titleString
                                                           description:descriptionString
                                                        uneditableTags:tagsArray];
}


#pragma mark - NicoNicoCocosPublisher

void NicoNicoCocosPublisher::postBroadcasterComment(std::string comment) {
    [[NicoNico sharedInstance].publisher postBroadcasterCommentText:[NSString stringWithUTF8String:comment.c_str()]
                                                  completionHandler:^(NSError *error) {
                                                      if (niconicoCocosEventListener) {
                                                          if (error) {
                                                              niconicoCocosEventListener->niconicoDidFailPostingBroadcasterComment(NicoNicoCocosError((int)error.code, [error.domain UTF8String], [error.localizedDescription UTF8String]));
                                                          } else {
                                                              niconicoCocosEventListener->niconicoDidPostBroadcasterComment();
                                                          }
                                                      }
                                                  }];
}


#pragma mark - NicoNicoCocosEvent

@implementation NicoNicoCocosEvent

- (id)init
{
    self = [super init];
    if (self) {
        [[NicoNico sharedInstance] setDelegate:self];
        [[NicoNico sharedInstance].camera setDelegate:self];
    }
    return self;
}

- (void)niconicoWillShowView {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoWillShowView();
}

- (void)niconicoDidShowView {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidShowView();
}

- (void)niconicoWillHideView {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoWillHideView();
}

- (void)niconicoDidHideView {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidHideView();
}

- (void)niconicoWillShowChildView:(UIView *)view {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoWillShowChildView();
}

- (void)niconicoDidShowChildView:(UIView *)view {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidShowChildView();
}

- (void)niconicoWillChangeChildView:(UIView *)view toFrame:(CGRect)frame
{
    if (!niconicoCocosEventListener) {
        return;
    }
    niconico::NicoNicoCocosRect to(frame.origin.x, frame.origin.y, frame.size.width, frame.size.height);
    niconico::NicoNicoCocosRect from(view.frame.origin.x, view.frame.origin.y, view.frame.size.width, view.frame.size.height);
    niconicoCocosEventListener->niconicoWillChangeChildViewFrame(to, from);
}

- (void)niconicoDidChangeChildView:(UIView *)view fromFrame:(CGRect)frame
{
    if (!niconicoCocosEventListener) {
        return;
    }
    niconico::NicoNicoCocosRect to(view.frame.origin.x, view.frame.origin.y, view.frame.size.width, view.frame.size.height);
    niconico::NicoNicoCocosRect from(frame.origin.x, frame.origin.y, frame.size.width, frame.size.height);
    niconicoCocosEventListener->niconicoDidChangeChildViewFrame(to, from);
}

- (void)niconicoWillHideChildView {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoWillHideChildView();
}

- (void)niconicoDidHideChildView {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidHideChildView();
}

- (void)niconicoDidStartRecording {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidStartRecording();
}

- (void)niconicoDidFinishRecording {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidFinishRecording();
}

- (void)niconicoDidPauseRecording {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidPauseRecording();
}

- (void)niconicoDidResumeRecording {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidResumeRecording();
}

- (void)niconicoDidStartUploading {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidStartUploading();
}

- (void)niconicoDidFinishUploading:(NicoNicoUploadVideo *)video {
    if (!niconicoCocosEventListener) {
        return;
    }
    
    niconico::NicoNicoCocosUser user([video.user.userId UTF8String],
                                     [video.user.nickName UTF8String],
                                     [[video.user.thumbnailSmallURL absoluteString] UTF8String],
                                     [[video.user.thumbnailURL absoluteString] UTF8String],
                                     video.user.isPremium);
    
    std::vector<std::string> tags;
    for (NSString *tag in video.tags) {
        tags.push_back([tag UTF8String]);
    }
    
    std::vector<std::string> uneditableTags;
    for (NSString *tag in video.uneditableTags) {
        uneditableTags.push_back([tag UTF8String]);
    }
    
    std::vector<std::string> editableTags;
    for (NSString *tag in video.editableTags) {
        editableTags.push_back([tag UTF8String]);
    }
    
    niconico::NicoNicoCocosUploadVideo cocosVideo([video.videoId UTF8String],
                                                  [video.title UTF8String],
                                                  [video.debugDescription UTF8String],
                                                  user,
                                                  video.duration*1000,
                                                  tags,
                                                  uneditableTags,
                                                  editableTags,
                                                  static_cast<niconico::NicoNicoCocosCategory>(video.category),
                                                  [[video.watchURL absoluteString] UTF8String]);
    
    niconicoCocosEventListener->niconicoDidFinishUploading(cocosVideo);
}

- (void)niconicoDidProgressUploading:(CGFloat)progress {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidProgressUploading(progress);
}

- (void)niconicoReadyForPublishing:(NicoNicoPublisher *)publisher
{
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoReadyForPublishing();
}

- (void)niconicoDidStartPublishing {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidStartPublishing();
}

- (void)niconicoDidFinishPublishing {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidFinishPublishing();
}

- (void)niconicoDidPausePublishing {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidPausePublishing();
}

- (void)niconicoDidBeginWaitingForPublishing {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidBeginWaitingForPublishing();
}

- (void)niconicoDidUpdateProgramStatistics:(NicoNicoProgramStatistics *)statistics {
    if (!niconicoCocosEventListener) {
        return;
    }
    NicoNicoCocosProgramStatistics programStatistics = NicoNicoCocos::getInstance().getNicoNicoCocosPublisher().getProgram().getStatistics();
    niconicoCocosEventListener->niconicoDidUpdateProgramStatistics(programStatistics);
}

- (void)niconicoDidUpdateElapsedTime:(NSTimeInterval)elapsedTime remainingTime:(NSTimeInterval)remainingTime {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidUpdateElapsedTime(elapsedTime*1000, remainingTime*1000);
}

- (void)niconicoDidReceiveComment:(NicoNicoComment *)comment {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidReceiveComment([self cocosComment:comment]);
}

- (void)niconicoDidReceiveCommentWhileDisconnected:(NicoNicoComment *)comment {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoDidReceiveCommentWhileDisconnected([self cocosComment:comment]);
}

- (niconico::NicoNicoCocosComment)cocosComment:(NicoNicoComment*)comment
{
    niconico::NicoNicoCocosCommentPosition position = static_cast<niconico::NicoNicoCocosCommentPosition>(comment.position);
    niconico::NicoNicoCocosCommentSize size = static_cast<niconico::NicoNicoCocosCommentSize>(comment.size);
    
    return niconico::NicoNicoCocosComment((int)comment.number,
                                          [comment.text UTF8String],
                                          position,
                                          size,
                                          (int)comment.color.intValue,
                                          (int)comment.vpos,
                                          comment.mine);
}

- (void)niconicoDidFailWithError:(NSError *)error {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconico::NicoNicoCocosError cocosError((int)error.code, [error.domain UTF8String], [error.localizedDescription UTF8String]);
    niconicoCocosEventListener->niconicoDidFailWithError(cocosError);
}

- (void)niconicoCameraDidStartSession {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoCameraDidStartSession();
}

- (void)niconicoCameraDidStopSession {
    if (!niconicoCocosEventListener) {
        return;
    }
    niconicoCocosEventListener->niconicoCameraDidStopSession();
}

@end


#pragma mark - NicoNicoFeatures

@implementation NicoNicoFeatures (Cocos)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

+ (NicoNicoAvailableServiceType)availableServiceType {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->availableServiceType();
    }
    return defaultNicoNicoCocosFeatures->availableServiceType();
}

+ (BOOL)shouldShowAccountSignupButton
{
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->shouldShowAccountSignupButton();
    }
    return defaultNicoNicoCocosFeatures->shouldShowAccountSignupButton();
}

+ (NSString*)frameworkType;
{
    std::string type;
    if (niconicoCocosFeatures) {
        type = niconicoCocosFeatures->frameworkType();
    } else {
        type = defaultNicoNicoCocosFeatures->frameworkType();
    }
    return [[NSString stringWithUTF8String:type.c_str()] copy];
}

+ (NSString*)supportValidationPolicy
{
    std::string policy;
    if (niconicoCocosFeatures) {
        policy = niconicoCocosFeatures->supportValidationPolicy();
    } else {
        policy = defaultNicoNicoCocosFeatures->supportValidationPolicy();
    }
    return [[NSString stringWithUTF8String:policy.c_str()] copy];
}

+ (UInt64)storageFreeSpaceLimit
{
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->storageFreeSpaceLimit();
    }
    return defaultNicoNicoCocosFeatures->storageFreeSpaceLimit();
}

+ (BOOL)supportsOpenAL
{
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->supportsOpenAL();
    }
    return defaultNicoNicoCocosFeatures->supportsOpenAL();
}

+ (BOOL)supportsAVAudioPlayer {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->supportsAVAudioPlayer();
    }
    return defaultNicoNicoCocosFeatures->supportsAVAudioPlayer();
}

+ (BOOL)supportsAudioUnit {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->supportsAudioUnit();
    }
    return defaultNicoNicoCocosFeatures->supportsAudioUnit();
}

+ (BOOL)supportsAuxiliaryAudioInput {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->supportsAuxiliaryAudioInput();
    }
    return defaultNicoNicoCocosFeatures->supportsAuxiliaryAudioInput();
}

+ (BOOL)shouldChangeAudioSessionSettings {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->shouldChangeAudioSessionSettings();
    }
    return defaultNicoNicoCocosFeatures->shouldChangeAudioSessionSettings();
}

+ (BOOL)shouldInterruptOtherAudio {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->shouldInterruptOtherAudio();
    }
    return defaultNicoNicoCocosFeatures->shouldInterruptOtherAudio();
}

+ (BOOL)enableBackgroundUpload {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->enableBackgroundUpload();
    }
    return defaultNicoNicoCocosFeatures->enableBackgroundUpload();
}

+ (BOOL)shouldAutoResumeUploading {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->shouldAutoResumeUploading();
    }
    return defaultNicoNicoCocosFeatures->shouldAutoResumeUploading();
}

+ (NSUInteger)maxCapacityForLiveComments {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->maxCapacityForLiveComments();
    }
    return niconicoCocosFeatures->maxCapacityForLiveComments();
}

+ (BOOL)enableRenderingCommentsForPublish {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->enableRenderingCommentsForPublish();
    }
    return defaultNicoNicoCocosFeatures->enableRenderingCommentsForPublish();
}

+ (BOOL)shouldGenerateDummyCommentsForPublishing {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->shouldGenerateDummyCommentsForPublishing();
    }
    return defaultNicoNicoCocosFeatures->shouldGenerateDummyCommentsForPublishing();
}

+ (BOOL)permittedRecordingCameraForPublishing {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->permittedRecordingCameraForPublishing();
    }
    return defaultNicoNicoCocosFeatures->permittedRecordingCameraForPublishing();
}

+ (BOOL)enableShareTwitter {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->enableShareTwitter();
    }
    return defaultNicoNicoCocosFeatures->enableShareTwitter();
}

+ (NSString *)twitterClientId {
    std::string clientId;
    if (niconicoCocosFeatures) {
        clientId = niconicoCocosFeatures->twitterClientId();
    } else {
        clientId = defaultNicoNicoCocosFeatures->twitterClientId();
    }
    return [[NSString stringWithUTF8String:clientId.c_str()] copy];
}

+ (NSString *)twitterClientSecret {
    std::string clientSecret;
    if (niconicoCocosFeatures) {
        clientSecret = niconicoCocosFeatures->twitterClientSecret();
    } else {
        clientSecret = defaultNicoNicoCocosFeatures->twitterClientSecret();
    }
    return [[NSString stringWithUTF8String:clientSecret.c_str()] copy];
}

+ (BOOL)enableShareFacebook {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->enableShareFacebook();
    }
    return defaultNicoNicoCocosFeatures->enableShareFacebook();
}

+ (NSString *)facebookClientId {
    std::string clientId;
    if (niconicoCocosFeatures) {
        clientId = niconicoCocosFeatures->facebookClientId();
    } else {
        clientId = defaultNicoNicoCocosFeatures->facebookClientId();
    }
    return [[NSString stringWithUTF8String:clientId.c_str()] copy];
}

+ (NSString *)facebookClientSecret {
    std::string clientSecret;
    if (niconicoCocosFeatures) {
        clientSecret = niconicoCocosFeatures->facebookClientSecret();
    } else {
        clientSecret = defaultNicoNicoCocosFeatures->facebookClientSecret();
    }
    return [[NSString stringWithUTF8String:clientSecret.c_str()] copy];
}

+ (BOOL)enableShareYouTube {
    if (niconicoCocosFeatures) {
        return niconicoCocosFeatures->enableShareYouTube();
    }
    return defaultNicoNicoCocosFeatures->enableShareYouTube();
}

+ (NSString *)youTubeClientId {
    std::string clientId;
    if (niconicoCocosFeatures) {
        clientId = niconicoCocosFeatures->youTubeClientId();
    } else {
        clientId = defaultNicoNicoCocosFeatures->youTubeClientId();
    }
    return [[NSString stringWithUTF8String:clientId.c_str()] copy];
}

+ (NSString *)youTubeClientSecret {
    std::string clientSecret;
    if (niconicoCocosFeatures) {
        clientSecret = niconicoCocosFeatures->youTubeClientSecret();
    } else {
        clientSecret = defaultNicoNicoCocosFeatures->youTubeClientSecret();
    }
    return [[NSString stringWithUTF8String:clientSecret.c_str()] copy];
}

@end
