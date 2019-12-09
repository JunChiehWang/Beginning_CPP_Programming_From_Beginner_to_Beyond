#include <iostream>
#include <string>

using namespace std;
class A {
private:
    string name;
public:
    A(string na): name {na} {cout << "A const: " << name << endl;}
    ~A() {cout << "A dest: " << name << endl;}
};

int main() {
    try {
        A a{"a"};
        throw 0;
        A b{"b"};
        A c{"c"};
        cout << "in try block" << endl; 
    }
    catch (int &ex) {
        cout << "a cannot be created" << endl;  
    }
    cout << "after catch block" << endl;
    return 0;
}