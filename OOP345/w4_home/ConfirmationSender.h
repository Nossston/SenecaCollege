//
//  ConfirmationSender.h
//  w4_home
//
//  Created by Noston Liu on 2019/10/3.
//  Copyright © 2019 Noston. All rights reserved.
//

// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 2nd Oct , 2019

#ifndef ConfirmationSender_h
#define ConfirmationSender_h

#include <iostream>
#include "Reservation.h"

namespace sdds{
    class ConfirmationSender{
        size_t c_cnt;
        const Reservation** c_array;
    public:
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender&);
        ConfirmationSender(ConfirmationSender&&);
        ~ConfirmationSender();
        
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        
        friend ostream& operator<<(ostream& os, const ConfirmationSender& rhs);
    };
}

#endif /* ConfirmationSender_h */
