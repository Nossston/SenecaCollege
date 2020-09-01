//
//  Book.h
//  w5_lab
//
//  Created by Noston Liu on 2019/10/7.
//  Copyright © 2019 Noston. All rights reserved.
//

// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 10/8 , 2019

#ifndef Book_h
#define Book_h

#include <string>
#include <iostream>
using namespace std;
namespace sdds {
    class Book{
        string _author;
        string _title;
        string _country;
        size_t _year;
        double _price;
        string _description;
    public:
        Book();
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const ;
        double& price();
        Book(const std::string& strBook);
        friend ostream& operator<<(ostream& os, const Book& rhs);

    };
}

#endif /* Book_h */
