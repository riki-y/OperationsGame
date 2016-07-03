#include <string>
#include <vector>
#include "NicoNicoCocosUser.h"

#ifndef NICONICOCOCOSUPLOADVIDEO_H_
#define NICONICOCOCOSUPLOADVIDEO_H_

namespace niconico {
    
/**
 * ニコニコ動画カテゴリ
 *
 * 動画投稿時に設定する動画のカテゴリ
 */
enum NicoNicoCocosCategory {
    /**
     * 音楽
     */
    Music,
    /**
     * エンターテイメント
     */
    Entertainment,
    /**
     * アニメ
     */
    Anime,
    /**
     * ゲーム
     */
    Game,
    /**
     * ラジオ
     */
    Radio,
    /**
     * スポーツ
     */
    Sport,
    /**
     * 科学
     */
    Science,
    /**
     * 料理
     */
    Cooking,
    /**
     * 政治
     */
    Politics,
    /**
     * 動物
     */
    Animal,
    /**
     * 歴史
     */
    History,
    /**
     * 自然
     */
	Nature,
    /**
     * ニコニコ動画講座
     */
    Lecture,
    /**
     * 演奏してみた
     */
    Play,
    /**
     * 歌ってみた
     */
    Sing,
    /**
     * 踊ってみた
     */
    Dance,
    /**
     * 描いてみた
     */
    Draw,
    /**
     * ニコニコ技術部
     */
    NicoTech,
    /**
     * アイドルマスター
     */
    IdolMaster,
    /**
     * 東方
     */
    Toho,
    /**
     * VOCALOID
     */
    Vocaloid,
    /**
     * 例のアレ
     */
    Are,
    /**
     * 日記
     */
    Diary,
    /**
     * その他
     */
    Other,
    /**
     * ニコニコインディーズ
     */
    NicoNicoIndies,
    /**
     * 旅行
     */
    Travel,
    /**
     * 車載動画
     */
    Drive,
    /**
     * ニコニコ手芸部
     */
    Handcraft,
    /**
     * 作ってみた
     */
    Make,
    /**
     * R-18（※このカテゴリでの投稿はできません）
     */
    R18
};

/**
 * 動画情報
 */
class NicoNicoCocosUploadVideo {
private:
    std::string videoId;
    std::string title;
    std::string videoDescription;
    NicoNicoCocosUser user;
    int64_t duration;
    std::vector<std::string> tags;
    std::vector<std::string> uneditableTags;
    std::vector<std::string> editableTags;
    NicoNicoCocosCategory category;
    std::string watchURL;
    
public:

    /**
     * コンストラクタ
     * @param videoId 動画ID
     * @param title 動画タイトル
     * @param videoDescription 動画詳細
     * @param user ユーザー
     * @param duration 動画の長さ
     * @param tags 全てのタグのリスト
     * @param uneditableTags 編集不可能なタグのリスト
     * @param editableTags 編集可能なタグのリスト
     * @param category 動画カテゴリ
     * @param watchURL 動画視聴URL
     */
    NicoNicoCocosUploadVideo(std::string videoId, std::string title, std::string videoDescription, NicoNicoCocosUser user, int64_t duration, std::vector<std::string> tags, std::vector<std::string> uneditableTags, std::vector<std::string> editableTags, NicoNicoCocosCategory category, std::string watchURL);
    
    /**
     * 動画IDを取得
     * @return 動画ID
     */
    std::string getVideoId();
    
    /**
     * 動画タイトルを取得
     * @return 動画タイトル
     */
    std::string getTitle();
    
    /**
     * 動画説明文を取得
     * @return 動画説明文
     */
    std::string getVideoDescription();
    
    /**
     * 動画投稿ユーザを取得
     * @return 動画投稿ユーザ
     */
    NicoNicoCocosUser getUser();
    
    /**
     * 動画の長さ(秒)を取得
     * @return 動画の長さ
     */
    int64_t getDuration();
    
    /**
     * 動画に付与された全てのタグを取得
     * @return 動画に付与された全てのタグのリスト
     */
    std::vector<std::string> getTags();
    
    /**
     * 動画に付与された編集不可タグを取得
     * @return 動画に付与された編集不可タグのリストを取得
     */
    std::vector<std::string> getUneditableTags();
    
    /**
     * 動画に付与された編集可能タグを取得する
     * @return 動画に付与された編集可能タグのリスト
     */
    std::vector<std::string> getEditableTags();
    
    /**
     * カテゴリを取得
     * @return カテゴリ
     */
    NicoNicoCocosCategory getCategory();
    
    /**
     * 動画視聴のURLを取得
     * @return 視聴URL
     */
    std::string getWatchURL();
};

}

#endif
