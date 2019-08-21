//
//  iAccount.c
//
//  Created by Noston Liu on 2019/7/17.
//  Copyright © 2019 Noston. All rights reserved.
//
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/18    w8_at_home
///////////////////////////////////////////////////////////

#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {
    const double interest = 0.05 ;
    const double transfee = 0.50;
    const double monthfee = 2.00;
    
    iAccount* CreateAccount (const char* type, double vaule){
        iAccount* temp = nullptr;
        if (type[0] == 'S') {
            temp = new SavingsAccount( interest, vaule);
        }
        if (type[0] == 'C') {
            temp = new ChequingAccount (vaule, transfee, monthfee );
        }
        return temp;
    };
}


