//
//  Reservation.hpp
//  w4_lab
//
//  Created by Noston Liu on 2019/10/1.
//  Copyright © 2019 Noston. All rights reserved.
//
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 2nd Oct , 2019

#ifndef Reservation_h
#define Reservation_h

#include <iostream>
using namespace std;

namespace sdds{
    class Reservation{
        string r_id;
        string r_name;
        string r_mail;
        int num;
        int day;
        int hour;
    public:
        Reservation();
        Reservation(const std::string& m_res);
        friend ostream& operator<<(ostream& os, const Reservation& rhs);
        
    };
}

#endif /* Reservation_h */
