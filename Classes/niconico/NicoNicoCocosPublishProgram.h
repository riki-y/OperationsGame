#include <string>
#include <vector>
#include "NicoNicoCocosProgramStatistics.h"
#include "NicoNicoCocosCommunity.h"
#include "NicoNicoCocosUser.h"

#ifndef NICONICOCOCOSPUBLISHPROGRAM_H_
#define NICONICOCOCOSPUBLISHPROGRAM_H_

namespace niconico {

/**
 *  生放送番組の公開範囲
 */
enum NicoNicoCocosPermittedAudience {
    /**
     * 非公開
     */
    AudienceNone,
    /**
     * コミュニティメンバーに限定して公開
     */
    CommunityMemberOnly,
    /**
     * 全てのニコニコユーザに公開
     */
    NicoNicoUsers,
    /**
     * 非ログインユーザを含めた全てのユーザに公開
     */
    All
};

/**
 * 生放送番組情報
 */
class NicoNicoCocosPublishProgram {
 public:
    NicoNicoCocosPublishProgram();

    /**
     * 生放送番組IDを取得
     * @return 生放送番組ID
     */
    std::string getProgramId();

    /**
     * 番組タイトルを取得
     * @return 番組タイトル
     */
    std::string getTitle();

    /**
     * 番組説明文を取得
     * @return 番組説明文
     */
    std::string getProgramDescription();

    /**
     * サムネイルURLを取得
     * @return サムネイルURL
     */
    std::string getThumbnailURL();

    /**
     * 統計情報を取得
     * @return 統計情報
     */
    NicoNicoCocosProgramStatistics getStatistics();

    /**
     * コミュニティ情報を取得
     * @return コミュニティー情報
     */
    NicoNicoCocosCommunity getCommunity();

    /**
     * 開演時間を取得
     * @return 開演時間
     */
    int64_t getBeginDate();

    /**
     * 終了時間を取得
     * @return 終了時間
     */
    int64_t getEndDate();

    /**
     * 残り時間を取得
     * @return 残り時間（ミリ秒）
     */
    int64_t getRemainingTime();

    /**
     * 番組の公開範囲を取得
     * @return 公開範囲
     */
    NicoNicoCocosPermittedAudience getPermittedAudience();

    /**
     * タイムシフトを公開するか
     * @return 公開する場合true。そうでなければfalse
     */
    bool isTimeshiftEnabled();

    /**
     * タグ一覧を取得
     * @return タグ一覧
     */
    std::vector<std::string> getTags();

    /**
     * 顔出しか否か
     * @return 顔出しの場合true。そうでなければfalse
     */
    bool isKaodashi();

    /**
     * 配信ユーザを取得
     * @return 配信ユーザ
     */
    NicoNicoCocosUser getUser();
};

}

#endif /* NICONICOCOCOSPUBLISHER_H_ */
