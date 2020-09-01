//
//  CustomerOrder.c
//  ms2
//
//  Created by Noston Liu on 2019/11/17.
//  Copyright © 2019 Noston. All rights reserved.
//
#include <future>
#include <vector>
#include <algorithm>
#include "CustomerOrder.h"
size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder(){
    m_cntItem = 0;
    m_lstItem = nullptr;
};

CustomerOrder::CustomerOrder(std::string& src){
    Utilities ult ;
    bool more = src.length() != 0 ;
    size_t pos = 0;
    try{
        m_name = ult.extractToken( src, pos ,more);
        if( m_widthField < m_name.length() ){
            m_widthField = ( m_name.length());
        }
        m_product = ult.extractToken(src, pos, more) ;
        if( m_widthField < m_product.length() ){
            m_widthField = ( m_product.length());
        }
        m_cntItem = (unsigned int)count(src.begin(),src.end(),ult.getDelimiter())-1;
        m_lstItem = new ItemInfo* [m_cntItem];
        for (unsigned int i = 0; i < m_cntItem; i++) {
            m_lstItem[i] = new ItemInfo(ult.extractToken(src, pos, more));
        }
    }
    catch(...){
        std::cout << "error without handling";
    }
    
};

CustomerOrder::CustomerOrder(const CustomerOrder&){
    std::string msg = "We don't allow copy constructor";
    throw msg;
};

//move constructor. This constructor should "promise" that it doesn't throw exceptions. Use the noexcept keyword in the prototype.
CustomerOrder::CustomerOrder(CustomerOrder&& src)noexcept  {
    *this = std::move(src);
};

CustomerOrder& CustomerOrder::operator=( CustomerOrder&& src) noexcept {
    if (  src.m_lstItem != nullptr &&  this != &src) {
        m_name    = src.m_name;
        m_lstItem = src.m_lstItem;
        m_cntItem = src.m_cntItem;
        m_product = src.m_product;
        src.m_name = "";
        src.m_lstItem= nullptr;
        src.m_cntItem= 0;
        src.m_product= "";
    }
    return *this;
};

CustomerOrder::~CustomerOrder(){
    delete[] m_lstItem;
};

bool CustomerOrder::getItemFillState(std::string src) const{
    for( size_t i = 0 ; i < m_cntItem ;i++  ){
        if(src == m_lstItem[i]->m_itemName ){
            return m_lstItem[i]->m_fillState ;
        }
    }
    return true;
};
bool CustomerOrder::getOrderFillState() const {
    bool flag = true;
    for (unsigned int  i = 0; i < m_cntItem && flag ; i++) {
        if( !m_lstItem[i]->m_fillState ){
            flag = false;
        }
    }
    return flag;
};
void CustomerOrder::fillItem(Item& item, std::ostream& os) {
    for (unsigned int i = 0; i < m_cntItem; i++) {
        if ( item.getName().length() != 0 && m_lstItem[i]->m_itemName == item.getName() ) {
            if( item.getQuantity() > 0 ){
                item.updateQuantity();
                m_lstItem[i]->m_serialNumber = item.getSerialNumber();
                m_lstItem[i]->m_fillState = true;
                os << "Filled " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
            else{
                os << "Unable to fill " << m_name << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
        }
        
    }
};
void CustomerOrder::display(std::ostream& os) const{
    os << m_name << " - " << m_product << '\n';
    for ( size_t i = 0 ; i < m_cntItem ; i++){
        os << "[" << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber << "] "
        << std::left << std::setfill(' ') << std::setw( (m_widthField) )<< m_lstItem[i]->m_itemName
        << " - " << (getOrderFillState() ? "FILLED":"MISSING") << std::endl ;
    }
} ;
