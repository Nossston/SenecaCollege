//
//  Utilities.c
//  ms1
//
//  Created by Noston Liu on 2019/10/22.
//  Copyright © 2019 Noston. All rights reserved.
//
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 11/13 , 2019
#include "Utilities.h"

char Utilities::m_delimiter = '\0' ;

void Utilities::setFieldWidth(size_t src){
    m_widthField = src;
};
size_t Utilities::getFieldWidth() const{
    return m_widthField;
};

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
    std::string tmp;
    if( more ){
        auto find_delie = str.find( getDelimiter(),next_pos );
        
        if ( find_delie != 0 ) {
            tmp = str.substr( next_pos, find_delie-next_pos );
            if (tmp.length() == 0) {
                std::string msg = "two deliemiter are together";
                more = false ;
                throw msg;
            }
            next_pos = find_delie+1 ;
        }
        else{
            tmp = str.substr( next_pos,'\n' );
            next_pos = 0;
            more = false;
        }
    }
    return tmp;
    
};

void Utilities::setDelimiter(const char src){
    m_delimiter = src ;
};

const char Utilities::getDelimiter() const{
    return m_delimiter;
};
