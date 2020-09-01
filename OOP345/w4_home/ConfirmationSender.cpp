//
//  ConfirmationSender.c
//  w4_home
//
//  Created by Noston Liu on 2019/10/3.
//  Copyright © 2019 Noston. All rights reserved.
//


// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 2nd Oct , 2019

#include "ConfirmationSender.h"
using namespace std;

namespace sdds{
    
    ConfirmationSender::ConfirmationSender(){
        c_array = nullptr;
        c_cnt = 0;
    };
    
ConfirmationSender::ConfirmationSender(const ConfirmationSender& rhs){
    c_cnt = rhs.c_cnt ;
    if( c_cnt > 0){
        c_array = const_cast<const Reservation**>(new Reservation*[c_cnt]);
        for (size_t i = 0 ; i < c_cnt; i++) {
            c_array[i] = rhs.c_array[i];
        }
    }
    else{
        c_array = nullptr;
    }
};
    ConfirmationSender::ConfirmationSender(ConfirmationSender&& rhs){
        c_cnt = rhs.c_cnt;
        c_array = rhs.c_array;
        rhs.c_cnt = 0;
        rhs.c_array = nullptr;
    };

    
    
    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& rhs){
        bool findElement = false; //if rhs is already in the array, this operator does nothing
    
        for (size_t i = 0; i < c_cnt; i++) {
            if( c_array[i] == &rhs ){
                findElement = true;
            }
        }
        
        if(!findElement){
            Reservation** temp = new Reservation*[c_cnt+1];
            for (size_t i = 0; i < c_cnt; i++) {
                temp[i] = const_cast<Reservation*>(c_array[i]);
            }
            delete [] c_array;
            c_array = const_cast<const Reservation**>(temp);
            c_array[c_cnt++] = &rhs;
        }
        return *this;
    };
    
    
    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& rhs){
        bool findElement = false; // if rhs is not in the array, this operator does nothing
        size_t  i = 0;

        for ( i = 0; i < c_cnt; i++) {
            if (c_array[i] == &rhs ) {
                findElement = true;
            }
        }
        
        if (findElement) {
            Reservation** temp = new Reservation*[c_cnt--];
            if(i > 0){
                for (size_t j = 0; j < i; j++) {
                    temp[j] = const_cast<Reservation*>(c_array[j]);
                }
            }
            for (size_t j = i; j < c_cnt; j++) {
                temp[j] = const_cast<Reservation*>(c_array[j+1]);
            }
            delete [] c_array;
            c_array = const_cast<const Reservation**>(temp);
        }
        
        return *this;
        
    };
    
    ConfirmationSender::~ConfirmationSender(){
        delete [] c_array;
    }
    
    ostream& operator<<(ostream& os, const ConfirmationSender& rhs){
        
        
        os << "--------------------------" << endl
        << "Confirmations to Send" << endl
        << "--------------------------" << endl;
        
        if ( rhs.c_cnt == 0) {
            os << "The object is empty!" << endl ;
        }
        else{
            for (size_t i = 0; i < rhs.c_cnt ; i++) {
                os << *rhs.c_array[i];
            }
        }
        os << "--------------------------" << endl;

        
        return os;
    };

}
