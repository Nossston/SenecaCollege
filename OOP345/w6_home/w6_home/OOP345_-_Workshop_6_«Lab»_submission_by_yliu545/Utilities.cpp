//
//  Utilities.c
//  w6_lab
//
//  Created by Noston Liu on 2019/10/27.
//  Copyright � 2019 Noston. All rights reserved.
//

// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 10/31 , 2019
#include <string>
#include <iostream>
#include <sstream>

#include "Vehicle.h"

#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
   Vehicle* createInstance(std::istream& in){
       Vehicle* temp = nullptr;
       char type = 'j'; // initialize with random value;
       
       type = in.get();
       if (type == ' ') {
           type = in.get();
       }
       
       switch ( type ) {
           case 'c':
           case 'C':
               temp = new Car(in);
               break;
           case 'r':
           case 'R':
               temp = new Racecar(in);
               break;
           default:
               temp = nullptr;
               std::string s(1, type);
               std::string msg = "Unrecognized record type: [" + s + "]"  ;
               std::string eat ; // eat the rest of line.
               getline(in,eat,'\n');
               throw  (msg);
       }
       return temp;
   };
}
