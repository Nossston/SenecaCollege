//
//  Utilities.h
//  ms1
//
//  Created by Noston Liu on 2019/10/22.
//  Copyright © 2019 Noston. All rights reserved.
//

#ifndef Utilities_h
#define Utilities_h

#include <iostream>
#include <string>

class Utilities{
    size_t m_widthField = 1 ;
    static char m_delimiter  ; // share the same delimeter
    
public:
    void setFieldWidth(size_t);
    size_t getFieldWidth() const;
    const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(const char);
    const char getDelimiter() const;
};

#endif /* Utilities_h */
