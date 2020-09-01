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
       std::getline(rhs, temp, '\n' );
       std::cout << temp <<'\n' ;
       auto tag_end = temp.find(',')+1 ;
       auto maker_end = temp.find(',', tag_end+1) +1;
       auto con_end = temp.find (',', maker_end+1) +1;
       
       if (maker_end+1 == con_end || con_end == 0) {
           temp.insert(maker_end , " ");
           std::cout << temp <<'\n' ;
           con_end = temp.find (',', maker_end+1) +1;
       }
       
       auto spe_end = temp.find(',',con_end+1)+1;
       auto bos_end = temp.find('\n',spe_end+1)+1;
       // c_tag = temp.substr( 0 , tag_end -1);
       
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
       
       c_topspeed  =  ( temp.substr(con_end, spe_end-con_end-1) );
       c_topspeed.erase(0,c_topspeed.find_first_not_of(" "));
       
       if( bos_end != spe_end){
           c_booster = temp.substr( spe_end, bos_end-spe_end-1 );
           stod(c_booster) > 0  ? isRace = true : isRace = false;
           if (isRace) {
               c_tag = 'R';
           }
       }
   }; // TAG,MAKER,CONDITION,TOP_SPEED
    
    
    
    /*
 Car::Car(std::istream& in){
     c_tag = 'C';
     std::string line;
     std::getline( in,line);
     
     
     replace(line.begin(),line.end(), ',' , ' ');
     
     
     std::cout<< line;
     std::stringstream ss(line);
     ss  >> c_maker >> c_condition >> c_topspeed  >> c_booster;
     std::cout << "  boos:"<< c_booster << std::endl ;
     if (c_booster[0] != '\n' && c_booster != "") {
         stod(c_booster) > 0  ? isRace = true : isRace = false;
         if (isRace) {
             c_tag = 'R';
         }
     }
     
 }
    */
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
        if( (c_topspeed[0]) > '9'  ){
            std::cout << std::string("Invaild record");
            return 2.2;
        }
        else{
            return stod(c_topspeed);
        }
    };
    
    void Car::display(std::ostream& os) const{
        std::string temp = "";
        
        switch ( condition()[0] ) {
            case 'n':
            case 'N':
                temp = "new";
                break;
            case 'u':
            case 'U':
                temp = "used";
                break;
            case 'B':
            case 'b':
                temp = "broken";
                break;
            
            default:
                temp = "invaild";
                break;
        }
        if (condition().length() == 0 ){
            temp = "new";
        }
        
        if (!isRace) {
            os
            <<  "| " << std::setw(10) << std::right << c_maker
            << " | " << std::setw(6) << std::left <<  temp
            << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |" << std::endl;
            
        }
        else{
            os
            <<  "| " << std::setw(10) << std::right << c_maker
            << " | " << std::setw(6) << std::left   << temp
            << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |" << c_booster << "*" << std::endl;
            
        }
    };
    std::string Car::condition() const{
        return c_condition;
    };

    Car::~Car(){};

}
