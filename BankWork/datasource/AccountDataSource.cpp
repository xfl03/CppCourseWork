/**
 * @file
 * 文档见 datasource/AccountDataSource.h
 */
#include <vector>
#include "AccountDataSource.h"
#include "../Constant.h"
#include "../io/FileIO.h"
#include "../domain/Account.h"
#include "../domain/DebitAccount.h"
#include "../domain/CreditAccount.h"

using namespace std;

void AccountDataSource::Read() {
    Account temp;
    int type;
    file.SetDoInput(true);
    ifstream &is = file.GetInputStream();
    if (!is.is_open())//文件打开失败
        return;
    while (is >> temp.identity) {
        is >> temp.password;
        is >> temp.name >> temp.gender >> temp.address >> temp.phone >> temp.idcard;
        is >> temp.balance >> temp.type;
        switch (temp.type) {
            case 1: {//储蓄账户
                DebitAccount deb_acc(temp);
                accounts->push_back(deb_acc);
            }
                break;
            case 2: {//信用卡账户
                CreditAccount cre_acc(temp);
                accounts->push_back(cre_acc);
            }
                break;
            default:
                break;
        }
    }
    file.SetDoInput(false);
}

void AccountDataSource::Write() {
    file.SetDoOutput(true);
    ofstream &out = file.GetOutputStream();
    for (Account &temp:*accounts) {
        out << temp.identity << " "
            << temp.password << " "
            << temp.name << " "
            << (temp.gender ? 1 : 0) << " "
            << temp.address << " "
            << temp.phone << " "
            << temp.idcard << " "
            << temp.balance << " "
            << temp.type << endl;
    }
    file.SetDoOutput(false);
}

vector<Account> *AccountDataSource::GetAccounts() {
    return accounts;
}

AccountDataSource::AccountDataSource() : file(ACCOUNTS_FILE_PATH) {
    accounts = new vector<Account>();
    Read();
}
