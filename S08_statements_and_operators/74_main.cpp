// Section 8 Challenge
/*
	For this program I will be using US dollars and cents.
	
    Write a program that asks the user to enter the following:
	An integer representing the number of cents 
    	
	You may assume that the number of cents entered is greater than or equal to zero
    
	The program should then display how to provide that change to the user.
	
	In the US:
		1 dollar is 100 cents
		1 quarter is 25 cents
		1 dime is 10 cents
		1 nickel is 5 cents, and
		1 penny is 1 cent.
		
	Here is a sample run:
	
	Enter an amount in cents :  92
	
	You can provide this change as follows:
	dollars    : 0
	quarters : 3
	dimes     : 1
	nickels   : 1
	pennies  : 2
	
	Feel free to use your own currency system.
	Also, think of how you might solve the problem using the modulo operator.

	Have fun and test your program!!

*/
#include <iostream>

using namespace std;

int main() {

    unsigned long long int cents {0};
    unsigned long long int dollar {0};
    unsigned long long int quarter {0};
    unsigned long long int dime {0};
    unsigned long long int nickel {0};
    unsigned long long int penny {0};

    cout << "An integer representing the number of cents" << endl;
    cin >> cents;
    cout << "You input " << cents << endl;
    
    dollar  = cents/100.0;
    cents = cents%100;
    cout << "dollar " << dollar << " cents " << cents << endl;

    quarter  = cents/25.0;
    cents = cents%25;
    cout << "quarter " << quarter << " cents " << cents << endl;

    dime  = cents/10.0;
    cents = cents%10;
    cout << "dime " << dime << " cents " << cents << endl;

    nickel  = cents/5.0;
    cents = cents%5;
    cout << "nickels " << nickel << " cents " << cents << endl;

    penny  = cents/1.0;
    cents = cents%1;
    cout << "penny " << penny << " cents " << cents << endl;

    return 0;
}


