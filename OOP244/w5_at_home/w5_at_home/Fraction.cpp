/**************
 ///////////////////////////////////////////////////////////
 // Name        Date    Reason
 // Liu,Yu-Che  6/13    w5_at_home
 ///////////////////////////////////////////////////////////
 **********************************************************/


#include <iostream>
#include "Fraction.h"
using namespace std;
using namespace sict;


Fraction::Fraction(){

    numerator=0;
    denominator=0;
};


Fraction::Fraction(int nu, int de){


    if (nu >= 0 && de >= 0 ) {
        numerator = nu;
        denominator = de;
        reduce();
    }
    else
        /* long way:
         numerator=0;
         denominator=0;
         */
        *this = Fraction();
};


int Fraction::max() const{
    return numerator > denominator ? numerator : denominator;
};
//ternary operator
int Fraction::min() const{
    return numerator < denominator ? numerator : denominator;
    /*
     My old long code:
     if(numerator>denominator)
     return denominator;
     else
     return numerator;
     */
};

int Fraction::gcd() const {
    int mn = min();
    int mx = max();
    int g_c_d = 1;
    bool found = false;
    
    for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
        if (mx % x == 0 && mn % x == 0) {
            found = true;
            g_c_d = x;
        }
    }
    return g_c_d;
}

void Fraction::reduce(){
    int gd = gcd();
    numerator /= gd;
    denominator /= gd;
};

bool Fraction::isEmpty() const{
    
    if (numerator == 0 && denominator == 0)
        return true;
    else
        return false;
};

void Fraction::display() const{
    
    if (!isEmpty() && denominator != 1 ) {
        cout << numerator << "/" <<denominator;
    }
    else if( denominator == 1 ){ // we already check the value of numerator is not empty and non-negative
        cout << numerator;
    }
    else
        cout << "no fraction stored";
};
Fraction Fraction::operator+(const Fraction& rhs) const{
    if( isEmpty() || rhs.isEmpty() ) {
        return Fraction();
    }
    else{
        Fraction result;
        result.numerator = ( numerator * rhs.denominator)+ ( rhs.numerator * denominator );
        result.denominator = ( denominator * rhs.denominator);
        result.reduce();
        return result;
    }
};


Fraction Fraction::operator*(const Fraction& rhs) const{
    if( isEmpty() || rhs.isEmpty() )
        return Fraction();
    else{
        Fraction result;
        result.numerator = numerator * rhs.numerator;
        result.reduce();
        return result;
    }
};

bool Fraction::operator==(const Fraction& rhs) const{
    if( isEmpty() || rhs.isEmpty() )
        return false;
    else if ( numerator == rhs.numerator && denominator == rhs.denominator )
        return true;
    else
        return false;
};
bool Fraction::operator!=(const Fraction& rhs) const{
    if( isEmpty() || rhs.isEmpty() )
        return false;
    else if ( numerator != rhs.numerator || denominator != rhs.denominator )
        return true;
    else
        return false;
};

Fraction& Fraction::operator+=(const Fraction& rhs) {

    if( isEmpty() || rhs.isEmpty() )
        return *this;
    else{
        Fraction temp;
        temp.numerator = ( numerator * rhs.denominator) + ( rhs.numerator * denominator );
        temp.denominator = ( denominator * rhs.denominator);
        *this = temp;
        return *this;
    }
    
};

Fraction::~Fraction(){
    //testing:
    // cout << "    !!!!In destructor!!! " << endl;
};
