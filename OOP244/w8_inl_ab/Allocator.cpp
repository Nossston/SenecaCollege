//
//  iAccount.c
//  w8_inl_ab
//
//  Created by Noston Liu on 2019/7/17.
//  Copyright © 2019 Noston. All rights reserved.
//
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/18    w8_in_lab
///////////////////////////////////////////////////////////

#include "SavingsAccount.h"

namespace sict {
    const double interest = 0.05 ;
    
    iAccount* CreateAccount (const char* type, double vaule){
        iAccount* temp = nullptr;
        if (type[0] == 'S') {
            temp = new SavingsAccount( interest, vaule);
            
        }
        return temp;
    };
}


