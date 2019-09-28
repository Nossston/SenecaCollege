//
//  Perishable.c
//  ms5
//
//  Created by Noston Liu on 2019/7/28.
//  Copyright © 2019 Noston. All rights reserved.
/////////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/26   ms5
///////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "Perishable.h"
#include "Good.h"
#include "Date.h"



namespace aid {
    
    Perishable::Perishable() : Good('P') {
        isClear();
    };
    
    std::fstream& Perishable::store(std::fstream& file, bool newLine) const{
        Good::store(file, false) ;
        file << ',';
        p_date.write(file);
        
        if (newLine){
            file << std::endl;
        }
        return file;
    };
    std::fstream& Perishable::load(std::fstream& file){
        Good::load(file);
        file.ignore();
        p_date.read(file);
        return file;

    };
    std::ostream& Perishable::write(std::ostream& os, bool linear) const{
        Good::write(os,linear);
        if ( !isEmpty() && isClear() ) {
            if (linear) {
                p_date.write(os);
            }
            else{
                os << std::endl << " Expiry date: ";
                p_date.write(os);
            }
        }
        return os;
    };
    std::istream& Perishable::read(std::istream& is){
        Good::read(is);
        if(!is.fail()){
            std::cout << " Expiry date (YYYY/MM/DD): ";
            p_date.read(is);
            switch ( p_date.errCode() ) {
                case CIN_FAILED:
                    message("Invalid Date Entry");
                    is.setstate(std::ios::failbit);
                    return is;
                case YEAR_ERROR:
                    message("Invalid Year in Date Entry");
                    is.setstate(std::ios::failbit);
                    return is;
                case MON_ERROR:
                    message("Invalid Month in Date Entry");
                    is.setstate(std::ios::failbit);
                    return is;
                case DAY_ERROR:
                    message("Invalid Day in Date Entry");
                    is.setstate(std::ios::failbit);
                    return is;
                case PAST_ERROR:
                    message("Invalid Expiry in Date Entry");
                    is.setstate(std::ios::failbit);
                    return is;
            }
        }
        return is;
    };
    
    const Date& Perishable::expiry() const{
        return p_date;
    };
    
    iGood* CreateProduct(char tag){
        iGood* temp = nullptr;
        switch (tag) {
            case 'N':
            case 'n':
                temp = new Good();
                break;
            case 'P':
            case 'p':
                temp = new Perishable();
                break;
        }
        return temp;
    };

}
