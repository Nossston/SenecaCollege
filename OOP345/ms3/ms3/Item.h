//
//  Item.h
//  ms1
//
//  Created by Noston Liu on 2019/10/22.
//  Copyright © 2019 Noston. All rights reserved.
//

#ifndef Item_h
#define Item_h

#include <iostream>
#include <string>
#include <iomanip>
#include <utility>
#include "Utilities.h"

class Item{
    std::string m_name ;
    std::string m_description ;
    size_t m_serialNumber ;
    size_t m_quantity ;
    static size_t m_widthField ;
public:
    Item(const std::string& src );
    const std::string& getName() const;
    const size_t getSerialNumber()  ;
    const size_t getQuantity()  ;
    void updateQuantity();
    void display(std::ostream& os, bool full) const ;
};

#endif /* Item_h */
