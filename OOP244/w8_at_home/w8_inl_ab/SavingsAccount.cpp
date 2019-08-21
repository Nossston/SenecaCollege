//
//  SavingsAccount.c
//
//  Created by Noston Liu on 2019/7/17.
//  Copyright © 2019 Noston. All rights reserved.
//

///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/18    w8_at_home
///////////////////////////////////////////////////////////
#include <iomanip>
#include "SavingsAccount.h"

namespace sict{
    
    SavingsAccount::SavingsAccount(double interest, double money): Account::Account(money) {
        accountinterest = (interest > 0) ? interest: 0.0 ;
    };
    void SavingsAccount::monthEnd(){
        Account::credit( Account::balance() * accountinterest);
    };
    void SavingsAccount::display(std::ostream& os)const{
        
        os << "Account type: Savings" << std::endl;
        os.setf(os.fixed, os.floatfield);
        os.precision(2);
        os << "Balance: $" << Account::balance() << std::endl;
        os << "Interest Rate (%): " << accountinterest * 100 << std::endl;
    };
};
