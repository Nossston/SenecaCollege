//
//  main.cpp
//  w1_home
//
//  Created by Noston Liu on 2019/9/12.
//  Copyright © 2019 Noston. All rights reserved.
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 12th Sept , 2019
#include <iostream>
#include "process.h"
#include "String.h"

int main(int argc, const char * argv[]) {
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
    std::cout << "First processing:\n";
    std::cout << "------------------\n";
    for (int i = 1; i < argc; i++)
        sdds::process(argv[i]);
    std::cout << "------------------\n\n";
    
    sdds::g_maxSize = 5;
    
    std::cout << "------------------\n";
    std::cout << "Second processing:\n";
    std::cout << "------------------\n";
    for (int i = 1; i < argc; i++)
        sdds::process(argv[i]);
    std::cout << "------------------\n\n";
    
    sdds::g_maxSize = 42;
    sdds::String str1(argv[1]);
    str1.display(std::cout);
    std::cout << '\n';
    sdds::String str2 = str1;
    str2.display(std::cout);
    std::cout << '\n';
    sdds::String str3("School of Software Design and Data Science(SDDS)");
    str3.display(std::cout);
    std::cout << '\n';
    str3 = str1;
    std::cout << str1 << '\n' << str2 << '\n' << str3 << '\n';
    
    return 0;
}
