#include<iostream>
#include<string>

using namespace std;

// 3.declare Printable class
class Printable {
// 4. implement print method (a pure virtual function)
public:
    virtual void print(ostream &os) const = 0;
    virtual ~Printable() {};
};

// Account
class Account: public Printable { // 5. Account inherited from Printable
private:
    double rate {0.1};
protected:
    string name;
public:
    // 6. Account needs to implement print method
    virtual void print(ostream &os) const override {os << "From Account, rate = " << rate;};
    Account(string na):name {na} {cout << "Account const : " << name << endl;}
    virtual ~Account(){cout << "Account distru : " << name << endl;}
};

// Check
class Check: public Account {
private:
    double rate {0.2};
public:
    // 7. if not implement its own, "From Account..." will be printed
    virtual void print(ostream &os) const override {os << "From Check, rate = " << rate;};
    Check(string na):Account {na} {cout << "Check const : " << name << endl;}
    virtual ~Check() {cout << "Check distru : " << name << endl;}
};

// 1. I want a function (overriding << operator) to print obj,
// this obj is an instance of some special classes. 
// We can create a abstract class Printable so that
// these special classes are inherited from Printable
ostream &operator<<(ostream &os, const Printable &obj){
    // 2. for each class inherited from Printable, I want different 
    // variables to be printed by this << operator, 
    // I can implement its own print method in each class
    obj.print(os);
    return os;
};

void function1(Account &obj){
    cout << obj << endl;    
};

void function2(Printable &obj){
    cout << obj << endl;    
};

// main 
int main() {
    
    cout << "=====Account=====" << endl;
    Account *a = new Account {"a"};
    cout << (*a) << endl;
    
    cout << "=====Check=====" << endl;
    Check *b = new Check {"b"}; 
    cout << (*b) << endl;

    cout << "=====poly=====" << endl;
    Account *c = new Check {"c"};
    cout << (*c) << endl;

    cout << "=====function1=====" << endl;
    function1(*a);
    function1(*b);
    function1(*c);
    
    cout << "=====function2=====" << endl;
    function2(*a);
    function2(*b);
    function2(*c);
    
    cout << "=====delete pointer=====" << endl;
    delete a;
    delete b;
    delete c;
    
    cout << "=====End=====" << endl;
    
    return 0;
}