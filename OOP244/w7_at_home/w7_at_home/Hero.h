
///////////////////////////////////////////////////////////
// Name        Date    Reason
// Liu,Yu-Che  7/12    w7_at_home
///////////////////////////////////////////////////////////

#ifndef Hero_h
#define Hero_h
#include <iostream>

#define MAX_ROUNDS 100

namespace sict {
    class Hero{
        char name[41];
        int hp;
        int attack;
    public:
        Hero();
        Hero(const char* hname, int hhp, int hatk);
        void operator-=(int attack);
        bool isAlive() const;
        bool isEmpty() const;
        int attackStrength() const;
        friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
    };
    const Hero& operator*(const Hero& first, const Hero& second);
    
};

#endif /* Hero_h */
