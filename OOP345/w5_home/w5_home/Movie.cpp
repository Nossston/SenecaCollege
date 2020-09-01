//
//  Movie.c
//  w5_home
//
//  Created by Noston Liu on 2019/10/9.
//  Copyright © 2019 Noston. All rights reserved.
//
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 10/17 , 2019
#include <iomanip>
#include <iostream>
#include <string>

#include "Movie.h"

using namespace std;

namespace sdds {
    Movie::Movie(){
        _title ="";
        _year = 0;
        _description = "";
    };
    const string& Movie::title() const{
        return _title;
    };
    
    Movie::Movie(const string& strMovie){
        auto title_end = strMovie.find(',') + 1 ;
        auto year_end = strMovie.find(',',title_end + 1) + 1;
        auto desc_end = strMovie.length();
        _title = strMovie.substr(0, title_end - 1);
        _title.erase(0 , _title.find_first_not_of(" "));
        _title.erase(_title.find_last_not_of(" ") + 1);
        _year = stoi(strMovie.substr(title_end , year_end - title_end));
        _description = strMovie.substr(year_end  , desc_end - year_end);
        _description.erase( 0 , _description.find_first_not_of(" "));
        _description.erase(_description.find_last_not_of(" ") + 1);

    };
    
    ostream& operator<<(ostream& os, const Movie& rhs){
        string bar = " | ";
        
        os
        << setw(40) << rhs._title << bar
        << setw(4) << rhs._year << bar
        << rhs._description << endl;
        
        return os;
    };


}
