// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 11/13 , 2019

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
    List<Product> mergeRaw(const List<Description>& l_desc, const List<Price>& l_price) {
        List<Product> priceList;
        for ( size_t i = 0; i < l_desc.size(); i++){
            for (size_t j = 0; j < l_price.size(); j++) {
                if (l_desc[i].code == l_price[j].code){
                    Product* tmp = new Product( l_desc[i].desc, l_price[j].price);
//                    Product(const std::string& str, double p);
                    // call validate()
                    tmp->validate();
                    priceList += *tmp;
                    delete tmp;
                };
            }
        }
        return priceList;
    }
}
