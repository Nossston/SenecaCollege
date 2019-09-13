// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// w1.cpp
// Chris Szalwinski - 2019/01/08
// Cornel - 2019/09/06

// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 12th Sept , 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include <iostream>
#include "process.h"
#include "String.h"

int main(int argc, const char * argv[]) {
    {
        std::cout << "Command Line:\n";
        
        for(int i = 1; i<argc ; i++){
            std::cout << argv[i] << std::endl;
        }
        
        std::cout << std::endl;
        if (argc < 2)
        {
            std::cerr << "\n*** Insufficient number of arguments ***\n";
            return 1;
        }
        
        std::cout << "------------------\n";
        std::cout << "Global variable:\n";
        std::cout << "------------------\n";
        std::cout << "Old Value: " << sdds::g_maxSize << '\n';
        sdds::g_maxSize = 4;
        std::cout << "New Value: " << sdds::g_maxSize << '\n';
        std::cout << "------------------\n\n";
        
        std::cout << "------------------\n";
        std::cout << "Processing:\n";
        std::cout << "------------------\n";
        for (int i = 1; i < argc; i++)
            sdds::process(argv[i]);
        std::cout << "------------------\n\n";
        
        return 0;
    }
}
