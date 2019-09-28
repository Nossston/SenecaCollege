//
//  List.h
//  w3_lab
//
//  Created by Noston Liu on 2019/9/22.
//  Copyright © 2019 Noston. All rights reserved.
//
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 22th Sept , 2019
#ifndef List_h
#define List_h

#include <iostream>
using namespace std;

namespace sdds{
    
    template<typename T, unsigned int N>
    class List{
        T arr[N];
        size_t count = 0;
    public:
        size_t size() const{
            return count;
        };
        const T& operator[](size_t i) const{
            return arr[i];
        };
        
        void operator+=(const T& tt){
            if (count  < N) {
                arr[count] = tt;
                count++;
            }
        };
    };
    
}


#endif /* List_h */
