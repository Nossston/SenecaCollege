//
//  Car.c
//  w6_lab
//
//  Created by Noston Liu on 2019/10/27.
//  Copyright © 2019 Noston. All rights reserved.
//

// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 10/31 , 2019

#include <iomanip>
#include <sstream>
#include <algorithm> // replace
#include <vector>
#include "Car.h"

namespace sdds {
    
    Car::Car(std::istream& rhs){
        std::string temp;
        std::string msg ("Invalid record!");

        std::getline(rhs, temp, '\n' );
        auto tag_end = temp.find(',')+1 ;
        auto maker_end = temp.find(',', tag_end+1) +1;
        auto con_end = temp.find (',', maker_end+1) +1;
        if (  con_end == 0) { // true if there are 2 commas
            temp.insert(maker_end , "n");
            con_end = temp.find (',', maker_end+1) +1;
        }
        // testing ferrai
        else if( maker_end+2 == con_end ){ // maker_end +1 is empty
            temp.insert(maker_end , "n");
            con_end = temp.find (',', maker_end+1) +1;
        }
        auto spe_end = temp.find(',',con_end+1)+1;
        auto bos_end = temp.find('\n',spe_end+1)+1;
        c_maker = temp.substr( tag_end , maker_end-tag_end-1);
        if (c_maker.length() == 0 ) {
            auto maker_end = temp.find(',', tag_end+1) +2;
            c_maker = temp.substr( tag_end , maker_end-tag_end-1);
        }
        c_maker.erase(0,c_maker.find_first_not_of(" "));
        c_maker.erase(c_maker.find_last_not_of(" ") + 1);
        //  c_maker.erase( remove(c_maker.begin(),c_maker.end(), ' ' ), c_maker.end() );
        
        c_condition = temp.substr( maker_end , con_end-maker_end-1);
        
        if (c_condition.length() == 0) {
            c_condition = "n";
        }else{
            c_condition.erase(0,c_condition.find_first_not_of(" "));
            c_condition.erase(c_condition.find_last_not_of(" ") + 1);
        }
        
        switch ( condition()[0] ) {
            case 'n':
            case 'N':
            case ' ':
                c_condition = "new";
                break;
            case 'u':
            case 'U':
                c_condition = "used";
                break;
            case 'B':
            case 'b':
                c_condition = "broken";
                break;
            default:
                throw msg ;
                break;
        }
        
        
        
        c_topspeed  =  ( temp.substr(con_end, spe_end-con_end-1) );
        c_topspeed.erase(0,c_topspeed.find_first_not_of(" "));
        if( (c_topspeed[0]) > '9'  ){
            throw msg;
        }
        if( bos_end != spe_end){
            c_booster = temp.substr( spe_end, bos_end-spe_end-1 );
        }
    }; 
    double Car::boos() const{
        return stod(c_booster);
    }
    
    Car::Car(){
        c_tag = '\0';
        c_maker = "" ;
        c_condition = '\0';
        c_topspeed = "";
    };
    
    double Car::topSpeed() const{
        return stod(c_topspeed);
    };
    
    void Car::display(std::ostream& os) const{
        os
        <<  "| " << std::setw(10) << std::right << c_maker
        << " | " << std::setw(6) << std::left <<  condition()
        << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |" ;
    };
    std::string Car::condition() const{
        return c_condition;
    };
    Car::~Car(){};
    
}
