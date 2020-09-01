// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel

// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 10/8 , 2019
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Book.h"
#include "Book.h"

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; i++)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";
    
    // get the books
    sdds::Book library[7];
    auto cnt = 0;
    {
        std::ifstream file(argv[1]);
        if (!file)
        {
            std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
            return 1;
        }

        std::string strBook = "";
        do {
            getline(file, strBook);
            if (strBook[0] != '#'){
                library[cnt] = strBook;
                cnt++;
            }
        } while (cnt < 7);
    }
    
    double usdToCadRate = 1.3;
    double gbpToCadRate = 1.5;
    
    // what's the difference between & and = in here;
    auto update = [=](sdds::Book& rhs) {
        std::string nation = rhs.country();
        size_t yr = rhs.year();
        if (nation == "US") {
            rhs.price() *= usdToCadRate;
        }
        else if( nation == "UK" && yr >= 1990 && yr <= 1999 ){
            rhs.price() *= gbpToCadRate;
        }
         return rhs.price();
    };

    
    std::cout << "-----------------------------------------\n";
    std::cout << "The library content\n";
    std::cout << "-----------------------------------------\n";
    for (auto& book : library)
        std::cout << book;
    std::cout << "-----------------------------------------\n\n";
    
    
    for (auto& i : library)
        update(i);
    
    // for (auto i = 0; i < 7; i++) {
    //     update(library[i]);
    // }
    
    
    std::cout << "-----------------------------------------\n";
    std::cout << "The library content (updated prices)\n";
    std::cout << "-----------------------------------------\n";
    for (auto& book : library)
        std::cout << book;
    std::cout << "-----------------------------------------\n";
    
    return 0;
}
