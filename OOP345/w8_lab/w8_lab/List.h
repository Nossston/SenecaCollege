#ifndef SDDS_LIST_H
#define SDDS_LIST_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 11/13 , 2019

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>
#include <memory>

namespace sdds {
    template <typename T>
    class List {
        std::vector<T> list;
    public:
        List() { }
        
        List(const char* fn) {
            std::ifstream file(fn);
            if (!file )
                throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***\n");
            while ( !file.eof() ) {
                T e;
                if (e.load(file))
                    list.push_back(*new T(e));
            }
        }
        size_t size() const { return list.size(); }
        const T& operator[](size_t i) const { return list[i]; }
        
        // TODO: Overload the += operator with a raw pointer
        //       as a second operand.
        void operator+=(const T& rhs ){
            list.push_back(rhs);
        }
        //
        
        void display(std::ostream& os) const {
            os << std::fixed << std::setprecision(2);
            for (auto& e : list)
                e.display(os);
        }
    };
    
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const List<T>& l) {
        l.display(os);
        return os;
    }
}
#endif
