#include "Account.h"

Account::Account(string identity, string password, string name, bool gender, string phone, string idcard,
                 long double balance) :
        identity(identity), password(password),
        name(name), gender(gender), phone(phone), idcard(idcard),
        balance(balance) {}

Account::Account(const Account &acc) :
        identity(acc.identity), password(acc.password),
        name(acc.name), address(acc.address), gender(acc.gender), phone(acc.phone), idcard(acc.idcard),
        balance(acc.balance), type(acc.type) {}

int Account::GetType() const {
    return -1;
}

bool Account::CanWithDrawal(double amount) const {
    return (balance - amount) >= 0;
}

string Account::GetID() {
    return identity;
}

bool Account::CheckPassword(string pw) {
    return password == pw;
}

long double Account::GetBalance() {
    return balance;
}

void Account::SetBalance(long double balance) {
    this->balance = balance;
}
