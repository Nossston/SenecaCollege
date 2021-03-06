/**********************************************************
 // Workshop 3: Classes and Privacy
 // w3_at_home.cpp
 // Version 3.0
 // 2019/05/19
 // Cornel
 // Description
 // This workshop demonstrates classes in C++ and
 // how member variables are defined privately, but
 // accessed through public member functions
 //
 // Revision History
 ///////////////////////////////////////////////////////////
 // Name        Date    Reason
 // Liu,Yu-Che  5/28    w3_in_lab
 ///////////////////////////////////////////////////////////
 **********************************************************/
#ifndef CRA_Account_h
#define CRA_Account_h

namespace sict {
    const int max_name_length = 40;
    const int min_sin =100000000;
    const int max_sin =999999999;
    const int max_yrs = 4;
    
    class CRA_Account{
        char cfamilyName[max_name_length + 1] = {'\0'} ;
        char cgivenName[max_name_length + 1] = {'\0'};
        int csin = 0;
        int creturnyrs[max_yrs] = {0}; // tax return years
        double cbalance[max_yrs] = {0.00};
        int cdate = 0;
        int k = 0;
    public:
        void set(const char* familyName, const char* givenName, int sin);
        bool isEmpty() const;
        void display() const;
        void set(int year, double balance);
};

};
#endif /* CRA_Account_h */
