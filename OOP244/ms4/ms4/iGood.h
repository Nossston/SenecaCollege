//
//  iGood.h
//  ms4
//
//  Created by Noston Liu on 2019/7/26.
//  Copyright © 2019 Noston. All rights reserved.
//
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/28   ms4
///////////////////////////////////////////////////////////

#ifndef iGood_h
#define iGood_h

#include <iostream>
#include <fstream>

namespace aid{
   
    class iGood{
    
    public:
        virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
        virtual std::fstream& load(std::fstream& file) = 0;
        virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual bool operator==(const char*) const = 0;
        virtual double total_cost() const = 0;
        virtual const char* name() const = 0;
        virtual void quantity(int) = 0;
        virtual int qtyNeeded() const = 0;
        virtual int quantity() const = 0;
        virtual int operator+=(int) = 0;
        virtual bool operator>(const iGood&) const = 0;
        virtual ~iGood(){};
    };
    iGood* CreateProduct(char tag);
    std::ostream& operator<<(std::ostream&, const iGood&);
    std::istream& operator>>(std::istream&, iGood&);
    double operator+=(double&, const iGood&);
}
#endif /* iGood_h */
