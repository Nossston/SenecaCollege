//
//  Restaurant.h
//  w4_home
//
//  Created by Noston Liu on 2019/10/3.
//  Copyright © 2019 Noston. All rights reserved.
//

// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 2nd Oct , 2019
#ifndef Restaurant_h
#define Restaurant_h

#include <iostream>
#include "Reservation.h"

namespace sdds {
    class Restaurant{
        size_t r_cnt;
        Reservation* r_array;
    public:
        Restaurant();
        Restaurant(Reservation* reservations[], size_t cnt);
        Restaurant (Restaurant&& src);
        Restaurant( Restaurant& src);
        ~Restaurant();
        friend ostream& operator<<(ostream&, const Restaurant&);
    };
    
}

#endif /* Restaurant_h */
