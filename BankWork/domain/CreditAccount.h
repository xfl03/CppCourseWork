#ifndef BANKWORK_CREDITACCOUNT_H
#define BANKWORK_CREDITACCOUNT_H

#include "Account.h"

/**
 * 信用卡账户类
 */
class CreditAccount : public Account {
public:
    explicit CreditAccount(const Account &acc) : Account(acc) {}

    int GetType() const override {
        return 2;
    }

    bool CanWithDrawal(double amount) const override {
        return (balance - amount) >= -CREDIT_LIMIT;//判断是否在信用额度以内
    }
};

#endif //BANKWORK_CREDITACCOUNT_H
