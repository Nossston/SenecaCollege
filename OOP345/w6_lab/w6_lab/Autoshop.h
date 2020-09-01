//
//  Autoshop.h
//  w6_lab
//
//  Created by Noston Liu on 2019/10/27.
//  Copyright © 2019 Noston. All rights reserved.
//

// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 10/31 , 2019
#ifndef Autoshop_h
#define Autoshop_h

#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"

namespace sdds{
    class Autoshop{
        std::vector<Vehicle*> m_vehicles;
    public:
        Autoshop& operator +=(Vehicle* theVehicle);
        void display(std::ostream& out) const;
    };
}


#endif /* Autoshop_h */
