//
//  String.c
//  w1_lab
//
//  Created by Noston Liu on 2019/9/9.
//  Copyright © 2019 Noston. All rights reserved.
//

// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 12th Sept , 2019
#include "String.h"

namespace sdds{
    unsigned int g_maxSize = 3;
    
    String::String(const char* rhs){
        if (  rhs != nullptr && rhs[0] != '\0' ){
            strncpy(s_string, rhs, 3);
            s_string[3] = '\0';
        }
        else{
            s_string[0] = '\0';
        }
    };
    
    void String::display(std::ostream& os) const{
        os << s_string;
    };
    
    std::ostream& operator<<( std::ostream& os, const String& rhs){
        static int counter = 1;
        os << counter << ": ";
        rhs.display(os);
        counter++;
        return os;
    };

}
