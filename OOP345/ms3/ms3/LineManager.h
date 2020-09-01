//
//  LineManager.h
//  ms3
//
//  Created by Noston Liu on 2019/11/23.
//  Copyright © 2019 Noston. All rights reserved.
//

#ifndef LineManager_h
#define LineManager_h


#include <iostream>
#include <string>
#include <iomanip>
#include <deque>
#include <vector>
#include "Utilities.h"
#include "Task.h"
#include "Item.h"
#include "CustomerOrder.h"


class LineManager{
    std::vector<Task*> AssemblyLine;
    std::deque<CustomerOrder> ToBeFilled;
    // – A queue of customer orders to be filled
    std::deque<CustomerOrder> Completed;
    // – A queue of customer orders completed
    unsigned int m_cntCustomerOrder;
    //– The number of CustomerOrder objects the assembly line started with.
public:
    LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);
    bool run(std::ostream&);
    void displayCompleted(std::ostream&) const;
    void validateTasks() const ;
    
    
};

#endif /* LineManager_h */
