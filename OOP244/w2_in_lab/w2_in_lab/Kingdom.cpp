/***********************************************************
 // OOP244 Workshop 2: Dynamic Memory
 // File Kingdom.cpp
 // Version 1.0
 // Date: 2019/05/06
 // Author: Cornel
 // Revision History
 ///////////////////////////////////////////////////////////
 // Name        Date    Reason
 // Liu,Yu-Che  5/23    w2_in_lab
 ///////////////////////////////////////////////////////////
 ***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

namespace sict {
    
    void display(const struct Kingdom& kd){
        cout << kd.m_name << ", population " << kd.m_population << endl ;
        
    };}

