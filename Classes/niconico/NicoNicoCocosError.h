#include <string>

#ifndef NICONICOCOCOSERROR_H_
#define NICONICOCOCOSERROR_H_

namespace niconico {

/**
 * SDKから渡されるエラークラス
 */
class NicoNicoCocosError {
 private:
    const int errorCode;
    const std::string errorDomain;
    const std::string description;
 public:
    /**
     * コンストラクタ
     * @param code エラーコード
     * @param domain エラードメイン
     * @param description エラー詳細
     */
    NicoNicoCocosError(int code, const std::string& domain, const std::string& description)
            : errorCode(code),
              errorDomain(domain),
              description(description) {

    }
    /**
     * エラードメインを取得
     * @return エラードメイン
     */
    std::string getErrorDomain() {
        return errorDomain;
    }
    /**
     * エラーコードを取得
     * @return エラーコード
     */
    int getErrorCode() {
        return errorCode;
    }
    /**
     * エラー詳細を取得
     * @return エラー詳細
     */
    std::string getDescription() {
        return description;
    }
};

}

#endif
