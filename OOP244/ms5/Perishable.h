//
//  Perishable.h
//  ms5
//
//  Created by Noston Liu on 2019/7/28.
//  Copyright © 2019 Noston. All rights reserved.
//
/////////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/26   ms5
///////////////////////////////////////////////////////////
#ifndef Perishable_h
#define Perishable_h

#include <iostream>
#include <fstream>

#include "Good.h"
#include "Date.h"

namespace aid {
    class Perishable : public Good{
        Date p_date;
        
    public:
        Perishable();
        std::fstream& store(std::fstream& file, bool newLine = true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        const Date& expiry() const;
    };
}


#endif /* Perishable_h */
