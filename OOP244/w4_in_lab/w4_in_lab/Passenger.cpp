/**************
 ///////////////////////////////////////////////////////////
 // Name        Date    Reason
 // Liu,Yu-Che  6/05    w4_in_lab
 ///////////////////////////////////////////////////////////
 **********************************************************/

#include <iostream>
#include <string.h>
#include "Passenger.h"

using namespace std;
using namespace sict;


Passenger::Passenger(){
    pName[0] = '\0';
    destination[0] = '\0';
};

Passenger::Passenger(const char* cname, const char* cdes){
    if( cname != nullptr && cname[0] != '\0'  && cdes != nullptr &&  cdes[0] != '\0'  ){
        strncpy(pName, cname, 18);
        strncpy(destination, cdes, 18);
    }
    else{
        pName[0] = '\0';
        destination[0] = '\0';
    }
};

bool Passenger::isEmpty() const{
    if( pName[0] == '\0' || destination[0] == '\0')
        return true;
    else
        return false;
};

void Passenger::display() const {
    if( !isEmpty() )
        cout <<  pName << " - " << destination << endl ;
    else
        cout << "No passenger!" << endl ;
    
    
};
