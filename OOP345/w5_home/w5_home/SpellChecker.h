//
//  SpellChecker.h
//  w5_home
//
//  Created by Noston Liu on 2019/10/9.
//  Copyright © 2019 Noston. All rights reserved.
//
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 10/17 , 2019
#ifndef SpellChecker_h
#define SpellChecker_h

#include <iostream>
#include <string>
#define MAX 5
using namespace std;

namespace sdds{
    class SpellChecker{
        string m_badWords[MAX];
        string m_goodWords[MAX];
    public:
        SpellChecker(const char* filename);
        void operator()(std::string& text) const;
    };
}

#endif /* SpellChecker_h */
