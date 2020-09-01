//
//  Task.c
//  ms3
//
//  Created by Noston Liu on 2019/11/23.
//  Copyright © 2019 Noston. All rights reserved.
//

#include "Task.h"

Task::Task(const std::string& src) : Item(src){
    m_pNextTask = nullptr ;
}

void Task::runProcess(std::ostream& os ){
    if ( !m_orders.empty() ) {
        if ( !m_orders.back().getOrderFillState() ) {
            m_orders.back().fillItem(*this, os);
           //m_orders.back().display(os);
        }
    }
};
bool Task::moveTask(){
    if (m_orders.empty()) {
       return false;
    }
    if ( m_pNextTask != nullptr && m_orders.back().getItemFillState(getName())){
        *m_pNextTask += std::move(m_orders.back());
        m_orders.pop_back();
    }
    return true;
};
void Task::setNextTask(Task& next){
    if (m_pNextTask != nullptr) {
        delete m_pNextTask;
    }
    m_pNextTask = &next;
};
bool Task::getCompleted(CustomerOrder& src){
    bool res = false;
    if(!m_orders.empty() && m_orders.back().getOrderFillState() ){
        src = std::move(m_orders.back());
        m_orders.pop_back();
        res = true;
    }
    return res;
};
void Task::validate(std::ostream& os){
    os << getName() << " --> " ;
    if (m_pNextTask != nullptr) {
        os << m_pNextTask->getName() ;
    }
    else{
        os << "END OF LINE";
    }
    os << std::endl;
};
Task& Task::operator+=(CustomerOrder&& src){
    m_orders.push_front( std::move(src) );
    return *this;
};
