//
//  Account.h
//
//  Created by Noston Liu on 2019/7/17.
//  Copyright © 2019 Noston. All rights reserved.
//
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/18    w8_at_home
///////////////////////////////////////////////////////////

#ifndef Account_h
#define Account_h

#include <iostream>
#include "iAccount.h"

namespace sict {
    class Account: public iAccount {
        double accountbalance;
    protected:
        double balance() const;
    public:
        Account(double);
        bool credit(double);
        bool debit(double);
       
    };
}

#endif /* Account_h */
