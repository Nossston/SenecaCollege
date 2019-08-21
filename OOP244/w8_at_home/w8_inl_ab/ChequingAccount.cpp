//
//  ChequingAccount.c
//
//  Created by Noston Liu on 2019/7/18.
//  Copyright © 2019 Noston. All rights reserved.
//
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/18    w8_at_home
///////////////////////////////////////////////////////////

#include "ChequingAccount.h"

namespace sict  {
    ChequingAccount::ChequingAccount(double money, double transfee, double monthfee): Account::Account(money){
        accountTransfee = ( transfee > 0 ) ? transfee : 0.0;
        accountMonthfee =  ( monthfee > 0 ) ? monthfee : 0.0;
    };
    bool ChequingAccount::credit(double money){
        if ( money > 0 ){
            Account::credit(money);
            Account::debit(accountTransfee);
            return true;
        }
        else
            return false;
    };
    bool ChequingAccount::debit(double money){
        if ( money > 0 ){
            Account::debit(money);
            Account::debit(accountTransfee);
            return true;
        }
        else
            return false;
    };
    void ChequingAccount::monthEnd(){
        Account::debit(accountMonthfee);
    };
    void ChequingAccount::display(std::ostream& os) const {
        os << "Account type: Chequing" << std::endl;
        os.setf(os.fixed, os.floatfield);
        os.precision(2);
        os << "Balance: $" << Account::balance() << std::endl;
        os << "Per Transaction Fee: " << accountTransfee << std::endl;
        os << "Monthly Fee: " << accountMonthfee  << std::endl;
        
    };

}
