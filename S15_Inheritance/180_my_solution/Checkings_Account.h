#ifndef _CHECKINGS_ACCOUNT_H_
#define _CHECKINGS_ACCOUNT_H_
#include "Account.h"

class Checkings_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checkings_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Checkings Account";
    static constexpr double def_balance = 0.0;
public:
    Checkings_Account(std::string name = def_name, double balance = def_balance);    
    bool withdraw(double amount);
    // Inherits the Account::deposit methods
};

#endif // _SAVINGS_ACCOUNT_H_