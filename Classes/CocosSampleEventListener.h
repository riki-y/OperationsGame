//
//  CocosSampleEventListener.h
//  OperationsGame
//
//  Created by 吉田　理貴 on 2016/07/04.
//
//

#ifndef CocosSampleEventListener_h
#define CocosSampleEventListener_h

#define LOG_METHOD_CALL() \
CCLOG("method called: %s.%s", typeid(*this).name(), __FUNCTION__);

#define LOG_METHOD_CALL_WITH_MSG(msg) \
CCLOG("method called: %s.%s [%s]", typeid(*this).name(), __FUNCTION__, msg);

#include "niconico/NicoNicoCocos.h"

namespace niconico {
    
    class CocosSampleEventListener: public niconico::NicoNicoCocosEventListener {
    public:
        
        virtual void niconicoWillShowView() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidShowView() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoWillHideView() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidHideView() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoWillShowChildView() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidShowChildView() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoWillChangeChildViewFrame(NicoNicoCocosRect to,
                                                      NicoNicoCocosRect from) {
            LOG_METHOD_CALL_WITH_MSG(
                                     cocos2d::StringUtils::format(
                                                                  "to:(%d,%d,%d,%d) from:(%d,%d,%d,%d)", to.getLeft(),
                                                                  to.getTop(), to.getRight(), to.getBottom(),
                                                                  from.getLeft(), from.getTop(), from.getRight(),
                                                                  from.getBottom()).c_str());
        }
        
        virtual void niconicoDidChangeChildViewFrame(NicoNicoCocosRect to,
                                                     NicoNicoCocosRect from) {
            LOG_METHOD_CALL_WITH_MSG(
                                     cocos2d::StringUtils::format(
                                                                  "to:(%d,%d,%d,%d) from:(%d,%d,%d,%d)", to.getLeft(),
                                                                  to.getTop(), to.getRight(), to.getBottom(),
                                                                  from.getLeft(), from.getTop(), from.getRight(),
                                                                  from.getBottom()).c_str());
        }
        
        virtual void niconicoWillHideChildView() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidHideChildView() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidStartRecording() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidFinishRecording() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidPauseRecording() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidResumeRecording() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidStartUploading() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidFinishUploading(NicoNicoCocosUploadVideo video) {
            LOG_METHOD_CALL_WITH_MSG(
                                     cocos2d::StringUtils::format("id(%s), title(%s)",
                                                                  video.getVideoId().c_str(), video.getTitle().c_str()).c_str())
        }
        
        virtual void niconicoDidProgressUploading(float progress) {
            LOG_METHOD_CALL_WITH_MSG(
                                     cocos2d::StringUtils::format("progress:%f", progress).c_str())
        }
        
        virtual void niconicoReadyForPublishing() {
            NicoNicoCocos::getInstance().getNicoNicoCocosPublisher().startPublishing();
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidStartPublishing() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidFinishPublishing() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidPausePublishing() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidBeginWaitingForPublishing() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidUpdateProgramStatistics(
                                                        NicoNicoCocosProgramStatistics statistics) {
            LOG_METHOD_CALL_WITH_MSG(
                                     cocos2d::StringUtils::format(
                                                                  "comments(%d), reservations(%d), watches(%d)",
                                                                  statistics.getCommentCount(),
                                                                  statistics.getTimeshiftReservationCount(),
                                                                  statistics.getWatchCount()).c_str())
        }
        
        virtual void niconicoDidUpdateElapsedTime(int64_t elapsedtime,
                                                  int64_t remainingTime) {
            elapsedTimeNotifyCount++;
            if (elapsedTimeNotifyCount > 40) {
                LOG_METHOD_CALL_WITH_MSG(
                                         cocos2d::StringUtils::format("elapsed:%lld, remaining:%lld",
                                                                      elapsedtime, remainingTime).c_str())
                elapsedTimeNotifyCount = 0;
            }
        }
        
        virtual void niconicoDidPostBroadcasterComment() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidFailPostingBroadcasterComment(
                                                              NicoNicoCocosError error) {
            LOG_METHOD_CALL_WITH_MSG(
                                     cocos2d::StringUtils::format("code:%d, desc:%s",
                                                                  error.getErrorCode(), error.getDescription().c_str()).c_str())
        }
        
        virtual void niconicoDidReceiveComment(NicoNicoCocosComment comment) {
            LOG_METHOD_CALL_WITH_MSG(comment.getText().c_str())
        }
        
        virtual void niconicoDidReceiveCommentWhileDisconnected(
                                                                NicoNicoCocosComment comment) {
            LOG_METHOD_CALL_WITH_MSG(comment.getText().c_str())
        }
        
        virtual void niconicoDidFailWithError(NicoNicoCocosError error) {
            LOG_METHOD_CALL_WITH_MSG(
                                     cocos2d::StringUtils::format("code:%d, desc:%s",
                                                                  error.getErrorCode(), error.getDescription().c_str()).c_str())
        }
        
        virtual void niconicoCameraDidStartSession() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoCameraDidStopSession() {
            LOG_METHOD_CALL()
        }
        
        virtual void niconicoDidFinishAuthenticate(NicoNicoCocosUser user) {
            LOG_METHOD_CALL_WITH_MSG(
                                     cocos2d::StringUtils::format("id(%s), name(%s)",
                                                                  user.getUserId().c_str(), user.getNickName().c_str()).c_str())
        }
        
    private:
        int elapsedTimeNotifyCount = 0;
        
    };
    
}  // namespace niconico

#endif /* CocosSampleEventListener_h */
