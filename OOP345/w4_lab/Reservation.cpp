//
//  Reservation.cpp
//  w4_lab
//
//  Created by Noston Liu on 2019/10/1.
//  Copyright © 2019 Noston. All rights reserved.
//
//
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 2nd Oct , 2019


#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

#include "Reservation.h"
using namespace std;

namespace sdds{
    Reservation::Reservation(){
        r_id = "";
        r_name = "";
        r_mail = "";
        num = 0;
        day = 0;
        hour = 0;
    };
    Reservation::Reservation(const std::string& m_res){
        
        // The reason why to add 1 is due to the string.find function locates the index of char
        // However, we want the string after that char
        // Thus, we put + 1 after

        size_t id_end = m_res.find(':') + 1;
        auto name_end = m_res.find(',') + 1 ;
        auto email_end = m_res.find(',',name_end + 1) + 1;
        auto num_end = m_res.find(',',email_end + 1) + 1;
        auto day_end = m_res.find(',',num_end + 1) + 1;
        auto hour_end = m_res.length();
        r_id = m_res.substr( 0 ,id_end );
        r_id.erase( remove(r_id.begin(),r_id.end(), ' ' ), r_id.end() );
        r_name = m_res.substr(id_end  , name_end - id_end - 1);
        r_name.erase( remove(r_name.begin(),r_name.end(), ' ' ), r_name.end() );
        r_mail = m_res.substr(name_end  , email_end - name_end - 1);
        r_mail.erase( remove(r_mail.begin(),r_mail.end(), ' ' ), r_mail.end() );
        num = stoi(m_res.substr(email_end , num_end - email_end));
        day = stoi(m_res.substr(num_end , day_end - num_end)  );
        hour = stoi(m_res.substr(day_end , hour_end - day_end));
        
        // As required
        r_mail.insert(0,"<");
        r_mail.append(">");
        
    };
    ostream& operator<<(ostream& os, const Reservation& rhs) {
        
        string temp;
        
        if (rhs.hour >= 6 && rhs.hour <= 9 ) {
            temp = "Breakfast on day ";
        }
        else if( rhs.hour >= 11 && rhs.hour <= 15){
            temp = "Lunch on day ";
        }
        else if ( rhs.hour >= 17 && rhs.hour <= 21){
            temp = "Dinner on day ";
        }
        else{
            temp = "Drinks on day ";
        }
        
        
        os  << "Reservation " << rhs.r_id
        << setw(11) << right << rhs.r_name << "  "
        << setw(24) << left << rhs.r_mail
        //  << Reservation::Meal(rhs.hour)
        << temp
        << rhs.day << " @ "
        << rhs.hour << ":00 for "
        << rhs.num << " people."
        << endl;
        return os;
    };
    
    /*
    string Reservation::Meal(int hour){
        string temp;
        
        if (hour >= 6 && hour <= 9 ) {
            temp = "Breakfast on day ";
        }
        else if( hour >= 11 && hour <= 15){
            temp = "Lunch on day ";
        }
        else if ( hour >= 17 && hour <= 21){
            temp = "Dinner on day ";
        }
        else{
            temp = "Drinks on day ";
        }
        
        return temp;
    }
    */
}
