//
//  SavingsAccount.h
//  w8_inl_ab
//
//  Created by Noston Liu on 2019/7/17.
//  Copyright © 2019 Noston. All rights reserved.
//

///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/18    w8_at_home
///////////////////////////////////////////////////////////
#ifndef SavingsAccount_h
#define SavingsAccount_h

#include <iostream>
#include "Account.h"

namespace sict{
    
    class SavingsAccount: public Account{
        double accountinterest;
    public:
        SavingsAccount(double, double);
        void monthEnd();
        void display(std::ostream&)const;
    };
    //class ChequingAccount: public Account{};

}
#endif /* SavingsAccount_h */
