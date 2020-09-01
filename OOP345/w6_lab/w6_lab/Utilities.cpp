//
//  Utilities.c
//  w6_lab
//
//  Created by Noston Liu on 2019/10/27.
//  Copyright © 2019 Noston. All rights reserved.
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

namespace sdds {
    
   Vehicle* createInstance(std::istream& in){
       Vehicle* temp = nullptr;
 //   std::string test;
 //   getline(in, test);
 //   char type = test[0] ;
       char type = 'j';
       type = in.get();
       if (type == ' ') {
           type = in.get();
       }
       switch ( type ) {
           case 'c':
           case 'C':
               std::cout << "Car created" << '\n';
               temp = new Car(in);
               break;
               
           case 'R':
           case 'r':
               std::cout << "RaceCar created" << '\n';
               temp = new Car(in);
               break;
               
           default:
               temp = nullptr;
               std::string s(1, type);
               std::string msg = "Unrecognized record type: [" + s + "]" + "\n" ;
               std::cout <<  (msg);
               std::string eat ;
               getline(in,eat,'\n');

       }
     // char eat =  in.get(); // eat 
       return temp;
   };
     
    /*
    // v2
   Vehicle* createInstance(std::istream& in){
       std::string line ;
       std::getline(in, line, '\n');
       std::stringstream ss(line);
       char type , delim;
       ss >> type >> delim;
  
       switch (type) {
           case 'c':
           case 'C':
               return new Car(in);
               break;
       }
       return nullptr;

   }
*/
 //  Vehicle* createInstance(std::istream& in){
 //      return new Car (in);
 //  }
}
