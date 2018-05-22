#ifndef BANKWORK_ACCOUNT_H
#define BANKWORK_ACCOUNT_H

#include <string>

using namespace std;

/**
 * 个人账户类
 */
class Account {
    friend class RegView;

    friend class AccountDataSource;

public:
    /**
     * 默认构造函数作为备用
     */
    Account() {}

    /**
     * 创建个人账户对象
     */
    Account(string identity, string password,
            string name, bool gender, string phone, string idcard,
            long double balance = 0);

    /**
     * 克隆个人账户对象
     * @param 被克隆的对象
     */
    Account(const Account &acc);

    /**
     * 获得账户类型
     * @return 账户类型 1-储蓄 2-信用
     */
    virtual int GetType() const;

    /**
     * 判断账户能否取款
     * @param 取款数目
     */
    virtual bool CanWithDrawal(double amount) const;

    /**
     * 获得账号
     * @return 账户的账号
     */
    string GetID();

    /**
     * 检查密码是否与当前账户密码一致
     * @param 被检查的密码
     * @return 是否一致
     */
    bool CheckPassword(string pw);

    /**
     * 获得余额
     * @return 账户余额
     */
    long double GetBalance();

    /**
     * 设置余额
     * @param 新的余额
     */
    void SetBalance(long double balance);

protected:
    /**
     * 银行卡号
     * @example 6200 0000 0000 0000
     */
    string identity;
    /**
     * 账户密码的hash
     * @note 非明文密码
     */
    string password;
    /**
     * 用户姓名
     * @example 张三
     */
    string name;
    /**
     * 用户性别
     * @note true - 男性
     */
    bool gender;
    /**
     * 用户地址
     */
    string address;
    /**
     * 用户手机
     */
    string phone;
    /**
     * 用户身份证
     */
    string idcard;
    /**
     * 账户余额
     */
    long double balance;
    /**
     * 账户类型
     * 1-储蓄 2-信用
     */
    int type = -2;
};

#endif //BANKWORK_ACCOUNT_H
