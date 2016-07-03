#include <string>

#ifndef NICONICOCOCOSPROGRAMSTATISTICS_H_
#define NICONICOCOCOSPROGRAMSTATISTICS_H_

namespace niconico {

/**
 * 番組統計情報
 * 配信中の番組の各種統計情報を管理する
 */
class NicoNicoCocosProgramStatistics {
 public:
    NicoNicoCocosProgramStatistics();

    /**
     * 来場者数を取得
     * @return 来場者数
     */
    int getWatchCount();

    /**
     * コメント数を取得
     * @return コメント数
     */
    int getCommentCount();

    /**
     * タイムシフト予約数を取得
     * @return タイムシフト予約数
     */
    int getTimeshiftReservationCount();
};

}

#endif /* NICONICOCOCOSPROGRAMSTATISTICS_H_ */
