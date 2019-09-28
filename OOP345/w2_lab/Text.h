/// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 19th Sept , 2019

#ifndef Text_h
#define Text_h

#include <iostream>

using namespace std;

namespace sdds{
    
    class Text{
        string* t_string;
        int count;
    public:
        Text();
        Text(const char*);
        Text(Text&);
        Text& operator=(const Text&);
        ~Text();
        size_t size() const;
    };
};
#endif /* Text_h */
