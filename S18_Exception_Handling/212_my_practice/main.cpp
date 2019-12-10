#include <iostream>
#include <string>
#include <memory>
using namespace std;

class IllegalNameException {
public:
    IllegalNameException(){cout << "In const of Ill... class" << endl;};
    ~IllegalNameException(){cout << "In destru of Ill... class" << endl;};
};

class IllegalNameException2: public exception {
public:
    IllegalNameException2() noexcept {cout << "In const of Ill...2 class" << endl;}; 
    ~IllegalNameException2() noexcept {cout << "In destru of Ill...2 class" << endl;};
    virtual const char *what() const noexcept {return "Illegal balance exception2 from what";};
};

class A {
private:
    string name;
public:
    A(string na)
    : name {na} {
        //if (name=="b") throw IllegalNameException();
        if (name=="b") throw IllegalNameException2();
        cout << "A const: " << name << endl;}
        
    ~A() {cout << "A dest: " << name << endl;}
};

int main() {
    try {
        cout << "do a:" << endl;
        unique_ptr<A> a = make_unique<A>("a");
        cout << "do b:" << endl;
        A b{"b"};
        cout << "do c:" << endl;
        A c{"c"};
    }
    catch (IllegalNameException &ex){
        cout << "IllegalNameException .." << endl;
    }
    catch (IllegalNameException2 &ex){
        cout << "IllegalNameException2 .." << endl;
        cout << "my what is: " << ex.what() << endl;
    }
    cout << "after catch block" << endl;
    return 0;
}