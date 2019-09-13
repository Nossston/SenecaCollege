//  Process.c
//  w1_home
//  Created by Noston Liu on 2019/9/12.
//  Copyright © 2019 Noston. All rights reserved.
// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// process.cpp
// Chris Szalwinski - 2019/01/08
// Cornel - 2019/09/06

#include <iostream>
#include "String.h"
#include "process.h"

namespace sdds
{
    void process(const char* str)
    {
        String a = String(str);
        std::cout << a << std::endl;
    }
}
