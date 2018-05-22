#ifndef BANKWORK_ACCOUNTSERVICE_H
#define BANKWORK_ACCOUNTSERVICE_H

#include "../dao/AccountDAO.h"

/**
 * 账户服务类
 * 对账户的直接操作止于此
 * 负责操作账户
 * @note 请保持单例
 */
class AccountService {
public:
    /**
     * 检查账户ID是否已经被注册
     * @param 被检查的ID
     * @return 是否已经被注册
     */
    bool CheckAccountExist(string id);

    /**
     * 注册账户
     * @param 账户信息
     */
    Account *DoRegister(Account &acc);

    /**
     * 登录账户
     * @param 账号
     * @param 经过hash的密码
     */
    Account *DoLogin(string id, string pass);

    /**
     * 存款
     * @param 账户
     * @param 存款数目
     */
    void DoDeposit(Account *acc, double amount);

    /**
     * 检查账户能否完成取款
     * @param 账户
     * @param 取款数目
     */
    bool CheckWithDrawal(Account *acc, double amount);

    /**
     * 取款
     * @param 账户
     * @param 取款数目
     */
    void DoWithDrawal(Account *acc, double amount);

    /**
     * 查询余额
     * @param 账户
     * @return 账户的余额
     */
    long double GetBalance(Account *acc);

    /**
     * 利息计算
     * @param 账户
     * @return 账户将来一年的利息
     */
    long double GetInterest(Account *acc);

    /**
     * 删除账户
     * @param 被删除的账户
     */
    void DoDelete(Account *acc);

    /**
     * 检测手机号是否合法
     */
    bool JudgeMobile(string mobile);

    /**
     * 检测身份证号是否合法
     */
    bool JudgeIDcard(string idcard);

private:
    /**
     * 账户数据访问对象
     */
    AccountDAO dao;
};


#endif //BANKWORK_ACCOUNTSERVICE_H
