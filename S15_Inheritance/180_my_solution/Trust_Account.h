#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double def_bonus = 50.0;
    static constexpr double def_bonus_threshold = 5000.0;
    static constexpr size_t withdraw_limit = 3;
    static constexpr double withdraw_amount_limit_percent = 0.2;
//protected:
    //double int_rate; // dont need int_rate again beause we inherit it from Savings_Account
    //double int_rate;  // if we declare int_rate again here
    size_t withdraw_count {0};
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);    
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // _TRUST_ACCOUNT_H_


