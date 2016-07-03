#include <string>

#ifndef NICONICOCOCOSUSER_H_
#define NICONICOCOCOSUSER_H_

namespace niconico {

/**
 *  niconicoのユーザ情報
 */
class NicoNicoCocosUser {
 private:
    std::string userId;
    std::string nickname;
    std::string thumbnailSmallURL;
    std::string thumbnailURL;
    bool premium;
 public:
    /**
     * コンストラクタ
     * @param userId ユーザID
     * @param nickname ニックネーム
     * @param thumbnailSmallURL 小サムネイルのURL
     * @param thumbnailURL サムネイルのURL
     * @param premium プレミアム会員か否か
     */
    NicoNicoCocosUser(std::string userId, std::string nickname, std::string thumbnailSmallURL, std::string thumbnailURL, bool premium);
    NicoNicoCocosUser();
    
    /**
     * ユーザのIDを取得
     * @return ユーザーID
     */
    std::string getUserId();

    /**
     * ユーザに設定されたニックネームを取得
     * @return ニックネーム
     */
    std::string getNickName();

    /**
     * ユーザに設定された小プロフィール画像URLを取得
     * @return 小プロフィール画像のURL
     */
    std::string getThumbnailSmallURL();

    /**
     * ユーザに設定されたプロフィール画像URLを取得
     * @return プロフィール画像URL
     */
    std::string getThumbnailURL();

    /**
     * プレミアム状態を取得
     * @return プレミアム会員ならtrue。そうでなければfalse
     */
    bool isPremium();

};
}

#endif /* NICONICOCOCOSUSER_H_ */
