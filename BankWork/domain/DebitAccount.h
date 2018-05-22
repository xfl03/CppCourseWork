#ifndef BANKWORK_DEBITACCOUNT_H
#define BANKWORK_DEBITACCOUNT_H

#include "Account.h"

/**
 * 储蓄账户类
 */
class DebitAccount : public Account {
public:
    DebitAccount(const Account &acc) : Account(acc) {}

    int GetType() const override {
        return 1;
    }
};

#endif //BANKWORK_DEBITACCOUNT_H
