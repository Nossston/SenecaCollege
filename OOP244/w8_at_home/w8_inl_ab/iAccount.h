
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/18    w8_at_home
///////////////////////////////////////////////////////////

#ifndef iAccount_h
#define iAccount_h

#include <iostream>

namespace sict {
    class iAccount{
        
public:
        virtual bool credit(double) = 0;
        virtual bool debit(double) = 0;
        virtual void monthEnd() = 0;
        virtual void display(std::ostream&) const = 0;
        virtual ~iAccount() {}; // = default
    };
    iAccount* CreateAccount(const char*, double);
    
}

#endif /* iAccount_h */
