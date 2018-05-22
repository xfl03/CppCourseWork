/**
 * @file
 * 文档见 controller/AccountController.h
 */
#include "AccountController.h"

AccountController *AccountController::instance = new AccountController();

BasicResponce AccountController::CheckID(string id) {
    if (service.CheckAccountExist(id)) {
        return BasicResponce(-1, "ID已被注册！");
    } else {
        return BasicResponce(0, "ID可以使用！");
    }
}

BasicResponce AccountController::Register(Account &acc) {
    if (service.CheckAccountExist(acc.GetID()))//再次检查ID
        return BasicResponce(-1, "ID已被注册！");
    service.DoRegister(acc);
    account = &acc;//自动登录
    return BasicResponce(0, "注册成功！");
}

BasicResponce AccountController::Login(string id, string password) {
    Account *acc = service.DoLogin(id, password);
    if (acc == nullptr)
        return BasicResponce(-1, "ID或密码错误！");
    account = acc;//记住登录状态
    return BasicResponce(0, "登录成功！");
}

BasicResponce AccountController::Deposit(double amount) {
    if (amount <= 0)
        return BasicResponce(-1, "无效的金额！");
    service.DoDeposit(account, amount);
    return BasicResponce(0, "存款成功！");
}

BasicResponce AccountController::WithDrawal(double amount) {
    if (amount <= 0)
        return BasicResponce(-1, "无效的金额！");
    if (!service.CheckWithDrawal(account, amount))//检查余额
        return BasicResponce(-1, "余额不足！");
    service.DoWithDrawal(account, amount);//扣款
    return BasicResponce(0, "取款成功！");
}

BasicResponce AccountController::Balance() {
    char buffer[32];
    ostringstream oss(buffer);
    oss << "余额为：" << service.GetBalance(account);
    return BasicResponce(0, oss.str());
}

BasicResponce AccountController::Interest() {
    char buffer[32];
    ostringstream oss(buffer);
    oss << "年利息为：" << service.GetInterest(account);
    return BasicResponce(0, oss.str());
}

BasicResponce AccountController::Delete() {
    service.DoDelete(account);
    account = nullptr;
    return BasicResponce(0, "撤销成功！");
}

BasicResponce AccountController::Logout() {
    account = nullptr;
    return BasicResponce(0, "退出成功！");
}

AccountController *AccountController::GetInstance() {
    return instance;
}

BasicResponce AccountController::JudgeMobile(string mobile) {
    if (service.JudgeMobile(mobile))
        return BasicResponce(0, "合法的手机号");
    else
        return BasicResponce(-1, "手机号格式错误");
}

BasicResponce AccountController::JudgeIDcard(string idcard) {
    if (service.JudgeIDcard(idcard))
        return BasicResponce(0, "合法的身份证号");
    else
        return BasicResponce(-1, "无效的身份证号");
}
