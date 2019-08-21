/**************
 ///////////////////////////////////////////////////////////
 // Name        Date    Reason
 // Liu,Yu-Che  6/10    w4_at_home
 ///////////////////////////////////////////////////////////
 **********************************************************/

#include <iostream>
#include <string.h>
#include <iomanip>

#include "Passenger.h"

using namespace std;
using namespace sict;


Passenger::Passenger(){
    pName[0] = '\0';
    destination[0] = '\0';
    yr = 0;
    mt = 0;
    day = 0;
};

Passenger::Passenger(const char* cname, const char* cdes){
    if( cname != nullptr && cname[0] != '\0'  && cdes != nullptr &&  cdes[0] != '\0'  ){
        strncpy(pName, cname, 18);
        pName[18] = '\0';
        strncpy(destination, cdes, 18);
        destination[18] = '\0';
        yr = 2019;
        mt = 10;
        day = 1;
    }
    else{
        Passenger();
    }
};

Passenger::Passenger(const char* cname, const char* cdes, int pyear, int pmonth, int pday){
    if( cname != nullptr && cname[0] != '\0'
       && cdes != nullptr &&  cdes[0] != '\0'
       && pyear <= 2021 && pyear >= 2019
       && pmonth >= 1 && pmonth <= 12
       && pday <= 31 && pday >= 1){
        strncpy(pName, cname, 18);
        pName[18] = '\0';
        strncpy(destination, cdes, 18);
        destination[18] = '\0';
        yr = pyear;
        mt = pmonth;
        day = pday;
    }
    else{
        Passenger();
    }
};

bool Passenger::isEmpty() const{
    if( pName[0] == '\0' || destination[0] == '\0' || yr == 0 || mt ==0 || day == 0)
        return true;
    else
        return false;
};

void Passenger::display() const {

    if( !isEmpty() ){
        cout.fill('0') ;
        cout <<  pName << " - " << destination << " on " << yr <<"/" << setw(2) << mt << "/" << setw(2) << day << endl ;
    }
    else
        cout << "No passenger!" << endl ;
    
    
};
const char* Passenger::name() const{
        return pName;
};


bool Passenger::canTravelWith(const Passenger& p) const {
    if( p.day == day && p.mt == mt && p.yr == yr )
        return true;
    else
        return false;
};
