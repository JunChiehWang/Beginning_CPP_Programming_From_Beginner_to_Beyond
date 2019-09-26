#include <iostream>
#include <string>

// main returns integer
int main() 
{
    int favorite_number;
    std::string mystring;

    mystring =  "Enter your favorite number between 1 and 100:";

    std::cout << mystring;

    std::cin >> favorite_number;

    mystring = "Amazing! That's my favorite number too!\n";

    std::cout << mystring;

    mystring = "No really. " + std::to_string(favorite_number);
    mystring = mystring + " is my favorite number.";

    std::cout << mystring << std::endl;

// return 0 if everything is good
    return 0;

}
