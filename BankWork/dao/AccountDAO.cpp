/**
 * @file
 * 文档见 dao/AccountDAO.h
 */
#include <vector>
#include "AccountDAO.h"
#include "../domain/DebitAccount.h"
#include "../domain/CreditAccount.h"

void AccountDAO::InsertAccount(Account &acc) {
    data.GetAccounts()->push_back(acc);
    data.Write();
}

Account *AccountDAO::SelectAccountByID(string id) {
    //遍历账户进行查找
    vector<Account> *ve = data.GetAccounts();
    for (Account &acc:*ve)
        if (acc.GetID() == id)
            return &acc;
    return nullptr;//未找到则放回NULL
}

void AccountDAO::DeleteAccount(Account &acc) {
    //遍历查找，找到后删除
    vector<Account> *as = data.GetAccounts();
    for (auto i = as->begin(); i < as->end(); i++) {
        if (i->GetID() == acc.GetID()) {
            as->erase(i);
            data.Write();
            break;
        }
    }
}

void AccountDAO::UpdateAccount(Account *acc) {
    //遍历查找，找到后更改
    std::vector<Account> *as = data.GetAccounts();
    for (auto i = as->begin(); i < as->end(); i++) {
        if (i->GetID() == acc->GetID()) {
            i->SetBalance(acc->GetBalance());
            data.Write();
            break;
        }
    }
}
