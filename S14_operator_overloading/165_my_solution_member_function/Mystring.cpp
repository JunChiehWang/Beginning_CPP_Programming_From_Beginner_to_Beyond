#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

// overloaded == operator
bool Mystring::operator==(const Mystring &rhs) {
    return (strcmp(str,rhs.str) == 0);
}; 

// overloaded != operator
bool Mystring::operator!=(const Mystring &rhs) {
    return (strcmp(str,rhs.str) != 0);
}; 

// overloaded > operator
bool Mystring::operator>(const Mystring &rhs) {
    return (strcmp(str,rhs.str) > 0);
}; 

// overloaded < operator
bool Mystring::operator<(const Mystring &rhs) {
    return (strcmp(str,rhs.str) < 0);
}; 

// overloaded - operator
Mystring Mystring::operator-() {
    size_t size {strlen(str)+1};
    char *buff = new char[size];
    for (size_t i {0}; i < size; i++) {
        buff[i] = tolower(str[i]);
    };
    Mystring temp {buff};
    delete [] buff;
    return temp;
};
// overloaded + operator
Mystring Mystring::operator+(const Mystring &rhs){
    size_t size {strlen(str) + strlen(rhs.str) + 1};
    char *buff = new char[size];
    strcpy(buff,str);
    strcat(buff,rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;    
};
// overloaded += operator
Mystring &Mystring::operator+=(const Mystring &rhs){
    /*
    size_t size {strlen(str) + strlen(rhs.str) + 1};
    char *buff = new char[size];
    strcpy(buff,str);
    strcat(buff,rhs.str);
    strcpy(str,buff);
    delete [] buff;*/
    *this = *this + rhs;
    return *this;    
};
// overloaded * operator
Mystring Mystring::operator*(const int &mulp){
    size_t size {strlen(str)*mulp + 1};
    char *buff = new char[size];
    strcpy(buff,str);
    for (size_t i {0}; i < mulp-1; i++) {
        strcat(buff,str);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;    
};
// overloaded *= operator
Mystring &Mystring::operator*=(const int &mulp) {
    *this = *this * mulp;
    return *this;
};
// overloaded pre-increment ++ operator
Mystring &Mystring::operator++() {
    size_t size {strlen(str)+1};
    char *buff = new char[size];
    for (size_t i {0}; i < size; i++) {
        buff[i] = toupper(str[i]);
    };
    strcpy(str,buff);
    delete [] buff;
    return *this;    
};
// overloaded post-increment ++ operator
Mystring Mystring::operator++(int) {
    Mystring temp {*this};
    operator++();
    return temp;
};
