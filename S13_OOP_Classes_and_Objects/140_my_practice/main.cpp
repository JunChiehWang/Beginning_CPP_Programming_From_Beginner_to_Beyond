#include<iostream>
#include<string>
#include"Account.h"

int main() {
    Account frank_account;
    frank_account.set_name("Frank's name");
    frank_account.set_balance(1000.0);
    
    if (frank_account.deposit(200.0)) {
        std::cout << "deposit ok" << std::endl;
    } else {
        std::cout << "deposit not allowed" << std::endl;
    }
    
    if (frank_account.withdraw(500.0)) {
        std::cout << "withdraw ok" << std::endl;
    } else {
        std::cout << "not sufficient funds" << std::endl;
    }

    if (frank_account.withdraw(1500.0)) {
        std::cout << "withdraw ok" << std::endl;
    } else {
        std::cout << "not sufficient funds" << std::endl;
    }
    
    return 0;
}


