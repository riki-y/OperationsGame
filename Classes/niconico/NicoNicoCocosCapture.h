#ifndef NICONICOCOCOSCAPTURE_H_
#define NICONICOCOCOSCAPTURE_H_

namespace niconico {

/**
 * 録画機能
 * @warning iOSのみ対応
 */
class NicoNicoCocosCapture {
    public:
    NicoNicoCocosCapture();
    
    /**
     * 録画映像のフレームレートを取得する
     * @warning iOSのみ（Androidでは常に0）
     * @return フレームレート
     */
    int getFramesPerSecond();
    
    /**
     * 録画する映像データのフレームレートを設定する。
     * @warning iOSのみ（Androidでは設定は無視される）
     * @param fps フレームレート
     */
    void setFramesPerSecond(int fps);
    
    /**
     * 録画中かどうかを返す
     * @warning iOSのみ（Androidでは常にfalse）
     * @return 録画中であればtrue。そうでなければfalse
     */
    bool isRecording();
    
    /**
     * 録画の開始
     * @warning iOSのみ（Androidでは何も起きず、常にfalse）
     * @return 開始された場合true。そうでなければfalse
     */
    bool startRecording();
    
    /**
     * 録画の停止
     * @warning iOSのみ（Androidでは何も起きず、常にfalse）
     * @return 停止された場合true。そうでなければfalse
     */
    bool stopRecording();
    
    /**
     * 録画の一時停止
     * @warning iOSのみ（Androidでは何も起きず、常にfalse）
     * @return 一時停止された場合true。そうでなければfalse
     */
    bool pauseRecording();
    
    /**
     * 録画の再開
     * @warning iOSのみ（Androidでは何も起きず、常にfalse）
     * @return 再開された場合true。そうでなければfalse
     */
    bool resumeRecording();
};
}

#endif /* NICONICOCOCOSCAPTURE_H_ */
