#include "Trust_Account.h"

// if int_rate is inherited, not declared in Trust_Account:
Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate} { 
}

// if int_rate is declared in Trust_Account too:
//Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
//    : Savings_Account {name, balance}, int_rate {int_rate} { 
//}

bool Trust_Account::deposit(double amount) {
    if (amount >= def_bonus_threshold) 
        amount = amount + def_bonus;
    amount += amount * (int_rate/100);
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    //std::cout << "withdraw_count:" << withdraw_count << ",withdraw_limit:" << withdraw_limit << std::endl; 
    //std::cout << "amount:" << amount << ",balance*withdraw_amount_limit_percent:" << balance*withdraw_amount_limit_percent << std::endl; 

    if (withdraw_count >= withdraw_limit) {
        std::cout << "withdraw_count = " << withdraw_count << " > withdraw_limit = " << withdraw_limit << std::endl;
        return false;
    }
    if (amount > balance*withdraw_amount_limit_percent) {
        std::cout << "amount = " << amount << " > balance*withdraw_amount_limit_percent = " << balance*withdraw_amount_limit_percent << std::endl;
        return false;        
    }
    withdraw_count = withdraw_count + 1;
    return Savings_Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

