//
//  Car.h
//  w6_lab
//
//  Created by Noston Liu on 2019/10/27.
//  Copyright © 2019 Noston. All rights reserved.
//

// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 10/31 , 2019

#ifndef Car_h
#define Car_h

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
    class Car : public Vehicle {
        std::string c_tag;
        std::string c_maker ;
        std::string c_condition ;
        std::string c_topspeed;
        std::string c_booster; // testing
        bool isRace;
    public:
        Car(std::istream&); // TAG,MAKER,CONDITION,TOP_SPEED
        Car();
        double topSpeed() const;
        void display(std::ostream&) const;
        std::string condition() const;
        ~Car();
        double boos() const;
    };
}

#endif /* Car_h */
