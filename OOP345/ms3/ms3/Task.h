//
//  Task.h
//  ms3
//
//  Created by Noston Liu on 2019/11/23.
//  Copyright © 2019 Noston. All rights reserved.
//

#ifndef Task_h
#define Task_h

#include <iostream>
#include <string>
#include <iomanip>
#include <deque>
#include "Utilities.h"
#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item{
    std::deque<CustomerOrder> m_orders;
    Task* m_pNextTask;
public:
    Task(const std::string&);
    Task(const Task&) = delete;
    Task(Task&& ) = delete;
    Task& operator=(const Task&) = delete;
    Task& operator=(Task&&) = delete;
    void runProcess(std::ostream&);
    bool moveTask();
    void setNextTask(Task&);
    bool getCompleted(CustomerOrder&);
    void validate(std::ostream&);
    Task& operator+=(CustomerOrder&&);
};


#endif /* Task_h */
