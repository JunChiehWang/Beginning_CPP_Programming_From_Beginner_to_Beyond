#include <iostream>
#include "Mystring.h"
using namespace std;

int main() {
    //Mystring a {"Hello"}; // overloaded constructor
    //Mystring b; // no-args constructor
    //Mystring stooge {larry}; // copy constructor
    //b=a; // assign a to b; copy assignment b.operator=(a)
    //b="This is a test"; //b.operator=("This is a test");
    
    //empty.display();
    //larry.display();
    //stooge.display();
    
    //Mystring a{"Hello"}; // overloaded constructor
    //a = Mystring{"Hola"}; // overloaded constructor then move assignment
    //a = "Bonjour"; // Overloaded constructor then move assignment
    
    /*
    Mystring larry{"Larry"};
    Mystring moe{"Moe"};
    Mystring stooge = larry;
    larry.display();
    moe.display();
    cout << boolalpha << endl;
    cout << (larry == moe) << endl; // overload equality operator
    cout << (larry == stooge) << endl;
    larry.display();
    Mystring larry2 = -larry; // negation operator
    larry2.display();
    Mystring stooges = larry + "Moe"; // concatenation operator
    stooges.display();
    */
    
    /*
    Mystring larry{"Larry"};
    larry.display();
    cout << boolalpha << endl;
    Mystring moe{"Moe"};
    Mystring stooge = larry;
    moe.display();
    cout << (larry == moe) << endl; // overload equality operator
    cout << (larry == stooge) << endl;
    larry.display();
    Mystring larry2 = -larry; // negation operator
    larry2.display();
    Mystring stooges = larry + "Moe"; // concatenation operator
    stooges.display();
    */
    
    Mystring larry {"Larry"};
    Mystring moe {"Moe"};
    Mystring curly;
    cout << "Enter the third stooge's first name:";
    cin >> curly;
    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl; 
    cout << "\nEnter the three stooges names sperated by a space:";
    cin >> larry >> moe >> curly;
    cout << "The three stooges are:" << larry << ", " << moe << ", and " << curly << endl;
    
    return 0;
}