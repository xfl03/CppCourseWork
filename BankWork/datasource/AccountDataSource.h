#ifndef BANKWORK_ACCOUNTDATASOURCE_H
#define BANKWORK_ACCOUNTDATASOURCE_H

#include <vector>
#include "../Constant.h"
#include "../io/FileIO.h"
#include "../domain/Account.h"

using namespace std;

/**
 * 账户的文件数据源类
 * 负责直接操作账户文件
 * @note 文件格式 每行一条数据 '账号 密码 名字 性别 手机 身份证 余额'
 * @note 请保持单例
 */
class AccountDataSource {
public:
    /**
     * 创建对象，文件数据源为 Constant::FILE_PATH
     */
    AccountDataSource();

    /**
     * 从文件中读取所有账户
     */
    void Read();

    /**
     * 将所有账户写入文件
     */
    void Write();

    vector<Account> *GetAccounts();

private:
    /**
     * 文件数据源
     */
    FileIO file;
    /**
     * 账户数组
     */
    vector<Account> *accounts;
};

#endif //BANKWORK_ACCOUNTDATASOURCE_H
