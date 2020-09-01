//
//  Racecar.h
//  w6_home
//
//  Created by Noston Liu on 2019/10/31.
//  Copyright © 2019 Noston. All rights reserved.
//

#ifndef Racecar_h
#define Racecar_h

#include <iostream>
#include <string>
#include "Utilities.h"
#include "Car.h"

namespace sdds {
    class Racecar : public Car{
        std::string m_booster;
    public:
        Racecar(std::istream&);
        void display(std::ostream&) const;
        double topSpeed() const;

    };
}

#endif /* Racecar_h */
