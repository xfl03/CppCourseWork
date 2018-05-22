#ifndef BANKWORK_BASICRESPONCE_H
#define BANKWORK_BASICRESPONCE_H

#include <string>

using namespace std;

/**
 * 控制器的基础响应类
 * 用于记录控制器响应的数据
 */
class BasicResponce {
public:
    BasicResponce(int status, string message) :
            status(status), message(message) {}

    /**
     * 响应状态码
     * 0-正常
     * 其他-错误
     */
    int status;
    /**
     * 响应文本
     */
    string message;
};

#endif //BANKWORK_BASICRESPONCE_H
