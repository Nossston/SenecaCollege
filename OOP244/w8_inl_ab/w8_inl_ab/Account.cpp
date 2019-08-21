//
//  Account.c
//  w8_inl_ab
//
//  Created by Noston Liu on 2019/7/17.
//  Copyright © 2019 Noston. All rights reserved.
//

///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/18    w8_in_lab
///////////////////////////////////////////////////////////
#include "Account.h"

namespace sict {
    double Account::balance() const{
        return accountbalance;
        };
    Account::Account(double money){
        accountbalance = (money <= 0) ? 0.0 : money;
    };
    bool Account::credit(double money){
            
        if (money < 0) {
            return false;
        }
        else{
            accountbalance += money;
            return true;
        }
    };
    bool Account::debit(double money){
        
        if (money < 0) {
            return false;
        }
        else{
            accountbalance -= money;
            return true;
        }
        
        
    };
}

