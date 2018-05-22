#ifndef BANKWORK_ACCOUNTDAO_H
#define BANKWORK_ACCOUNTDAO_H

#include "../datasource/AccountDataSource.h"

/**
 * 账户数据访问对象类
 * 负责控制对账户文件的访问
 * @note 请保持单例
 */
class AccountDAO {
public:
    /**
     * 插入账户
     * @param 被插入的账户
     */
    void InsertAccount(Account &);

    /**
     * 根据卡号查找账户
     * @param 卡号
     * @return 账户(可能为NULL)
     */
    Account *SelectAccountByID(string);

    /**
     * 删除账户
     * @param 被删除的账户
     */
    void DeleteAccount(Account &);

    /**
     * 更改账户
     * @param 被更改的账户
     */
    void UpdateAccount(Account *);

private:
    /**
     * 账户数据源
     */
    AccountDataSource data;
};

#endif //BANKWORK_ACCOUNTDAO_H
