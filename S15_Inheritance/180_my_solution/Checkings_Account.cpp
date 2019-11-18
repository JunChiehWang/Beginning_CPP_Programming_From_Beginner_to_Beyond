#include "Checkings_Account.h"

Checkings_Account::Checkings_Account(std::string name, double balance)
    : Account {name, balance} {
}

bool Checkings_Account::withdraw(double amount) {
    amount = amount + 1.5;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checkings_Account &account) {
    os << "[Checkings_Account: " << account.name << ": " << account.balance << " ]";
    return os;
}

