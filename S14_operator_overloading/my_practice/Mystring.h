#ifndef _MYSTRING_H_
#define _MYSTRING_H_
class Mystring {
    
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);
    
    // freind for non member oberloading function, we
    // need 2 parameters for binary operator
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    // 1 parameter for unary minus operator
    friend Mystring operator-(const Mystring &obj);
    // overload concatenation operator
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);

private:
    // pointer to a char[] that holds a c-style string
    char *str; 
public:
    Mystring(); // no-args constructor
    Mystring(const char *na); // overloaded constructor
    Mystring(const Mystring &source); // copy constructor
    ~Mystring();//destructor
    
    // overloading, member function
    Mystring &operator=(const Mystring &rhs); // copy assignment
    Mystring &operator=(Mystring &&rhs); // move assignment
    //Mystring operator-() const;// unary minus, return lower case by value
    //Mystring operator+(const Mystring &rhs) const;// concatenation
    //bool operator==(const Mystring &rhs) const; // overload equality operator
    
    void display() const;
    int get_length() const;
    const char *get_str() const;
};
#endif 