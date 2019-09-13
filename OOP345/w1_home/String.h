// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 12th Sept , 2019

#ifndef String_h
#define String_h

#include <iostream>
#include <cstring>
#include <string>

namespace sdds {
    extern unsigned int g_maxSize;
    
    class String{
        //char s_string[4];
        char* s_string;
    public:
        String(const char*);
        void display( std::ostream& )const;
    };
    std::ostream& operator<< (std::ostream&, const String&);
    
}

#endif /* String_h */
