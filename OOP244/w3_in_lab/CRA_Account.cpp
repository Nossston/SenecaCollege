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
#include <iostream>
#include <cstring>

#include "CRA_Account.h"

using namespace std;
using namespace sict;

void CRA_Account::set(const char* familyName, const char* givenName, int sin){
    if (sin > min_sin && sin < max_sin ){
        strncpy(cfamilyName, familyName, max_name_length+1);
        strncpy(cgivenName, givenName, max_name_length+1);
        csin = sin;
    }
    else{
        strcpy(cfamilyName, "");
        strcpy(cgivenName, "");
    }
        
    };

    bool CRA_Account::isEmpty() const{
        if ( csin == 0  )
            return true;
        else if ( cfamilyName[0] == '\0' )
            return true;
        else if (cgivenName[0] == '\0')
            return true;
        else
            return false;
                
    };

    void CRA_Account::display() const{
        
        if (!isEmpty()) {
            cout << "Family Name: " << cfamilyName << endl;
            cout << "Given Name : " << cgivenName << endl;
            cout << "CRA Account: " << csin << endl;
        }
        else{
        cout << "Account object is empty!" << endl;
        }
    };


