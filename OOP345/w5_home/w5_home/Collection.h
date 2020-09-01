//
//  Collection.h
//  w5_home
//
//  Created by Noston Liu on 2019/10/9.
//  Copyright © 2019 Noston. All rights reserved.
//
// Name: YuChe Liu
// Seneca Student ID: 134379189
// Seneca email: yliu545
// Date of completion: 10/17 , 2019

#ifndef Collection_h
#define Collection_h

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

namespace sdds{

template<class T>
class Collection{
    string _name;
    T* _arr;
    size_t _size;
    //a pointer to a function that returns void and receives two parameters of type const Collection<T>& and const T&.
    //This is the observer function (it observes an event): when an item has been added to the collection, the class Collection<T> will call this function informing the client about the addition.
    void (*observer) ( const Collection<T>& , const T& );

    
public:
    
    // delete copy operations
    Collection(const Collection& rhs) = delete;
    Collection& operator=(const Collection&) = delete;
    
    Collection(string name){
        _name = name;
        _arr = nullptr;
        _size = 0;
        observer = nullptr;
    }
    Collection(){
        _name = "";
        _arr = nullptr;
        _size = 0;
        observer = nullptr;
    }
    const string& name() const{ // a query that returns the name of the collection.
        return _name;
    }
    size_t size() const{
        return _size;
    }
    
    void setObserver(void (*observer_)(const Collection<T>& , const T&)){
        //stores the parameter into an attribute, to be used when an item is added to the collection. The parameter is a pointer to a function that returns void and accepts two parameters: a collection and an item that has just been added to the collection.
        observer = observer_;
        // observer(_arr,_arr[_size]);
        
    };
    
    Collection<T>& operator+=(const T& item){
        // adds a copy of item to the collection, only if the collection doesn't contain an item with the same title (type T has a member function called title() that returns the title of the item). If item is already in the collection, this function does nothing. If the item is not already in the collection, this function:
        bool find = false;
        for(size_t i = 0 ; i < this->size() && !find ; i++ ){
            if ( this->_arr[i].title() == item.title() ){
                find = true;
            }
        }
        if(!find){
            T* temp = new T[size()+1];
            for (size_t i = 0 ; i < size() ; i++){
                temp[i] = _arr[i];
            }
            delete [] _arr;
            _arr = temp;
            _arr[_size++] = item;
            if(observer != nullptr){
                observer(*this, item);
            }
        }
        return *this;
    };
    
    T& operator[](size_t idx) const{
        //returns the item at index idx.
        //if the index is out of range, this function throws an exception of type std::out_of_range with the message Bad index [IDX]. Collection has [SIZE] items.. Use operator + to concatenate strings.
        
        if( idx < _size){
            return _arr[idx];
        }
        string temp = "Bad index [" + to_string(idx) +"]. Collection has [" + to_string(size()) + "] items.";
        throw std::out_of_range(temp);
    };
    
    T* operator[](std::string title) const{
        // returns the address of the item with title title (type T has a member function called title() that returns the title of the item). If no such item exists, this function returns nullptr.
      size_t cnt = 0;
      bool flag = false;
      for ( size_t i = 0; i < size() ; i++){
          if( title == _arr[i].title() ){
              cnt = i ;
              flag = true;
          }
      }
      return flag ? &_arr[cnt] : nullptr;
        
        
    };
    
 };// class ends
    template<typename T>
    ostream& operator<<(ostream& os, const Collection<T>& rhs ){
        for (size_t i = 0; i < rhs.size() ; i++ ) {
            os << rhs[i]  ;
        }
        return os;
    };
};


#endif /* Collection_h */
