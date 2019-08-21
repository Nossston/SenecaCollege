
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/12    w7_at_home
///////////////////////////////////////////////////////////

#ifndef SuperHero_h
#define SuperHero_h
#include "Hero.h"

namespace sict {
 class SuperHero: public Hero{
    int bouns;
    int def;
public:
    SuperHero();
    SuperHero(const char* nm, int h, int a, int b, int d);
    int attackStrength() const;
    int defend() const;
    bool isEmpty() const;
 };
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second);

}
#endif /* SuperHero_h */
