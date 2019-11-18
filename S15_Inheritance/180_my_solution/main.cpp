// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checkings_Account.h"
#include "Trust_Account.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
    cout << "==================== Accounts begins ====================" << endl;
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 
    cout << "==================== Savings begins ====================" << endl;
    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
    
    // Checking
    cout << "==================== Checking begins ====================" << endl;
    vector<Checkings_Account> check_accounts;
    check_accounts.push_back(Checkings_Account {} );
    check_accounts.push_back(Checkings_Account {"Superman"} );
    check_accounts.push_back(Checkings_Account {"Batman", 2000} );
    check_accounts.push_back(Checkings_Account {"Wonderwoman", 5000} );

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust 
    cout << "==================== Trust begins ====================" << endl;
    vector<Trust_Account> Trust_accounts;
    Trust_accounts.push_back(Trust_Account {} );
    Trust_accounts.push_back(Trust_Account {"Superman"} );
    Trust_accounts.push_back(Trust_Account {"Batman", 2000} );
    Trust_accounts.push_back(Trust_Account {"Wonderwoman", 5000, 2.0} );
    display(Trust_accounts);
    deposit(Trust_accounts, 1000);
    //deposit(Trust_accounts, 5000);
    withdraw(Trust_accounts, 100);
    withdraw(Trust_accounts, 200);
    withdraw(Trust_accounts, 300);
    withdraw(Trust_accounts, 400);
    withdraw(Trust_accounts, 500);
    withdraw(Trust_accounts, 10);
    withdraw(Trust_accounts, 10);
    withdraw(Trust_accounts, 10);
    
    return 0;
}

