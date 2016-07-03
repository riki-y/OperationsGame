#include <string>

#ifndef NICONICOCOCOSCOMMUNITY_H_
#define NICONICOCOCOSCOMMUNITY_H_

namespace niconico {

/**
 * コミュニティー情報
 */
class NicoNicoCocosCommunity {
 public:
    NicoNicoCocosCommunity();

    /**
     * コミュニティーIDを取得
     * @return コミュニティーID
     */
    std::string getCommunityId();

    /**
     * コミュニティー名を取得
     * @return コミュニティー名
     */
    std::string getName();

    /**
     * コミュニティーのサムネイルURLを取得
     * @return コミュニティーのサムネイルURL
     */
    std::string getThumbnailURL();
};

}

#endif /* NICONICOCOMMUNITY_H_ */
