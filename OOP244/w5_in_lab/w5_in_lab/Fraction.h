/**************
 ///////////////////////////////////////////////////////////
 // Name        Date    Reason
 // Liu,Yu-Che  6/13    w5_in_lab
 ///////////////////////////////////////////////////////////
 **********************************************************/
#ifndef Fraction_h
#define Fraction_h


namespace sict {
    
class Fraction {
    int numerator;
    int denominator;     
    
    int max() const;
    int min() const;
    void reduce();
    int gcd() const;
 public:
    Fraction();
    Fraction(int numerator, int denominator);
    bool isEmpty() const;
    void display() const;
    Fraction operator+(const Fraction& rhs) const;
};

    
}
#endif /* Fraction_h */
