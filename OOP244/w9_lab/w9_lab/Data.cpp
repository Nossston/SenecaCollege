//
//  Data.c
//  w9_lab
//
//  Created by Noston Liu on 2019/7/23.
//  Copyright © 2019 Noston. All rights reserved.
//

///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/25    w9_in_lab
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include "Data.h"

namespace sict {
 
    // answers outputs statistics for visual validation of data
    //
    void answers(const int* year, const int* population, const int* violentCrime,
                 const double* violentCrimeRate, const int* grandTheftAuto, const int n) {
        
        // Q1: print the population change in millions of people
        // - print answer correct to 2 decimal places.
        // e..g "6.31 million";
        // note that population is an integer, so dividing by 1000000 would yield "6"
        
        std::cout.precision(2);
        std::cout.setf(std::ios::fixed);
        std::cout << "Population change from " << min(year, n) << " to " << max(year, n) << " is "
        << std::fixed << static_cast<double>(population[n-1] - population[0] )/ 1000000 << " million" << std::endl;
        
        
        
        // Q2. print whether violent crime rate has gone up or down between 2000 and 2005
        
        std::cout << "Violent Crime trend is ";
        if (violentCrime[n-1] - violentCrime[0] > 0) {
            std::cout << "up" << std::endl ;
        }
        else{
            std::cout << "down" << std::endl;
        }
        
        // Q3 print the GTA number accurate to 0 decimal places
        
        std::cout<< "There are " << std::fixed << average(grandTheftAuto, n)/1000000 << " million Grand Theft Auto incidents on average a year" << std::endl;
        
        
        // Q4. Print the min and max violentCrime rates
        
        std::cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << std::endl;
        std::cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << std::endl;

        
    }
}
