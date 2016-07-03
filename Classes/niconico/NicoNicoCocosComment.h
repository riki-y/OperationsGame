#include <string>

#ifndef NICONICOCOCOSCOMMENT_H_
#define NICONICOCOCOSCOMMENT_H_

namespace niconico {

/**
 * コメントを描画する際のフォントサイズ
 */
enum NicoNicoCocosCommentSize {
    /**
     * 中サイズ
     */
    MediumSize,
    /**
     * 大サイズ
     */
    BigSize,
    /**
     * 小サイズ
     */
    SmallSize
};

/**
 * コメントを描画する際の描画処理位置
 */
enum NicoNicoCocosCommentPosition {
    /**
     * 通常コメント。画面端から画面端へコメントが流れて表示される
     */
    Center,
    /**
     * 上コメント。画面上部に固定して表示される
     */
    Top,
    /**
     * 下コメント。画面下部に固定して表示される
     */
    Bottom
};

/**
 * ニコニコ動画、ニコニコ生放送に投稿されるコメント
 */
class NicoNicoCocosComment {
 private:
    int number;
    int color;
    std::string body;
    NicoNicoCocosCommentPosition commentPosition;
    NicoNicoCocosCommentSize commentSize;
    int vpos;
    bool mine;

 public:
    /**
     * コンストラクタ
     * @param number コメント番号
     * @param body コメント本文
     * @param commentPosition コメント表示位置
     * @param commentSize コメントサイズ
     * @param color コメント色
     * @param vpos コメントの映像に対する投稿位置。10ms単位
     * @param mine 自分のコメントか否か
     */
    NicoNicoCocosComment(int number, std::string body, NicoNicoCocosCommentPosition commentPosition, NicoNicoCocosCommentSize commentSize, int color,
                    int vpos, bool mine);
    /**
     * コメント番号を取得
     * @return コメント番号
     */
    int getNumber();

    /**
     * コメント色を取得
     * @return コメント色
     */
    int getColor();

    /**
     * コメント本文を取得
     * @return コメント本文
     */
    std::string getText();

    /**
     * コメント描画位置を取得
     * @return 描画位置
     */
    NicoNicoCocosCommentPosition getPosition();

    /**
     * コメントの描画サイズを取得
     * @return コメントの描画サイズ
     */
    NicoNicoCocosCommentSize getSize();

    /**
     * コメントの映像に対する投稿位置を取得。(単位：センチ秒)
     * @return コメントの映像に対する投稿位置
     */
    int getVpos();

    /**
     * ログイン中のユーザ自身が投稿したコメントか否か
     * @return ログイン中のユーザ自身が投稿したコメントであればtrue。そうでなければfalse
     */
    bool isMine();
};

}

#endif /* NICONICOCOMMENT_H_ */
