#include <iostream>
#include <string>
#include <memory>
using namespace std;

class IllegalNameException {
public:
    IllegalNameException(){cout << "In const of Ill... class" << endl;};
    ~IllegalNameException(){cout << "In destru of Ill... class" << endl;};
};

class A {
private:
    string name;
public:
    A(string na)
    : name {na} {
        if (name=="b") throw IllegalNameException();
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
    cout << "after catch block" << endl;
    return 0;
}