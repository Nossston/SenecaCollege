//
//  Autoshop.c
//  w6_lab
//
//  Created by Noston Liu on 2019/10/27.
//  Copyright � 2019 Noston. All rights reserved.
//

// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 10/31 , 2019
#include "Autoshop.h"

namespace sdds {
    Autoshop& Autoshop::operator +=(Vehicle* theVehicle){
        m_vehicles.push_back( theVehicle );
        return *this;
    };
    
    void Autoshop::display(std::ostream& os) const{
        
        os << "--------------------------------" << std::endl
        << "| Cars in the autoshop!        |" << std::endl
        << "--------------------------------" << std::endl;
        
        for ( auto i : this->m_vehicles){
            i->display(os);
            os << std::endl;
        }
        os << "--------------------------------" << std::endl;
    };
    
    Autoshop::~Autoshop(){
        while(!m_vehicles.empty() ){
            m_vehicles.pop_back();
        }
    }
}
