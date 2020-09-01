//
//  Restaurant.c
//  w4_home
//
//  Created by Noston Liu on 2019/10/3.
//  Copyright © 2019 Noston. All rights reserved.
//

// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 2nd Oct , 2019
#include "Reservation.h"

#include "Restaurant.h"

using namespace std;
namespace sdds {
    
    //default constructor
    Restaurant::Restaurant(){
        r_cnt = 0;
        r_array = nullptr;
    };
    
    Restaurant::Restaurant(Reservation* reservations[], size_t cnt){
        r_cnt = cnt;
        r_array = new Reservation[r_cnt];
        for (size_t i = 0; i < cnt; i++) {
            r_array[i] = *reservations[i];
        }
    };
    
    
    // copy
    Restaurant::Restaurant( Restaurant& rhs){
        r_cnt = rhs.r_cnt;
        if ( r_cnt > 0 ){
            r_array = new Reservation[r_cnt];
            for (size_t i = 0; i < r_cnt; i++) {
                r_array[i] = rhs.r_array[i];
            }
        }
        else{
            r_array = nullptr;
        }
    };

    Restaurant::~Restaurant(){
        delete [] r_array;
    }
    
    // move constructor
    Restaurant::Restaurant (Restaurant&& rhs){
        r_cnt = rhs.r_cnt;
        r_array = rhs.r_array;
        rhs.r_cnt = 0;
        rhs.r_array = nullptr;
    };
    
    
    
    
    ostream& operator<<(ostream& os, const Restaurant& rhs){
        os << "--------------------------" << endl
        << "Fancy Restaurant" << endl
        << "--------------------------" << endl;
        
        if ( rhs.r_cnt == 0 ) {
            os << "The object is empty!" << endl ;
        }
        else{
            for (size_t i = 0; i < rhs.r_cnt ; i++) {
                os << rhs.r_array[i];
            }
        }
        os << "--------------------------" << endl;
        return os;
    };

    }

