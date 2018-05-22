#ifndef BANKWORK_ACCOUNTCONTROLLER_H
#define BANKWORK_ACCOUNTCONTROLLER_H

#include <sstream>
#include "../service/AccountService.h"
#include "../domain/Account.h"
#include "../domain/BasicResponce.h"

/**
 * 账户控制器类
 * 对于账户的操作止于此
 * 负责调动Service来操作账户，并给上层回应
 * @note 请保持单例
 */
class AccountController {
public:
    /**
     * 检查ID能否使用
     * @param ID
     */
    BasicResponce CheckID(string);

    /**
     * 注册账户
     * @param 账户信息
     * @return
     */
    BasicResponce Register(Account &acc);

    /**
     * 登录
     * @param ID
     * @param 密码
     */
    BasicResponce Login(string id, string password);

    /**
     * 存款
     * @param 存款数量
     */
    BasicResponce Deposit(double amount);

    /**
     * 取款
     * @param 取款数量
     */
    BasicResponce WithDrawal(double amount);

    /**
     * 查询账户余额
     */
    BasicResponce Balance();

    /**
     * 查询年利息
     */
    BasicResponce Interest();

    /**
     * 撤销账户
     */
    BasicResponce Delete();

    /**
     * 退出账户
     */
    BasicResponce Logout();

    /**
     * 判断手机号是否合法
     */
    BasicResponce JudgeMobile(string mobile);

    /**
     * 判断身份证号是否合法
     */
    BasicResponce JudgeIDcard(string idcard);

    /**
     * 获得控制器实例（饿汉式单例模式）
     */
    static AccountController *GetInstance();

    AccountController() {}

private:
    /**
     * 账户服务实例
     */
    AccountService service;
    /**
     * 当前登录的账户
     */
    Account *account = nullptr;
    /**
     * 控制器实例
     */
    static AccountController *instance;
};
#endif //BANKWORK_ACCOUNTCONTROLLER_H
