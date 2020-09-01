//
//  Racecar.c
//  w6_home
//
//  Created by Noston Liu on 2019/10/31.
//  Copyright © 2019 Noston. All rights reserved.
//
#include <iomanip>
#include <sstream>
#include <algorithm> // replace
#include <vector>
#include "Racecar.h"

namespace sdds{
    Racecar::Racecar(std::istream& in) : Car(in){
        m_booster = boos() ;
    };
    void Racecar::display(std::ostream& os) const{
        Car::display(os);
        os << "*";
    };
    double Racecar::topSpeed() const{
        return Car::topSpeed() * (1+ boos() ) ;
    };

}
