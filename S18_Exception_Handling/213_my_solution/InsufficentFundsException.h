#ifndef __INSUFFICIENT_FUNDS_EXCEPTION_H__
#define __INSUFFICIENT_FUNDS_EXCEPTION_H__

class InsuifficientFundsException: public std::exception 
{
public:
    InsuifficientFundsException() {}
    ~InsuifficientFundsException() {}
    virtual const char* what() const noexcept{return "from class InsuifficientFundsException";}
};

#endif // __INSUFFICIENT_FUNDS_EXCEPTION_H__
