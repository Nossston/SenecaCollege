//
//  LineManager.c
//  ms3
//
//  Created by Noston Liu on 2019/11/23.
//  Copyright © 2019 Noston. All rights reserved.
//
#include <fstream>
#include "LineManager.h"

LineManager::LineManager(const std::string& filename, std::vector<Task*>& task, std::vector<CustomerOrder>& order){
    std::fstream file(filename);
    AssemblyLine = task;
    Utilities ult;
    std::string line,token,msg ;
    if (!file) {
        msg = "cannot open the file: " + filename ;
        throw msg;
    }
    for (size_t i = 0 ; i<order.size() ; i++) {
        ToBeFilled.push_front(std::move(order[i]) );
        m_cntCustomerOrder++;
    }
    
    while (std::getline(file,line) ) {
        bool more = true;
        size_t pos = 0;

        token = ult.extractToken(line, pos, more);
        for (auto i : task) {
            if (i->getName() == token) {
                if (pos != 0) {
                    token = ult.extractToken(line, pos, more);
                    for (size_t j = 0; j < task.size() ; j++) {
                        if (task[j]->getName() == token ) {
                            i->setNextTask(*AssemblyLine[j]);
                        }
                    }
                }
            }
        }
    }
    

};
bool LineManager::run(std::ostream& os){
    bool res = false;
    CustomerOrder order;
    if (!ToBeFilled.empty()) {
        *(AssemblyLine[4]) += std::move(ToBeFilled.back());
        ToBeFilled.pop_back();
    }
    //os<< "Size of Assem: [[" << AssemblyLine.size() <<"]]"<<'\n';

    for (auto i : AssemblyLine) {
        i->runProcess(os);
    }
    for (auto i : AssemblyLine) {
        if (i->moveTask()) {
            if (i->getCompleted(order)) {
                Completed.push_back(std::move (order));
            }
        }
    }
    
    if (Completed.size() == m_cntCustomerOrder && ToBeFilled.empty()) {
        res = true;
    }
    return res;
};

void LineManager::displayCompleted(std::ostream& os) const{
    for (size_t i = 0 ; i < Completed.size()  ; i++) {
        if (Completed[i].getOrderFillState()  && !Completed.empty() ) {
            Completed[i].display(os);
        }
    }
};

void LineManager::validateTasks() const{
    for (auto i : AssemblyLine) {
        i->validate(std::cout);
    }
} ;
