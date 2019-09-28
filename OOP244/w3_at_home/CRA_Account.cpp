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
 // Liu,Yu-Che  5/28    w3_at_home
 ///////////////////////////////////////////////////////////
 **********************************************************/
#include <iostream>
#include <cstring>
#include <math.h>
#include <iomanip>


#include "CRA_Account.h"

using namespace std;
using namespace sict;

void CRA_Account::set(const char* familyName, const char* givenName, int sin){
    int evendigits[4], odddigits[4]; // 4 digits to sum up
    int sum = 0, nextHigh = 0, checkDigit = 0;
    
    checkDigit=sin % 10;
    evendigits[3]=(sin % 100)/10;
    odddigits[3]=(sin % 1000)      /100;
    evendigits[2]=(sin % 10000)    /1000;
    odddigits[2]=(sin % 100000)    /10000;
    evendigits[1]=(sin % 1000000)  /100000;
    odddigits[1]=(sin % 10000000)  /1000000;
    evendigits[0]=(sin % 100000000)/10000000;
    odddigits[0]=(sin % 1000000000)/100000000;
    
    // This looks hard-coding, but it is really simple to understand from the first line.
    // digits[3] == the 8th position of SIN, after that, we just add an extra zero after one line.
    
    
    for( int i =0; i < 4; i++){
        if( evendigits[i] >= 5){ // greater than 5 means we will have one to sum up.
            sum++;
        }
        evendigits[i] *= 2;
        evendigits[i] %= 10;
        sum+=evendigits[i];
        sum+=odddigits[i];
    }
    
    
    // if sum+checkdigit %10 != 0
    
    
    
    if( sum%10 != 0){ // if sum already is the mutiple of ten, then we can just go to the next step;
        // if not, add ten.
        nextHigh=( (sum/10)+1) *10;
    }
    else{
        nextHigh=sum;
    }
    
    if (sin > min_sin && sin < max_sin && (nextHigh-sum) == checkDigit ){
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
    
    if ( !isEmpty() ) {
        cout << "Family Name: " << cfamilyName << endl;
        cout << "Given Name : " << cgivenName << endl;
        cout << "CRA Account: " << csin << endl;
        
        cout << fixed << showpoint;
        cout << setprecision(2);
        for (int i = 0; i < max_yrs; i++) {
            if( cbalance[i]>2 )
                cout << "Year (" << creturnyrs[i] <<") balance owing: "<< cbalance[i] <<endl;
            else if( cbalance[i] < (-2) )
                cout << "Year (" << creturnyrs[i] <<") refund due: "<< fabs(cbalance[i]) <<endl;
            else
                cout << "Year (" << creturnyrs[i] <<") No balance owing or refund due!"<<endl;
        }
    }
    else{
        cout << "Account object is empty!" << endl;
    }
};

void CRA_Account:: set(int year, double balance){
    if( !isEmpty() && k < max_yrs ){
        creturnyrs[k] = year;
        cbalance[k] = balance;
        k++;
    }
};


