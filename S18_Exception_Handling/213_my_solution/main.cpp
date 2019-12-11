#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    // test your code here
    
    try {
    shared_ptr<Account> a = make_shared<Checking_Account>("check_jerry", 1000);
    cout << *a << endl;
    a->withdraw(1500);
    cout << *a << endl;
    }
    catch (IllegalBalanceException &ex) {
        cout << "catch IllegalBalanceException" << endl;
        cout << ex.what() << endl;
    }
    catch (InsuifficientFundsException &ex) {
        cout << "catch InsuifficientFundsException" << endl;
        cout << ex.what() << endl;
    }    
    
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

