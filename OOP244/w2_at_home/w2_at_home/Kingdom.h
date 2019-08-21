/***********************************************************
 // OOP244 Workshop 2: Dynamic Memory
 // File Kingdom.cpp
 // Version 1.0
 // Date: 2019/05/06
 // Author: Cornel
 // Revision History
 ///////////////////////////////////////////////////////////
 // Name        Date    Reason
 // Liu,Yu-Che  5/23    w2_at_home
 ///////////////////////////////////////////////////////////
 ***********************************************************/

#ifndef Kingdom_h
#define Kingdom_h

namespace sict{
    struct Kingdom{
        char m_name[32];
        int m_population;
    };
    
    void display(const struct Kingdom& kd);
    
    void display(const struct Kingdom k[],int count);
    
}
#endif /* Kingdom_hpp */
