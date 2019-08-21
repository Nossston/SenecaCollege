//
//  ChequingAccount.h
//  w8_inl_ab
//
//  Created by Noston Liu on 2019/7/18.
//  Copyright © 2019 Noston. All rights reserved.
//

///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/18    w8_at_home
///////////////////////////////////////////////////////////

#ifndef ChequingAccount_h
#define ChequingAccount_h

#include <iostream>
#include "Account.h"

namespace sict {
    class ChequingAccount: public Account{
        double accountTransfee;
        double accountMonthfee;
    public:
        ChequingAccount(double, double, double);
        bool credit(double) ;
        bool debit(double);
        void monthEnd();
        void display(std::ostream&) const;
    };
}

#endif /* ChequingAccount_h */
