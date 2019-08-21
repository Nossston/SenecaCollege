/***********************************************************
 // OOP244 Workshop 2: Dynamic Memory
 // File Kingdom.cpp
 // Version 1.0
 // Date: 2019/05/06
 // Author: Cornel
 // Revision History
 ///////////////////////////////////////////////////////////
 // Name        Date    Reason
 // Liu,Yu-Che  5/23    w2_at_home
 ///////////////////////////////////////////////////////////
 ***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

namespace sict {
    
    void display(const struct Kingdom& kd){
        cout << kd.m_name << ", population " << kd.m_population << endl ;
        
    };

    void display(const struct Kingdom k[], int count){
        float sum = 0.00f;
    cout << "------------------------------\n"
        << "Kingdoms of SICT\n"
        << "------------------------------\n";
        
        for (int i = count; i >= 0; i--) {
            cout << i + 1 << ". " << k[i].m_name << ", population "
            << k[i].m_population << endl ;
            sum += k[i].m_population;
        }
        cout << "------------------------------\n"
        << "Total population of SICT: " << sum << "\n"
        << "------------------------------\n";

        
    };
};
