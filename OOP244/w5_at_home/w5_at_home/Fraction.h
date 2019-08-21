/**************
 ///////////////////////////////////////////////////////////
 // Name        Date    Reason
 // Liu,Yu-Che  6/13    w5_at_home
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
        Fraction operator*(const Fraction& rhs) const;
        bool operator==(const Fraction& rhs) const;
        bool operator!=(const Fraction& rhs) const;
        Fraction& operator+=(const Fraction& rhs);
        ~Fraction();

    };
    
    
}
#endif /* Fraction_h */
