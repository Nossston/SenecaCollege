//
//  Good.h
//  m3
//
//  Created by Noston Liu on 2019/7/16.
//  Copyright © 2019 Noston. All rights reserved.
//


///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/26   ms3
///////////////////////////////////////////////////////////
#ifndef Good_h
#define Good_h

#include <iostream>
#include "Error.h"

namespace aid {
    const int max_sku_length = 7;
    const int max_unit_length = 10;
    const int max_name_length = 75;
    const double tax_rate = 0.13;
    
    class Good{
        char goodType;
        char goodSku[ max_sku_length + 1] ;
        char goodUnit[max_unit_length + 1];
        char* goodName;
        int goodQTY;
        int goodQTYneed;
        double price;
        bool taxable;
        Error errorState;
    protected:
        void name(const char*);
        const char* name() const;
        const char* sku() const;
        const char* unit() const;
        bool taxed() const;
        double itemPrice() const;
        double itemCost() const;
        void message(const char*);
        bool isClear() const;
       
    public:
        explicit Good(char gtype = 'N');
        Good(const char* gsku,const char* gname,const char* gunit, int ghold = 0, bool gtaxable = true, double gprice = 0.0, int gneeded = 0);
        Good(Good& rhs); // copy constructor
        Good& operator=(const Good& rhs);
        ~Good();
        std::fstream& store(std::fstream& file, bool newLine = true ) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        bool operator==(const char*) const;
        double total_cost() const;
        void quantity(int);
        bool isEmpty() const;
        int qtyNeeded() const;
        int quantity() const;
        bool operator>(const char*) const;
        bool operator>(const Good&) const;
        int operator+=(int);
    };
    std::ostream& operator<<(std::ostream& os, const Good&);
    std::istream& operator>>(std::istream& is, Good&);
    double operator+=(double&, const Good&);

}
#endif /* Good_h */
