//
//  Item.c
//  ms1
//
//  Created by Noston Liu on 2019/10/22.
//  Copyright © 2019 Noston. All rights reserved.

// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 11/13 , 2019


#include <sstream>
#include "Item.h"

size_t Item::m_widthField = 1;

Item::Item(const std::string& src ){
    Utilities ult ;
    bool more = src.length() != 0 ;
    size_t pos = 0;
    // leave a space for error handling
    // since I am not having enough clue from the instruction
    try{
        m_name = ult.extractToken( src, pos ,more);
        if( ult.getFieldWidth() < m_name.length() ){
            ult.setFieldWidth( m_name.length());
        }
        m_serialNumber = stoi(ult.extractToken(src, pos, more)) ;
        m_quantity = stoi(ult.extractToken( src, pos ,more));
        m_description = ult.extractToken( src, pos ,more);
        m_widthField = ult.getFieldWidth();
    }
    catch(...){
        std::cout << "error without handling";
    }
    // if we couldn't extract token for any of variables
    // we set obj to empty safe statement
//    if( !m_description.length() ){
//        m_name = ""  ;
//        m_serialNumber = "";
//        m_quantity = "";
//    }
}
const std::string& Item::getName() const {
    return m_name;
};
const size_t Item::getSerialNumber() {
    m_serialNumber++;
    return m_serialNumber-1;
};
const size_t Item::getQuantity()  {
    return m_quantity;
} ;
void Item::updateQuantity(){
    if ( getQuantity() > 0 ){
        --m_quantity;
    }
};
void Item::display(std::ostream& os, bool full) const{
    os  << std::left
    << std::setw( int( m_widthField ) )
    << getName()
        << " [" << std::right << std::setw(6) << std::setfill('0') << m_serialNumber<< std::setfill(' ')  << "]" ;
    if (full){
        os
        << " Quantity: "  << std::left << std::setw(int( m_widthField ) )<< m_quantity
        << std::right <<std::setw( int( m_widthField ) ) << "Description: " << m_description   ;
    }
    os << std::endl;

};
