//
//  LVPair.h
//  w3_lab
//
//  Created by Noston Liu on 2019/9/22.
//  Copyright © 2019 Noston. All rights reserved.
//
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 22th Sept , 2019
#ifndef LVPair_h
#define LVPair_h

#include <iostream>
using namespace std;
namespace sdds{
    
    template<typename L, typename V>
    class LVPair{
        L label;
        V val;
    public:
        LVPair(): label {}, val {}
        {};
        
        LVPair(const L& aa, const V& bb): label{aa}, val{bb}
        {};
        
        const L& key() const{
            return label;
        };
        const V& value() const{
             return val;
        };
        void display(std::ostream& os) const{
            os << key() << " : " << value() << endl;
        };
    };
    
    template<typename L, typename V>
    virtual std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair){
        pair.display(os) ;
        return os;
    };
    
    
    
}

#endif /* LVPair_h */
