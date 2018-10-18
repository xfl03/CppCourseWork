/**
 * @file
 * 文档见service/AccountService.h
 */
#include "AccountService.h"

bool AccountService::CheckAccountExist(string id) {
    return dao.SelectAccountByID(id) != nullptr;
}

Account *AccountService::DoRegister(Account &acc) {
    dao.InsertAccount(acc);//插入账户
    return &acc;
}

Account *AccountService::DoLogin(string id, string pass) {
    Account *acc = dao.SelectAccountByID(id);
    if (acc == nullptr)//如果账号不存在
        return nullptr;
    if (!acc->CheckPassword(pass))//如果密码错误
        return nullptr;
    return acc;
}

void AccountService::DoDeposit(Account *acc, double amount) {
    acc->SetBalance(acc->GetBalance() + amount);
    dao.UpdateAccount(acc);
}

bool AccountService::CheckWithDrawal(Account *acc, double amount) {
    return acc->CanWithDrawal(amount);
}

void AccountService::DoWithDrawal(Account *acc, double amount) {
    acc->SetBalance(acc->GetBalance() - amount);
    dao.UpdateAccount(acc);
}

long double AccountService::GetBalance(Account *acc) {
    return acc->GetBalance();
}

long double AccountService::GetInterest(Account *acc) {
    return acc->GetBalance() <= 0 ? 0 : acc->GetBalance() * INTEREST_RATE;
}

void AccountService::DoDelete(Account *acc) {
    dao.DeleteAccount(*acc);
}

bool AccountService::JudgeMobile(string mobile) {
    if (mobile.size() != 11)//11位
        return false;

    if (mobile[0] != '1')//要求以1开头
        return false;
    for (int i = 1; i < 11; i++) {
        if (mobile[i] < '0' || mobile[i] > '9')//是否全为数字
            return false;
    }
    return true;
}

bool AccountService::JudgeIDcard(string idcard) {
    if (idcard.size() != 18)//是否为18位
        return false;

    for (int i = 0; i < 17; i++) {
        if (idcard[i] < '0' || idcard[i] > '9')//是否前17位为数字
            return false;
    }

    if (idcard[17] == 'x')
        idcard[17] = 'X';//自动转换成大写
    if ((idcard[17] < '0' || idcard[17] > '9') &&
        idcard[17] != 'X')//第17位是否为数字或者X
        return false;

    int checknum = idcard[17] == 'X' ? 10 : idcard[17] - '0';//输入身份证的校验码
    checknum = (12 - checknum) % 11;
    int calchecknum = 0;//计算出的校验码
    int plex[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    for (int i = 0; i < 17; i++)
        calchecknum += (idcard[i] - '0') * plex[i];//根据规则计算校验码
    calchecknum %= 11;
    return checknum == calchecknum;//校验码是否正确
}

