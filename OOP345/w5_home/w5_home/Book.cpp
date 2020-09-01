//
//  Book.c
//  w5_lab
//
//  Created by Noston Liu on 2019/10/7.
//  Copyright © 2019 Noston. All rights reserved.
//

// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 10/8 , 2019

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

#include "Book.h"

using namespace std;

namespace sdds {
    
    Book::Book(){
        _author = "";
        _title = "";
        _country = "";
        _year = 0;
        _price = 0.0;
        _description = "";
    };
    const string& Book::title() const{
        return _title;
    };
    const string& Book::country() const{
        return _country;
    };
    const size_t& Book::year() const{
        return _year;
    } ;
    double& Book::price(){
        return _price;
    };//: a function that returns the price by referene, allowing you to update the price
    
    Book::Book(const std::string& strBook){
        auto author_end = strBook.find(',') + 1;
        auto title_end = strBook.find(',',author_end + 1) + 1;
        auto country_end = strBook.find(',',title_end + 1) + 1;
        auto price_end = strBook.find(',',country_end + 1) + 1;
        auto year_end = strBook.find(',', price_end + 1) + 1;
        auto desc_end = strBook.length();
        _author = strBook.substr( 0 ,author_end - 1);
        _author.erase(0,_author.find_first_not_of(" "));
        _author.erase(_author.find_last_not_of(" ") + 1);
        _title = strBook.substr(author_end  , title_end - author_end - 1);
        _title.erase(0,_title.find_first_not_of(" "));
        _title.erase(_title.find_last_not_of(" ") + 1);
        _country = strBook.substr(title_end  , country_end - title_end - 1);
        _country.erase(0,_country.find_first_not_of(" "));
        _country.erase(_country.find_last_not_of(" ") + 1);
        _price = stod(strBook.substr(country_end , price_end - country_end)  );
        _year = stoi(strBook.substr(price_end , year_end - price_end));
        _description = strBook.substr(year_end  , desc_end - year_end);
        _description.erase(0,_description.find_first_not_of(" "));
        _description.erase(_description.find_last_not_of(" ") + 1);
        
    };
    
    ostream& operator<<(ostream& os, const Book& rhs){
        
        string bar = " | ";
        
        os
        << setw(20) << rhs._author << bar
        << setw(22) << rhs._title << bar
        << setw(5) << rhs._country << bar
        << setw(4) << rhs._year << bar
        << setw(6) << fixed << setprecision(2)<< rhs._price << bar
        << rhs._description << endl ;
        
        return os;
    };
    
}
