#include <iostream>
#include <cstring>
#include "Mystring.h"

// no-args constructor
Mystring::Mystring()
:str {nullptr}{
    std::cout << "no-arg constructor" << std::endl;
    str = new char[1]; // on heap
    *str = '\0';
};
// overloaded constructor
Mystring::Mystring(const char *s)
:str {nullptr} {
    std::cout << "overloaded constructor" << std::endl;
    if (s==nullptr) { // check if user gives a nullptr
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(s)+1];
        std::strcpy(str, s);
    }
};
// copy constructor
Mystring::Mystring(const Mystring &source)
:str {nullptr}{
    std::cout << "copy constructor" << std::endl;
    str = new char[std::strlen(source.str)+1];
    std::strcpy(str, source.str);// deep copy
};
//destructor
Mystring::~Mystring(){
    std::cout << "destructor" << std::endl;
    delete [] str;  
};
//display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
};
// length getter
int Mystring::get_length() const {
    return std::strlen(str);
};
// string getter
const char *Mystring::get_str() const {
    return str;    
};
// copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) 

{
    std::cout << "copy assignment" << std::endl;
    if (this == &rhs) {return *this;} 
    delete [] this->str; // or delete [] str;
    str = new char [std::strlen(rhs.str)+1];
    std::strcpy(this->str,rhs.str);
    return *this;
};

// move assignment
Mystring &Mystring::operator=(Mystring &&rhs) 
{
    std::cout << "move assignment" << std::endl;
    if (this == &rhs) {return *this;} 
    delete [] this->str; // or delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
};
/*
// unary minus, return lower case by value
Mystring Mystring::operator-() const {
    std::cout << "unary minus" << std::endl;
    //tmp = new char[std::strlen(str)+1];
    char *buff=new char[std::strlen(str)+1];
    std::strcpy(buff,str);
    for (size_t i {0}; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);    
    };
    Mystring tmp_obj {buff};
    delete [] buff;
    return tmp_obj;
};
// concatenation
Mystring Mystring::operator+(const Mystring &rhs) const{
    std::cout << "concatenation" << std::endl;
    char *buff=new char[std::strlen(str) 
                      + std::strlen(rhs.str) + 1];
    std::strcpy(buff,str);
    std::strcat(buff,rhs.str);
    Mystring tmp_obj {buff};
    delete [] buff;
    return tmp_obj;
};
// overload equality operator
bool Mystring::operator==(const Mystring &rhs) const {
    std::cout << "equality operator" << std::endl; 
    return (std::strcmp(str, rhs.str)==0);
};
*/

// freind for non member overloading function, we
// need 2 parameters for binary operator
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str,rhs.str)==0);
};

// 1 parameter for unary minus operator
Mystring operator-(const Mystring &obj) {
    std::cout << "non-member unary minus op" << std::endl;
    size_t size {std::strlen(obj.str)+1}; // dont forget +1
    char *buff = new char[size];
    for (size_t i{0}; i < size; i++) {
        buff[i] = std::tolower(obj.str[i]);
    };
    Mystring tmp {buff};
    delete [] buff; // dont forget !!
    return tmp;
};
    
// overload concatenation operator
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    std::cout << "non-member concatenation op" << std::endl;
    size_t size {std::strlen(lhs.str)+std::strlen(rhs.str)+1}; 
    char *buff = new char[size];
    std::strcpy(buff,lhs.str);
    std::strcat(buff,rhs.str);
    Mystring tmp {buff};
    delete [] buff;
    return tmp;    
};

// overload insertation operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs){
    os << rhs.str;
    return os;
};
// overload extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    //rhs.str = std::strcat(buff,rhs.str);
    //buff = strcat(buff, rhs.str);
    buff = strcat(buff, " ");
    buff = strcat(buff, rhs.str);
    rhs = Mystring {buff};
    delete [] buff;
    return in;
    
};
    