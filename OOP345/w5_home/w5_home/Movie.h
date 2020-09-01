//
//  Movie.h
//  w5_home
//
//  Created by Noston Liu on 2019/10/9.
//  Copyright © 2019 Noston. All rights reserved.
//
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 10/17 , 2019
#ifndef Movie_h
#define Movie_h

#include <iostream>
#include <string>

using namespace std;

namespace sdds {
    class Movie{
        string _title;
        size_t _year;
        string _description;
    public:
        Movie();
        const std::string& title() const; //: a query that returns the title of the movie
        Movie(const std::string& strMovie);
        
        template<typename T>
        void fixSpelling(T spellChecker){
            spellChecker(_title);
            spellChecker(_description);
        };
        
        friend ostream& operator<<(ostream& os, const Movie& rhs);

    };
}

#endif /* Movie_h */
