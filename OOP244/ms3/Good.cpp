//
//  Good.c
//  m3
//
//  Created by Noston Liu on 2019/7/16.
//  Copyright © 2019 Noston. All rights reserved.
//

///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/26   ms3
///////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "Good.h"

namespace aid {
    

    void Good::name(const char* name){
        if (name != nullptr) {
            goodName = new char[max_name_length + 1];
            strncpy(goodName, name, max_name_length);
            goodName[max_name_length] = '\0';
        }
};

    const char* Good::name() const{
        return ( goodName == nullptr || goodName[0] == '\0') ? nullptr : goodName;
    };
    
    const char* Good::sku() const{
        return goodSku;
    };
    const char* Good::unit() const{
        return goodUnit;
    };
    bool Good::taxed() const{
        return taxable;
    };
    double Good::itemPrice() const{
        return price;
    };
    double Good::itemCost() const{
        return (taxable) ? (price + price*tax_rate) : price;
    };
    void Good::message(const char* goodMsg){
        errorState.message(goodMsg);
    };
    bool Good::isClear() const{
        return errorState.isClear();
    };

    Good::Good(char gtype){
        goodType = gtype;
        goodSku[0] = '\0';
        goodUnit[0] = '\0';
        goodName = nullptr;
        goodQTY = 0;
        goodQTYneed = 0;
        price = 0.0;
        taxable = false;
    };
    Good::Good(const char* gsku,const char* gname,const char* gunit, int ghold, bool gtaxable, double gprice, int gneeded){
        strncpy(goodSku, gsku, max_sku_length);
        goodSku[max_sku_length] = '\0';
        name(gname);
        strncpy(goodUnit, gunit, max_unit_length);
        goodUnit[max_unit_length] = '\0';
        goodQTY = ghold;
        taxable = gtaxable;
        price = gprice;
        goodQTYneed = gneeded;
    };
    Good::Good(Good& rhs){ // copy constructor
        strncpy(goodSku, rhs.goodSku, max_sku_length);
        goodSku[max_sku_length] = '\0';
        name(rhs.goodName);
        strncpy(goodUnit, rhs.goodUnit, max_unit_length);
        goodUnit[max_unit_length] = '\0';
        goodQTY = rhs.goodQTY;
        taxable = rhs.taxable;
        price = rhs.price;
        goodQTYneed = rhs.goodQTYneed;
        
    };
    Good& Good::operator=(const Good& rhs){
        if (this == &rhs) {
            return *this;
        }
        else{
            strncpy(goodSku, rhs.goodSku, max_sku_length);
            goodSku[max_sku_length] = '\0';
            name(rhs.goodName);
            strncpy(goodUnit, rhs.goodUnit, max_unit_length);
            goodUnit[max_unit_length] = '\0';
            goodQTY = rhs.goodQTY;
            taxable = rhs.taxable;
            price = rhs.price;
            goodQTYneed = rhs.goodQTYneed;
            return *this;
        }
    };
    
    Good::~Good(){
        delete [] goodName;
        goodName = nullptr;
    };

    std::fstream& Good::store(std::fstream& file, bool newLine) const{
     if(!isEmpty()){
        file << goodType << ',' << goodSku << ',' << goodUnit << ',' << goodName << ',' << goodQTY << ',' << goodQTYneed << ',' << price << ',' << taxable << ',' << errorState;
        if (newLine) {
            file << std::endl;
        }
     }
        return file;
    };
    std::fstream& Good::load(std::fstream& file){
        Good temp;
        file.getline(temp.goodSku,max_sku_length, ',');
        file.getline(temp.goodUnit,max_unit_length, ',');
        file.getline(temp.goodName,max_name_length, ',');
        file >> temp.taxable;
        file.ignore();
        file >> temp.price;
        file.ignore();
        file >> temp.goodQTY;
        file.ignore();
        file >> temp.goodQTYneed;
        *this = temp;
        return file;
    };
    std::ostream& Good::write(std::ostream& os, bool linear) const{
        if(linear){
            os <<std::left << std::setw(max_sku_length) << goodSku << "|"
            << std::setw(20) << goodName << "|"
            << std::right << std::fixed << std::setprecision(2) << std::setw(7) << itemCost() << "|" << std::setw(4) << goodQTY << "|"
            << std::left << std::setw(10) << goodUnit << "|"
            << std::right << std::setw(4) << goodQTYneed << "|" ;
        }
        else{
            os << " Sku: " << goodSku << std::endl
            << " Name (no spaces):  " << goodName << std::endl
            << " Price: " << price << std::endl;
            if (taxable) {
                os << " Price after tax: " << itemCost() << std::endl;
            }
            else{
                os << " N/A" << std::endl;
            }
            os << " Quantity on hand: " << goodQTY << std::endl
            << " Quantity needed: " << goodQTYneed << std::endl;
            
        }
        return os;
    };
    std::istream& Good::read(std::istream& is){
        char t_goodSku[ max_sku_length + 1] ;
        char t_goodUnit[max_unit_length + 1];
        char* t_goodName = new char[max_name_length+1];
        
        int t_goodQTY;
        int t_goodQTYneed;
        double t_price;
        
        bool t_taxable = false ;
        char t_taxed;
        
        std::cout << " Sku: ";
        is >> t_goodSku;
        std::cout << " Name (no spaces): ";
        is >> t_goodName;
        std::cout << " Unit: ";
        is >> t_goodUnit;
        std::cout << " Taxed? (y/n): ";
        is >> t_taxed;
        
        switch (t_taxed) {
            case 'Y':
            case 'y':
                t_taxable = true;
                break;
            case 'N':
            case 'n':
                t_taxable = false;
                break;
            default:
                is.setstate(std::ios::failbit);
                errorState.message("Only (Y)es or (N)o are acceptable");
                break;
        }
        
        if (!is.fail()) {
            
            std::cout << " Price: ";
            is >> t_price;
            
            if (is.fail()) {
                errorState.message("Invalid Price Entry");
            }
       
            std::cout << " Quantity on hand: ";
            is >> t_goodQTY;
            
            if (is.fail()) {
                errorState.message("Invalid Quantity Entry");
            }
       
            std::cout << " Quantity needed: ";
            is >> t_goodQTYneed;
            
            if (is.fail()) {
                errorState.message("Invalid Quantity Needed Entry");
            }
            
            *this = Good(t_goodSku, t_goodName, t_goodUnit, t_goodQTY, t_taxable, t_price, t_goodQTYneed);
            
        }
        return is;
    };
    
    bool Good::operator==(const char* sku) const{
        return (strcmp(goodSku,sku) == 0 ) ;
    };
    double Good::total_cost() const{
        return ( itemCost() * goodQTY );
    };
    void Good::quantity(int q){
        if (q > 0) goodQTY = q;
    };
    bool Good::isEmpty() const{
        return ( goodName == nullptr || goodName[0] == '\0'  );
    };
    int Good::qtyNeeded() const{
        return goodQTYneed;
    };
    int Good::quantity() const{
        return goodQTY;
    };
    bool Good::operator>(const char* sku) const{
        return (strcmp(goodSku,sku) > 0 ) ;
    };
    bool Good::operator>(const Good& rhs) const{
        return (strcmp(goodName ,rhs.goodName) > 0 ) ;
    };
    int Good::operator+=(int add){
        if (add > 0) {
            goodQTY += add;
        }
        return goodQTY;
    };

    std::ostream& operator<<(std::ostream& os, const Good& rhs){
        rhs.write(os,true);
        return os;
    };
    std::istream& operator>>(std::istream& is, Good& rhs){
        rhs.read(is);
        return is;
    };
    double operator+=(double& add, const Good& rhs){
        add += rhs.total_cost();
        return add;
    };

}
